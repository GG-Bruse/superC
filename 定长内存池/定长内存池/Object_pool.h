#pragma once
#include <iostream>
using std::cout;
using std::endl;

#ifdef WIN32
	#include <windows.h>
#else
	#include <sys/mman.h>
	#include <unistd.h>
#endif



inline static void* SystemAlloc(size_t kpage)
{
#ifdef _WIN32
	void* ptr = VirtualAlloc(0, kpage << 13, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#else
	// linux下brk mmap等
#endif
	if (ptr == nullptr) throw std::bad_alloc();
	return ptr;
}

template <class T>
class ObjectPool
{
public:
	T* New()
	{
		T * obj = nullptr;
		if (_freeList != nullptr)//优先使用分配过的内存
		{
			obj = (T*)_freeList;
			_freeList = *(void**)_freeList;//强转为void**后解引用为void*,即在32位系统下可以看到4个字节，64位系统下可以看到8个字节
		}
		else
		{
			size_t objSize = sizeof(T) > sizeof(void*) ? sizeof(T) : sizeof(void*);//确保至少能存储一个指针大小
			if (_remainBytes < objSize)//大块内存空间不足
			{
				_remainBytes = 128 * 1024;
				_memory = (char*)SystemAlloc(_remainBytes >> 13);
			}
			obj = (T*)_memory;
			_memory += objSize;
			_remainBytes -= objSize;
		}
		new(obj)T;//定位new 调用对象构造函数初始化
		return obj;
	}
	void Delete(T* obj)
	{
		obj->~T();//调用对象析构函数
		*(void**)obj = _freeList;//头插
		_freeList = obj;
	}

private:
	char* _memory = nullptr;//char*便于切割分配内存 指向大块内存
	void* _freeList = nullptr;//自由链表 管理归还的内存块
	size_t _remainBytes = 0;//记录剩余字节数
};
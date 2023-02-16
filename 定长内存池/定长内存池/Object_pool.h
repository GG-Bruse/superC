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
	// linux��brk mmap��
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
		if (_freeList != nullptr)//����ʹ�÷�������ڴ�
		{
			obj = (T*)_freeList;
			_freeList = *(void**)_freeList;//ǿתΪvoid**�������Ϊvoid*,����32λϵͳ�¿��Կ���4���ֽڣ�64λϵͳ�¿��Կ���8���ֽ�
		}
		else
		{
			size_t objSize = sizeof(T) > sizeof(void*) ? sizeof(T) : sizeof(void*);//ȷ�������ܴ洢һ��ָ���С
			if (_remainBytes < objSize)//����ڴ�ռ䲻��
			{
				_remainBytes = 128 * 1024;
				_memory = (char*)SystemAlloc(_remainBytes >> 13);
			}
			obj = (T*)_memory;
			_memory += objSize;
			_remainBytes -= objSize;
		}
		new(obj)T;//��λnew ���ö����캯����ʼ��
		return obj;
	}
	void Delete(T* obj)
	{
		obj->~T();//���ö�����������
		*(void**)obj = _freeList;//ͷ��
		_freeList = obj;
	}

private:
	char* _memory = nullptr;//char*�����и�����ڴ� ָ�����ڴ�
	void* _freeList = nullptr;//�������� ����黹���ڴ��
	size_t _remainBytes = 0;//��¼ʣ���ֽ���
};
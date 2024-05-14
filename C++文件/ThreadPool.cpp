#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <windows.h>
using namespace std;

typedef std::function<int(int, int)> fun_t;
class Task
{
public:
	Task() {}
	Task(int x, int y, fun_t func) :_x(x), _y(y), _func(func) {}
	void operator()() {
		cout << "处理完成: " << _x << " + " << _y << " = " << _func(_x, _y) << endl;
	}
public:
	int _x = 0;
	int _y = 0;
	fun_t _func;
};


const int threadNum = 4;
template<class T>
class ThreadPool
{
public:
	ThreadPool(int threadNum) :_number(threadNum) {}
	~ThreadPool()
	{
		for (auto& iter : _threads) {
			iter->join();
			delete iter;
		}
		_threads.clear();
	}
	ThreadPool(const ThreadPool<T>& others) = delete;
	ThreadPool<T>& operator= (const ThreadPool<T>& others) = delete;

public:
	mutex* getMutex() { return &_mutex; };
	bool isEmpty() { return _taskQueue.empty(); }
	void waitCond(unique_lock<mutex>& ulock) {
		_cond.wait(ulock);
	}
	static void* routine(ThreadPool<T>* args)
	{
		ThreadPool<T>* threadPool = args;
		while (true) 
		{
			T task;
			{
				unique_lock<mutex> ulock(*(threadPool->getMutex()));
				while (threadPool->isEmpty()) threadPool->waitCond(ulock);
				task = threadPool->getTask();
				task();
			}
		}
		return nullptr;
	}
	static ThreadPool<T>* getThreadPool(int number = threadNum)
	{
		if (nullptr == _pool_ptr)
		{
			unique_lock<mutex> ulock(_init_mutex);
			if (nullptr == _pool_ptr)
				_pool_ptr = new ThreadPool<T>(number);
		}
		return _pool_ptr;
	}

public:
	void start()
	{
		for (int i = 0; i < _number; ++i)
			_threads.push_back(new thread(routine, this));
	}
	T getTask()
	{
		if (!_taskQueue.empty()) {
			T task = _taskQueue.front();
			_taskQueue.pop();
			return task;
		}
		return Task(0, 0, [](int a, int b) { return 0; });
	}
	void pushTask(const T& task)
	{
		unique_lock<mutex> ulock(_mutex);
		_taskQueue.push(task);
		_cond.notify_one();
	}

private:
	vector<thread*> _threads;
	size_t _number;
	queue<T> _taskQueue;
private:
	mutex _mutex;
	condition_variable _cond;
private:
	static ThreadPool<T>* _pool_ptr;
	static mutex _init_mutex;
};
template<class T>
ThreadPool<T>* ThreadPool<T>::_pool_ptr = nullptr;
template<class T>
mutex ThreadPool<T>::_init_mutex;



int main()
{
	ThreadPool<Task>* threadPool = ThreadPool<Task>::getThreadPool(4);
	threadPool->start();
	while (true)
	{
		//生产任务
		int x = rand() % 100 + 1;
		Sleep(1000);
		int y = rand() % 30 + 1;
		Task task(x, y, [](int x, int y)->int { return x + y; });
		//推送至线程池
		threadPool->pushTask(task);
	}
	return 0;
}
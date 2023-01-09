//template <int inst>
//class __malloc_alloc_template
//{
//private:
//	static void* oom_malloc(size_t);
//public:
//	// 对malloc的封装
//	static void* allocate(size_t n)
//	{
//		// 申请空间成功，直接返回，失败交由oom_malloc处理
//		void* result = malloc(n);
//		if (0 == result)
//			result = oom_malloc(n);
//		return result;
//	}
//
//	static void deallocate(void* p, size_t /* n */)// 对free的封装
//	{
//		free(p);
//	}
//	// 模拟set_new_handle
//	// 该函数的参数为函数指针，返回值类型也为函数指针
//	// void (* set_malloc_handler( void (*f)() ) )()
//	static void (*set_malloc_handler(void (*f)()))()
//	{
//		void (*old)() = __malloc_alloc_oom_handler;
//		__malloc_alloc_oom_handler = f;
//		return(old);
//	}
//};
//template <int inst>
//void* __malloc_alloc_template<inst>::oom_malloc(size_t n)// malloc申请空间失败时代用该函数
//{
//	void (*my_malloc_handler)();
//	void* result;
//	for (;;)
//	{
//		// 检测用户是否设置空间不足应对措施，如果没有设置，抛异常，模式new的方式
//		my_malloc_handler = __malloc_alloc_oom_handler;
//		if (0 == my_malloc_handler)
//		{
//			__THROW_BAD_ALLOC;
//		}
//		// 如果设置，执行用户提供的空间不足应对措施
//		(*my_malloc_handler)();
//
//		result = malloc(n);// 继续申请空间，可能就会申请成功
//		if (result)
//			return(result);
//	}
//}
//typedef __malloc_alloc_template<0> malloc_alloc;



//union obj {
//    union obj* free_list_link;
//    char client_data[1];    /* The client sees this.        */
//};
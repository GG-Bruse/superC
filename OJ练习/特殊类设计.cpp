/*****************************************************不能被拷贝的类********************************************************/

//class Test1
//{
//public:
//	Test1() {};
//private:
//	Test1(const Test1&);
//	Test1 operator=(const Test1&);
//};

//class Test2
//{
//public:
//	Test2() {};
//	Test2(const Test2&) = delete;
//	Test2 operator=(const Test2&) = delete;
//};
















/*************************************************只能在堆区上创建对象的类***************************************************/
//class HeapOnly
//{
//public:
//	static HeapOnly* CreatObj() {
//		return new HeapOnly;
//	}
//private:
//	HeapOnly() {};
//	//防拷贝
//	HeapOnly(const HeapOnly&) = delete;/*防止类似这种情况 HeapOnly obj2(*obj); */
//};
//int main()
//{
//	HeapOnly* obj = HeapOnly::CreatObj();
//	return 0;
//}
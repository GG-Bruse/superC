/*****************************************************���ܱ���������********************************************************/

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
















/*************************************************ֻ���ڶ����ϴ����������***************************************************/
//class HeapOnly
//{
//public:
//	static HeapOnly* CreatObj() {
//		return new HeapOnly;
//	}
//private:
//	HeapOnly() {};
//	//������
//	HeapOnly(const HeapOnly&) = delete;/*��ֹ����������� HeapOnly obj2(*obj); */
//};
//int main()
//{
//	HeapOnly* obj = HeapOnly::CreatObj();
//	return 0;
//}
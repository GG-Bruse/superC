#include<iostream>
#include"vector.hpp"
#include"queue.hpp"
#include"stack.hpp"
using namespace bjy;
using std::cout;
using std::endl;
int main_vector()
{
	vector<int> v;
	for (int i = 0; i < 10; ++i) { v.push_back(i + 1); }
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	for (vector<int>::reverse_iterator rit = v.rbegin(); rit != v.rend(); ++rit) {
		cout << *rit << " ";
	}
	cout << endl;
	return 0;
}
int main_priority_queue()
{
	priority_queue<int> heap;
	heap.push(5);
	heap.push(3);
	heap.push(2);
	heap.push(0);
	heap.push(4);
	heap.push(1);
	while (!heap.empty()) {
		cout << heap.top() << " ";
		heap.pop();
	}
	cout << endl;

	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	priority_queue<int, vector<int>, greater<int>> heap2(arr, arr + sizeof(arr) / sizeof(arr[0]));
	while (!heap2.empty()) {
		cout << heap2.top() << " ";
		heap2.pop();
	}
	cout << endl;

	return 0;
}
int main_test()
{
	stack<int> sk;
	for (size_t i = 0; i < 10; ++i) { sk.push(i + 1); }
	while (!sk.empty()) {
		cout << sk.top() << " ";
		sk.pop();
	}
	cout << endl;

	queue<int> qe;
	for (size_t i = 0; i < 10; ++i) { qe.push(i+1); }
	while (!qe.empty()) {
		cout << qe.front() << " ";
		qe.pop();
	}
	cout << endl;

	return 0;
}
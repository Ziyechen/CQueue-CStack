#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <stdlib.h>
#include "CQueue.hpp"
#include "CStack.hpp"

//测试用例
void TestCQueue()
{
	CQueue<int> q;
	q.appendTail(1);
	q.appendTail(2);
	q.appendTail(3);
	q.appendTail(4);

	cout << q.deleteHead() << endl;
	cout << q.deleteHead() << endl;
	cout << q.deleteHead() << endl;
	cout << q.deleteHead() << endl;
	cout << q.deleteHead() << endl;
}

void TestCStack()
{
	CStack<int> s;

	s.appendTop(1);
	s.appendTop(2);
	s.appendTop(3);
	s.appendTop(4);

	cout << s.deleteTop() << endl;
	cout << s.deleteTop() << endl;
	cout << s.deleteTop() << endl;
	cout << s.deleteTop() << endl;
	cout << s.deleteTop() << endl;
}

int main()
{
	//TestCQueue();
	TestCStack();

	system("pause");
	return 0;
}

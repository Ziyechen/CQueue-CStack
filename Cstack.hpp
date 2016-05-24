#pragma once

//用两个队列实现一个栈，请实现它的两个函数appendTop和deleteTop，

#include <queue>
using namespace std;

template <class T>
class CStack
{
public:
	void appendTop(const T &node);
	T deleteTop();

private:
	queue<T> q1;
	queue<T> q2;
};

// 4 1 2 3
template <class T>
void CStack<T>::appendTop(const T &node)
{
	//如果q2队列不为空则往q2队列中插入元素
	if (q2.size() > 0)
	{
		q1.push(node);
	}
	//否则往q1队列中插入元素
	else
	{
		q2.push(node);
	}
}

template <class T>
T CStack<T>::deleteTop()
{
	//如果q1队列和q2队列均为空，则栈为空
	if (q1.empty() && q2.empty())
	{
		throw new exception("stack is empty.");
	}
	//如果q1队列为空
	if (q1.size() == 0)
	{
		while (q2.size() > 1)
		{
			T data = q2.front();
			q2.pop();

			q1.push(data);
		}
		T top = q2.front();
		q2.pop();

		return top;
	}
	else
	{
		while (q1.size() > 1)
		{
			T data = q1.front();
			q1.pop();

			q2.push(data);
		}
		T top = q1.front();
		q1.pop();

		return top;
	}
}

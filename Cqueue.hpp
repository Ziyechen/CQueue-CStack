#pragma once

//用两个栈实现一个队列，队列声明如下，请实现它的两个函数appendTail和deleteHead，
//分别在队尾插入结点和队头删除节点

#include <stack>
using namespace std;

template <class T>
class CQueue
{
public:
	CQueue()
	{}
	~CQueue()
	{}
	void appendTail(const T &node);
	T deleteHead();
private:
	stack<T> s1;
	stack<T> s2;
};

//插入操作在stack1中进行，删除操作在stack2中进行，如果stack2为空，则将stack1中的所有元素转移到stack2中
template <class T>
void CQueue<T>::appendTail(const T &node)
{
	//往s1栈中插入元素
	s1.push(node);
}

template <class T>
T CQueue<T>::deleteHead()
{
	if (s2.size() <= 0)
	{
		while (s1.size() > 0)
		{
			T &data = s1.top();
			s1.pop();

			s2.push(data);
		}
	}

	if (s2.size() == 0)
		throw new exception("queue is empty.");

	T head = s2.top();
	s2.pop();

	return head;
}

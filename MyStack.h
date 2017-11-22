#ifndef MYSTACK_H
#define MYSTACK_H

#include<vector>
#include<iostream>

using std::vector;

template<typename T>
class MyStack {
public:
	//构造函数
	MyStack();
	//元素个数
	bool IsEmpty()const;
	//进栈出栈
	void Push(const T &data);
	void Pop();
	T TopAndPop();
	//显示元素
	T Top()const;
	void Print()const;
private:
	int m_top;
	int capacity;
	vector<T> m_stack;
};

template<typename T>
MyStack<T>::MyStack() :m_top(-1), capacity(20) {}

template<typename T>
bool MyStack<T>::IsEmpty()const {
	return m_top == -1;
}

template<typename T>
void MyStack<T>::Push(const T &data) {
	if (m_top == m_stack.size() - 1) {
		m_stack.push_back(data);
		++m_top;
	}
	else {
		m_stack[++m_top] = data;
	}
}

template<typename T>
void MyStack<T>::Pop() {
	if (!IsEmpty()) {
		--m_top;
	}
}

template<typename T>
T MyStack<T>::TopAndPop() {
	if (!IsEmpty()) {
		return m_stack[m_top--];
	}
	else {
		return T();
	}
}

template<typename T>
void MyStack<T>::Print()const {
	if (!IsEmpty()) {
		for (int i = 0; i <= m_top; ++i) {
			std::cout << m_stack[i] << ' ';
		}
	}
	else {
		std::cout << "empty stack!!" << std::endl;
	}
}

template<typename T>
T MyStack<T>::Top()const {
	if (!IsEmpty()) {
		return m_stack[m_top];
	}
	else {
		return T();
	}
}


#endif
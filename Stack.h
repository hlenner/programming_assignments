#ifndef Stack_H
#define Stack_H
#include "llist.h"

template <typename T>
class Stack:private LList<T> {
	public:
	Stack();
	~Stack();
	int size() const;
	void push(const T& value);
	void pop();
	T& top();
	bool empty() const;
        void print();
        T& at(int loc) const;
        
       private:
        
};
template<typename T>
Stack<T>:: Stack() 
{
	LList<T>();
}
template<typename T>
Stack<T>:: ~Stack() 
{

}
template<typename T>
void Stack<T>:: push(const T &val)
{
	LList<T>::push_back(val);
}
template<typename T>
int Stack<T>:: size() const
{
	return LList<T>::size();
}
template<typename T>
void Stack<T>:: pop()
{
	LList<T>::pop_back();
}
template<typename T>
T& Stack<T>:: top() 
{
	return LList<T>:: peek_front();
}

template<typename T>
bool Stack<T>:: empty() const
{
	return LList<T>::empty();
}
template<typename T>
T& Stack<T>:: at(int loc) const
{
	return LList<T>:: at(loc);
}

#endif


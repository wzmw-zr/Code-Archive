/*************************************************************************
	> File Name: 3.stack_template.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月10日 星期一 09时52分11秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

template<typename ValueType>
class stack {
public :
    stack();
    virtual ~stack();
    void push(ValueType val);
    bool empty();
    void pop();
    ValueType top();

private :
    int __top;
    int buffer_size;
    ValueType *buffer;
};

template<typename ValueType>
stack<ValueType>::stack() 
: __top(-1)
, buffer_size(10)
, buffer(new ValueType[10]) {}

template<typename ValueType>
stack<ValueType>::~stack() {
    delete[] buffer;
}

template<typename ValueType>
bool stack<ValueType>::empty() {
    return this->__top == -1;
}

template<typename ValueType>
void stack<ValueType>::push(ValueType val) {
    if (this->__top == this->buffer_size - 1) {
        this->buffer_size *= 2;
        ValueType *temp = new ValueType[this->buffer_size];
        memcpy(temp, this->buffer, sizeof(ValueType) * (this->__top + 1));
        delete[] this->buffer;
        this->buffer = temp;
    }
    this->buffer[++(this->__top)] = val;
}

template<typename ValueType>
void stack<ValueType>::pop() {
    if (empty()) return ;
    this->__top--;
}

template<typename ValueType>
ValueType stack<ValueType>::top() {
    return this->buffer[this->__top];
}

int main() {
    stack<int> st;
    for (int i = 20; i >= 0; i--) st.push(i);
    for (int i = 0; i < 10; i++) {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}

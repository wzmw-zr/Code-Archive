/*************************************************************************
	> File Name: 4.heap.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月10日 星期一 10时19分18秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

template<typename ValueType>
class priority_queue {
public :
    priority_queue();
    ~priority_queue();
    void push(ValueType val);
    bool empty();
    ValueType top();
    void pop();
    void show();

private :
    int buffer_size;
    int cnt;
    ValueType *buffer;
};

template<typename ValueType>
priority_queue<ValueType>::priority_queue() 
: buffer_size(10)
, cnt(0)
, buffer(new ValueType[this->buffer_size + 1]) {}

template<typename ValueType>
priority_queue<ValueType>::~priority_queue() {
    delete[] this->buffer;
}

template<typename ValueType>
void swap(ValueType *a, ValueType *b) {
    ValueType c = *a;
    *a = *b;
    *b = c;
}

template<typename ValueType>
void priority_queue<ValueType>::push(ValueType val) {
    if (this->cnt == this->buffer_size) {
        this->buffer_size *= 2;
        ValueType *temp = new ValueType[this->buffer_size + 1];
        memcpy(temp, this->buffer, sizeof(ValueType) * (this->cnt + 1));
        delete[] this->buffer;
        this->buffer = temp;
    }
    this->buffer[++this->cnt] = val;
    int ind = this->cnt;
    while (ind > 1 && this->buffer[ind >> 1] < this->buffer[ind]) {
        swap(&(this->buffer[ind >> 1]), &(this->buffer[ind]));
        ind >>= 1;
    }
}

template<typename ValueType>
bool priority_queue<ValueType>::empty() {
    return this->cnt == 0;
}

template<typename ValueType>
ValueType priority_queue<ValueType>::top() {
    return this->buffer[1];
}

template<typename ValueType>
void priority_queue<ValueType>::pop() {
    if (empty()) return ;
    this->buffer[1] = this->buffer[this->cnt--];
    int ind = 1;
    while ((ind * 2) <= this->cnt) {
        if ((ind * 2 + 1) <= this->cnt) {
            cout << this->buffer[ind * 2 + 1] << ", " << this->buffer[ind * 2 + 1] << endl;
            if (this->buffer[ind * 2] < this->buffer[ind * 2 + 1]) {
                if (this->buffer[ind] >= this->buffer[ind * 2 + 1]) return ;
                swap(&(this->buffer[ind]), &(this->buffer[ind * 2 + 1]));
                ind = ind * 2 + 1;
            } else {
                if (this->buffer[ind] >= this->buffer[ind * 2]) return ;
                swap(&(this->buffer[ind]), &(this->buffer[ind * 2]));
                ind *= 2;
            }
        } else {
            if (this->buffer[ind] >= this->buffer[ind * 2]) return ;
            swap(&(this->buffer[ind]), &(this->buffer[ind * 2]));
            ind *= 2; 
        }
    }
}

template<typename ValueType>
void priority_queue<ValueType>::show() {
    for (int i = 1; i <= this->cnt; i++) cout << this->buffer[i] << " ";
    cout << endl;
}

int main() {
    priority_queue<int> que;
    for (int i = 0; i < 20; i++) {
        que.push(i);
        que.show();
    }
    for (int i = 0; i < 10; i++) {
        que.pop();   
        que.show();
    }
    return 0;
}

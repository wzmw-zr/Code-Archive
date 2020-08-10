/*************************************************************************
	> File Name: 2.queue_template.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月10日 星期一 08时30分30秒
 ************************************************************************/

#include<iostream>
using namespace std;

template<typename ValueType>
class queue {
public :
    queue();
    virtual ~queue();

    int size();
    bool empty();
    void push(ValueType val);
    ValueType front();
    void pop();
    void show();

private :
    int buffer_size;
    int head;
    int tail;
    int cnt;
    ValueType *buffer;
};

template<typename ValueType>
queue<ValueType>::queue()
: buffer_size(3)
, head(0)
, tail(-1)
, cnt(0)
, buffer(new ValueType[3]) {}

template<typename ValueType>
queue<ValueType>::~queue() {
    delete[] this->buffer;
}

template<typename ValueType>
void queue<ValueType>::push(ValueType val) {
    if (this->cnt == this->buffer_size) {
        //cout << this->cnt << endl;
        this->buffer_size *= 2;
        ValueType *temp = new ValueType[this->buffer_size];
        int ind = 0;
        for (int i = this->head, number = this->cnt; number != 0; i = (i + 1) % this->cnt, number--) {
            temp[ind++] = this->buffer[i];
        }
        this->head = 0;
        this->tail = this->cnt - 1;
        delete[] this->buffer;
        this->buffer = temp;
    }
    this->buffer[(++this->tail) % this->buffer_size] = val;
    this->cnt++;
}

template<typename ValueType>
int queue<ValueType>::size() {
    return this->cnt;
}

template<typename ValueType>
bool queue<ValueType>::empty() {
    return this->cnt == 0;
}

template<typename ValueType>
ValueType queue<ValueType>::front() {
    return this->buffer[this->head];
}

template<typename ValueType>
void queue<ValueType>::pop() {
    if (empty()) return ;
    this->head = (this->head + 1) % this->buffer_size;
    this->cnt--;
}

template<typename ValueType>
void queue<ValueType>::show() {
    if (empty()) {
        cout << endl;
        return ;
    }
    for (int i = this->head, number = this->cnt; number != 0; i = (i + 1) % this->buffer_size, number--) {
        cout << this->buffer[i] << " ";
    }
    cout << endl;
}


int main() {
    queue<int> que;
    for (int i = 0; i < 10; i++) que.push(i);
    que.show();
    for (int i = 0; i < 12; i++) {
        que.pop();
        que.show();
    }
    return 0;
}

/*************************************************************************
	> File Name: 2.case.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月28日 星期二 09时48分59秒
 ************************************************************************/

#include<iostream>
using namespace std;

template <typename Type> class Node {
public:
    Type data;
    Node<Type> *next;
    Node(const Type &_data) {
        data = _data;
        next = NULL;
    }
};

int main() {
    Node<int> node(12);
    cout << node.data << endl;
    cout << node.next << endl;
    return 0;
}

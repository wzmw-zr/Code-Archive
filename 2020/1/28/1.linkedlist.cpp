/*************************************************************************
	> File Name: 1.linkedlist.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月28日 星期二 08时56分36秒
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

template <typename Type> class LinkedList {
private:
    Node<Type> *head;
public:
    LinkedList() {
        head = NULL;
    }
    ~LinkedList() {
        Node<Type> *current_node = head;
        while (current_node != NULL) {
            Node<Type> *delete_node = current_node;
            current_node = current_node->next;
            delete delete_node;
        }
    }
    bool insert(Node<Type> *node, int index) {
        if (head == NULL) {
            if (index != 0) {
                return false;
            }
            head = node;
            return true;
        }
        if (index == 0) {
            node->next = head;
            head = node;
            return true;
        }
        Node<Type> *current_node = head;
        int count = 0;
        while (current_node->next != NULL && count < index - 1) {
            current_node = current_node->next;
            count++;
        }
        if (count == index - 1) {
            node->next = current_node->next;
            current_node->next = node;
            return true;
        }
        return false;
    }

    void output() {
        if (head == NULL) {
            return;
        }
        Node<Type> *current_node = head;
        while (current_node != NULL) {
            cout << current_node->data << " ";
            current_node = current_node->next;
        }
        cout << endl;
    }

    int delete_node(int index) {
        Node<Type> *current_node = head;
        int count = 0;
        if (index == 0) {
            Node<Type> *del_node = head;
            head = head->next;
            free(del_node);
            return 1;
        }
        while (current_node->next && count < index - 1) {
            current_node = current_node->next;
            count++;
        }
        if (current_node->next && count == index - 1) {
            Node<Type> *del_node = current_node->next;
            current_node->next = del_node->next;
            free(del_node);
            return 1;
        }
        return 0;
    }
    void reverse() {
        Node<Type> *current_node = head->next;
        head->next = NULL;
        while (current_node) {
            Node<Type> *next_node = current_node->next;
            current_node->next = head;
            head = current_node;
            current_node = next_node;
        }
    }
};
int main() {
    LinkedList<int> linkedlist;
    int m;
    cin >> m;
    int t;
    for (int i = 1; i <= m; i++) {
        cin >> t;
        switch (t) {
            case 1 : {
                int a, b;
                cin >> a >> b;
                Node<int> *node = (Node<int> *) malloc(sizeof(Node<int>));
                node->data = b;
                node->next = NULL;
                if (linkedlist.insert(node, a)) cout << "success" << endl;
                else cout << "failed" << endl;
                break;
            }

            case 2 : {
                linkedlist.output();
                break;
            }

            case 3 : {
                int a;
                cin >> a;
                if (linkedlist.delete_node(a)) cout << "success" << endl;
                else cout << "failed" << endl;
                break;
            }

            case 4 : {
                linkedlist.reverse();
                break;
            }
        }
    }
    return 0;
}

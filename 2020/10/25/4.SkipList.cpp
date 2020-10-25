/*************************************************************************
	> File Name: 4.SkipList.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月25日 星期日 09时55分57秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

struct SkipListNode {
    int __value;
    int __level;
    SkipListNode **forward;

    SkipListNode() : 
    __value(0), 
    __level(1), 
    forward(nullptr) {}

    SkipListNode(int value, int level) :
    __value(value),
    __level(level),
    forward(new SkipListNode *[level]) {
        for (int i = 0; i < level; i++) forward[i] = nullptr;
    }

    ~SkipListNode() {
        if (forward) delete[] forward;
    }
};

struct SkipList {
    int MAX_LEVEL = 32;
    int P = 4;
    int S = 0xffff;
    int PS = S / P;

    SkipListNode *header, *tail;
    int __length;
    int __level;

    SkipList() : 
    header(new SkipListNode(0, MAX_LEVEL)),
    tail(nullptr),
    __length(0),
    __level(1) {
        srand(time(0));
    }

    int randomLevel() {
        int level = 1;
        while ((rand() & S) < PS) level++;
        return min(level, MAX_LEVEL);
    }

    SkipListNode *insert_node(int value) {
        SkipListNode *update[MAX_LEVEL], *x;
        x = this->header;
        for (int i = this->__level - 1; i >= 0; i--) {
            while (x->forward[i] && x->forward[i]->__value < value) 
                x = x->forward[i];
            //if (x == this->header) cout << i << " : header" << endl;
            //else cout << i << " : " << x->__value << endl;
            update[i] = x;
        }

        int level = randomLevel();
        cout << "level = " << level << endl;
        if (this->__level < level) {
            for (int i = this->__level; i < level; i++) 
                update[i] = this->header;
            this->__level = level;
        }

        x = new SkipListNode(value, level);
        for (int i = 0; i < level; i++) {
            x->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = x;
        }

        this->__length++;
        cout << "length = " << this->__length << endl;

        return x;
    }

    SkipListNode *find(int value) {
        SkipListNode *x = this->header;
        for (int i = this->__level - 1; i >= 0; i--) {
            while (x->forward[i] && x->forward[i]->__value < value) 
                x = x->forward[i];
            if (x->forward[i] && x->forward[i]->__value == value) 
                return x->forward[i];
        }
        return nullptr;
    }

    void delete_node(int value) {
        SkipListNode *update[MAX_LEVEL], *x;
        x = this->header;
        for (int i = this->__level - 1; i >= 0; i--) {
            while (x->forward[i] && x->forward[i]->__value < value) 
                x = x->forward[i];
            update[i] = x;
        }
        x = x->forward[0];
        if (x && x->__value == value) {
            for (int i = 0; i < this->__level; i++) {
                if (update[i]->forward[i] == x) 
                    update[i]->forward[i] = x->forward[i];
            }

            while (this->__level > 1 && this->header->forward[this->__level - 1] == nullptr) this->__level--;
            this->__length--;
            delete x;
        }
    }

    void show() {
        SkipListNode *temp = this->header;
        while (temp->forward[0]) {
            cout << temp->forward[0]->__value << ", ";
            temp = temp->forward[0];
        }
        cout << endl;
    }
};

int main() {
    SkipList sl;
    int op, n;
    while (cin >> op >> n) {
        if (op == 0) 
            sl.insert_node(n);
        else if (op == 1) 
            cout << (sl.find(n) ? "find " : "not find ") << n << endl;
        else 
            sl.delete_node(n);
        sl.show();
    }
    return 0;
}

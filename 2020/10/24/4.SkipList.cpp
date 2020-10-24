/*************************************************************************
	> File Name: 4.SkipList.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月24日 星期六 21时33分18秒
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
    SkipListNode *backward;
    SkipListNode **forward;

    SkipListNode() :
    __value(0),
    __level(0),
    backward(nullptr),
    forward(nullptr) {}

    SkipListNode(int value, int level) : 
    __value(value), 
    __level(level),
    backward(nullptr),
    forward(new SkipListNode *[level + 1]) {
        for (int i = 0; i <= level; i++) forward[i] = nullptr;
    }

    ~SkipListNode() {
        if (forward) delete[] forward;
    }
};

struct SkipList {   
    static const int MAX_LEVEL = 32;
    static const int P = 4;
    static const int S = 0xffff;
    static const int PS = S / P;
    static const int INVALID = INT32_MAX;

    SkipListNode *header, *tail;
    int __length;
    int __level;

    SkipList() : 
    __length(0),
    __level(1),
    header(new SkipListNode(0, MAX_LEVEL)),
    tail(nullptr) {
        srand(time(0));
        //for (int i = 0; i < MAX_LEVEL; i++) header->forward[i] = tail;
    }

    int randomLevel() {
        int level = 1;
        while ((rand() & S) < PS) level++;
        return min(level, MAX_LEVEL);
    }

    SkipListNode *insert_node(int value) {
        SkipListNode *update[MAX_LEVEL], *x;
        int level;
        x = this->header;
        for (int i = this->__level - 1; i >= 0; i--) {
            while (x->forward[i] && x->forward[i]->__value < value) 
                x = x->forward[i];
            update[i] = x;
        }

        level = randomLevel();
        if (level > this->__level) {
            for (int i = this->__level; i < level; i++) {
                update[i] = this->header;
            }
            this->__level = level;
        }

        x = new SkipListNode(value, level);
        for (int i = 0; i < level; i++) {
            x->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = x;
        }

        x->backward = (update[0] == this->header ? nullptr : update[0]);
        if (x->forward[0]) x->forward[0]->backward = x;
        else this->tail = x;
        this->__length++;
        return x;
    } 
    
    SkipListNode *find(int value) {
        SkipListNode *x = this->header;
        for (int i = this->__level - 1; i >= 0; i--) {
            while (x->forward[i] && x->forward[i]->__value < value) 
                x = x->forward[i];
            if (x->__value == value) return x;
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
            if (x->forward[0])
                x->forward[0]->backward = x->backward;
            while (this->__level > 1 && this->header->forward[this->__level - 1] == nullptr) this->__level--;
            this->__length--;
            delete x;
        }
    }
};

int main() {
    return 0;
}

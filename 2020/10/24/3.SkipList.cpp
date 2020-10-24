/*************************************************************************
	> File Name: 3.SkipList.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月24日 星期六 10时02分58秒
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
    int value;
    int level;
    SkipListNode *backward;
    SkipListNode **forward;

    SkipListNode() = default;
    SkipListNode(int value, int level) : value(value), level(level), backward(nullptr), forward(new SkipListNode *[level + 1]) {}

    ~SkipListNode() {
        if (forward) delete[] forward;
    }
};

struct SkipList {
    static const int MAX_L = 32;
    static const int P = 4;
    static const int S = 0xffff;
    static const int PS = S / P;
    static const int INVAILD = INT32_MAX;

    SkipListNode *header, *tail;
    int length;
    int level;

    SkipList() : length(0), level(1), header(new SkipListNode(0, MAX_L)), tail(nullptr) {
        srand(time(0));
    }

    int randomLevel() {
        int lv = 1;
        while ((rand() & S) < PS) lv++;
        return min(lv, MAX_L);
    }

    SkipListNode *insert(int value) {
        SkipListNode *update[MAX_L], *x;
        int i, lv;
        x = header;
        for (int i = this->level - 1; i >= 0; i--) {
            while (x->forward[i] && x->forward[i]->value < value) x = x->forward[i];
            update[i] = x;
        }

        lv = randomLevel();
        if (lv > this->level) {
            for (int i = this->level; i < lv; i++) update[i] = header;
            this->level = lv;
        }

        x = SkipListNode(value, lv);
        for (int i = 0; i < level; i++) {
            x->forward[i] = update[i]->forward[i];
            update[i]->forward = x;
        }

        x->backward = (update[0] == this->header ? nullptr : update[0]);
        if (x->forward[0]) x->forward[0]->backward = x;
        else this->tail = x;
        this->length++;
        return x;
    }
};

int main() {
    return 0;
}

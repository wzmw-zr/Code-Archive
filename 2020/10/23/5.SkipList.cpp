/*************************************************************************
	> File Name: 5.SkipList.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月23日 星期五 20时43分15秒
 ************************************************************************/

#include<iostream>
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
    int level, key;
    SkipListNode **forward;

    SkipListNode() = default;

    SkipListNode(int k, int l, SkipListNode *next = NULL) {
        key = k;
        level = l;
        forward = new SkipListNode *[l + 1];
        for (int i = 0; i <= l; i++) forward[i] = next;
    }

    ~SkipListNode() {
        if (forward) delete[] forward;
    }
};

struct SkipList {
    static const int MAXL = 32;
    static const int P = 4;
    static const int S = 0xFFFF;
    static const int PS = S / P;
    static const int INVALID = INT_MAX;

    SkipListNode *head, *tail;
    int length;
    int level;

    SkipList() {
        srand(time(0));
        level = length = 0;
        tail = new SkipListNode(INVALID, 0);
        head = new SkipListNode(INVALID, MAXL, tail);
    }

    int randomLevel() {
        int lv = 1;
        while ((rand() & S) < PS) ++lv;
        return min(MAXL, lv);
    }

    bool find(const int &key) {
        SkipListNode *p = head;
        for (int i = level; i >= 0; i--) {
            while (p->forward[i]->key < key) p = p->forward[i];
        }
        p = p->forward[0];
        if (p->key == key) return true;
        return false;
    }

    
};

int main() {
    return 0;
}

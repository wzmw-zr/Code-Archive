/*************************************************************************
	> File Name: 1.LeetCode2032.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月21日 星期三 09时59分32秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() = default;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *pa = headA, *pb = headB;
    while (pa != pb) {
        pa = pa ? pa->next : headB;
        pb = pb ? pb->next : headA;
    }
    return pa;
}

int main() {
    return 0;
}

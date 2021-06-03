/*************************************************************************
	> File Name: 1.LeetCode160.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月04日 星期五 00时02分48秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() = default;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode *> st;
    while (headA) {
        st.insert(headA);
        headA = headA->next;
    }
    while (headB) {
        if (st.count(headB)) return headB;
        headB = headB->next;
    }
    return nullptr;
}

int main() {
    return 0;
}

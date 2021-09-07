/*************************************************************************
	> File Name: 3.LeetCode817.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月07日 星期二 22时49分48秒
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

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

int numComponents(ListNode* head, vector<int>& nums) {
    unordered_set<int> st;
    for (int x : nums) st.insert(x);
    int ans = 0;
    ListNode *p = head;
    while (p) {
        if (st.count(p->val)) {
            while (p && st.count(p->val)) p = p->next; 
            ans++;
        } else p = p->next;
    }
    return ans;
}

int main() {
    return 0;
}

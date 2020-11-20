/*************************************************************************
	> File Name: 1.LeetCode148.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月21日 星期六 00时05分44秒
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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* sortList(ListNode* head) {
    vector<ListNode *> ans;
    while (head) {
        ans.push_back(head);
        head = head->next;
    }
    sort(ans.begin(), ans.end(), [](ListNode *a, ListNode *b){ return a->val < b->val; });
    return ans[0];
}

int main() {
    return 0;
}

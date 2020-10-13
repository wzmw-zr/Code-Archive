/*************************************************************************
	> File Name: 1.LeetCode24.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月13日 星期二 15时16分39秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *ans = nullptr;
    int flag = 1;
    while (head && head->next) {
        ListNode *temp = head->next;
        head->next = temp->next;
        temp->next = head;
        if (flag) {
            ans = temp;
            flag = 0;
        }
        head = head->next;
    }
    return ans;
}

int main() {
    return 0;
}

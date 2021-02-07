/*************************************************************************
	> File Name: 4.LeetCode382.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月07日 星期日 23时11分35秒
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
    ListNode(int val) : val(val), next(nullptr) {} 
};

class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode *head;

    Solution(ListNode* head) : head(head) {
        srand(time(0));
    }

    /** Returns a random node's value. */
    int getRandom() {
        int cnt, num;
        cnt = 1;
        num = 0;
        ListNode *temp = head;
        if (temp) num = temp->val;
        while (temp) {
            if (cnt == 1) num = temp->val;
            else {
                if (rand() % cnt == 0) num = temp->val;
            }
            cnt++;
            temp = temp->next;
        }
        return num;
    }
};

int main() {
    return 0;
}

/*************************************************************************
	> File Name: 3.LeetCode382.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月06日 星期六 15时57分49秒
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
#include<ctime>
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
    vector<int> nums;

    Solution(ListNode* head) {
        srand(time(0));
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
    }

    /** Returns a random node's value. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

int main() {
    return 0;
}

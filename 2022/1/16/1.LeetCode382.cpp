/*************************************************************************
	> File Name: 1.LeetCode382.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月16日 星期日 00时01分50秒
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
#include <ctime>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

struct ListNode {
    int val;   
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    vector<int> nums;
    Solution(ListNode* head) {
        srand(time(0));
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
    }

    int getRandom() {
        int ind = rand() % static_cast<int>(nums.size());
        return nums[ind];
    }
};

int main() {
    return 0;
}

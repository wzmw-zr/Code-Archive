/*************************************************************************
	> File Name: 1.LeetCode1784.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月28日 星期六 08时15分37秒
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

bool isPalindrome(ListNode* head) {
    vector<int> nums;
    while (head) {
        nums.push_back(head->val);
        head = head->next;
    }
    int i = 0, j = nums.size() - 1;
    while (i < j) {
        if (nums[i] - nums[j]) return false;
        i++, j--;
    }
    return true;
}

int main() {
    return 0;
}

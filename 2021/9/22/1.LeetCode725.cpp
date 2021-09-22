/*************************************************************************
	> File Name: 1.LeetCode725.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月22日 星期三 12时13分15秒
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
    ListNode(int val) : val(val), next(nullptr) {}
};

vector<ListNode*> splitListToParts(ListNode* root, int k) {
    int l = 0;
    ListNode *temp = root;
    vector<ListNode *> ans;
    while (temp) temp = temp->next, l++;
    int x = l / k, y = l % k;
    temp = root;
    for (int i = 0; i < k; i++) {
        ans.push_back(temp);
        for (int j = 0; j < x - 1; j++) temp = temp->next;
        if (y) {
            if (x) temp = temp->next;
            y--;
        }
        if (temp) {
            ListNode *t = temp->next;
            temp->next = nullptr;
            temp = t;
        }
    }
    return ans;
}

int main() {
    return 0;
}

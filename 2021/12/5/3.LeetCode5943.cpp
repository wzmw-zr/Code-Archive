/*************************************************************************
	> File Name: 3.LeetCode5943.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月05日 星期日 10时44分09秒
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
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

ListNode* deleteMiddle(ListNode* head) {
    int l = 0;
    ListNode *temp = head;
    while (temp) temp = temp->next, l++;
    int mid = l / 2;
    ListNode *h = new ListNode(0, head);
    temp = h;
    while (mid) temp = temp->next, mid--;
    ListNode *t = temp->next;
    temp->next = t->next;
    delete t;
    temp = h->next;
    delete h;
    return temp;
}

int main() {
    return 0;
}

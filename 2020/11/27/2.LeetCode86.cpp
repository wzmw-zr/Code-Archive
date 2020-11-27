/*************************************************************************
	> File Name: 2.LeetCode86.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月27日 星期五 08时06分06秒
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

ListNode* partition(ListNode* head, int x) {
    ListNode *lt = new ListNode(), *ge = new ListNode();
    ListNode *temp_1 = lt, *temp_2 = ge;
    while (head) {
        if (head->val < x) {
            temp_1->next = head;
            temp_1 = temp_1->next;
        } else {
            temp_2->next = head;
            temp_2 = temp_2->next;
        }
        head = head->next;
    }
    temp_2->next = nullptr;
    temp_1->next = ge->next;
    ListNode *ans = lt->next;
    delete lt, ge;
    return ans;
}

int main() {
    return 0;
}

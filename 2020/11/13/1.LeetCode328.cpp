/*************************************************************************
	> File Name: 1.LeetCode328.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月13日 星期五 00时06分29秒
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
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* oddEvenList(ListNode* head) {
    if (!head) return nullptr;
    if (!head->next) return head;
    ListNode *odd = head, *even = head->next, *even_head = head->next, *temp = head->next->next;
    int cnt = 3;
    while (temp) {
        if (cnt & 1) {
            odd->next = temp;   
            odd = odd->next;
        }
        else {
            even->next = temp;
            even = even->next;
        }
        cnt++;
        temp = temp->next;
    }
    odd->next = even_head;
    even->next = nullptr;
    return head;
}

int main() {
    return 0;
}

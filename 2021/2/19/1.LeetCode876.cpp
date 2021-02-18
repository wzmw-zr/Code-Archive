/*************************************************************************
	> File Name: 1.LeetCode876.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月19日 星期五 01时19分25秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* middleNode(ListNode* head) {
    int cnt = 0;
    ListNode *temp = head;
    while (temp) cnt++, temp = temp->next;
    temp = head;
    cnt = cnt / 2;
    while (cnt--)  temp = temp->next;
    return temp;
}

int main() {
    return 0;
}

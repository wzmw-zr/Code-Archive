/*************************************************************************
	> File Name: 3.LeetCode445.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月14日 星期二 23时10分28秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

int ListLen(ListNode *list) {
    int len = 0;
    ListNode *head = list;
    while (head && head->next) {
        head = head->next;
        len++;
    }
    if (head) len++;
    return len;
}

int cmp(ListNode *l1, ListNode *l2) {
    int len1 = ListLen(l1), len2 = ListLen(l2);
    int ret = 0;
    if (len1 == len2) {
        ListNode *head1 = l1, *head2 = l2;
        for (int i = 0; i < len1; i++) {
            if (head1->val == head2->val) {
                head1 = head1->next;
                head2 = head2->next;
                continue;
            }
            return head1->val > head2->val;
        }
        return ret;
    }
    return len1 > len2;
}

ListNode *NewNode(int val) {
    ListNode *node = (ListNode *) calloc(sizeof(ListNode), 1);
    node->val = val;
    return node;
}

ListNode *Insert(ListNode *head, int val) {
    if (!head) return NewNode(val);
    ListNode *tmp = NewNode(val);
    tmp->next = head;
    head = tmp;
    return head;
}


ListNode *AddNumber(ListNode *l1, ListNode *l2) {
    ListNode *head1 = l1, *head2 = l2, *ret = NULL;
    int len1 = ListLen(l1), len2 = ListLen(l2);
    int num1[len1] , num2[len2], res[len1 + 1];
    memset(res, 0, sizeof(int) * (len1 + 1));
    memset(num1, 0, sizeof(int) * len1);
    memset(num2, 0, sizeof(int) * len2);
    for (int i = 0; i < len1; i++) {
        num1[len1 - i - 1] = head1->val; 
        head1 = head1->next;
    }
    for (int i = 0; i < len2; i++) {
        num2[len2 - i - 1] = head2->val; 
        head2 = head2->next;
    }
    for (int i = 0; i < len1; i++) {
        if (i >= len2) res[i] += num1[i];
        else res[i] += num1[i] + num2[i];
        if (res[i] >= 10) {
            res[i] %= 10;
            res[i + 1] += 1;
        }
    }
    for (int i = 0; i < len1; i++) {
        ret = Insert(ret, res[i]);
    }
    if (res[len1]) ret = Insert(ret, res[len1]);
    return ret;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    ListNode *ret;
    if (cmp(l1, l2)) ret = AddNumber(l1, l2);
    else ret = AddNumber(l2, l1);
    return ret;
}

int main() {
    ListNode *l1 = NULL;
    /*NewNode(7);
    l1->next = NewNode(2);
    l1->next->next = NewNode(4);
    l1->next->next->next = NewNode(3);
    */

    ListNode *l2 = NULL;
    /*= NewNode(5);
    l2->next = NewNode(6);
    l2->next->next = NewNode(4);
    */ 
    ListNode *l3 = addTwoNumbers(l1, l2);
    ListNode *head = l3;
    while (head && head->next) {
        printf("%d->", head->val);
        head = head->next;
    }
    if (head) printf("%d", head->val);
    printf("\n");
    return 0;
}

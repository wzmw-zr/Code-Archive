/*************************************************************************
	> File Name: 4.21.leetcode.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月23日 星期日 10时22分20秒
 ************************************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

ListNode *NewListNode(int val) {
    ListNode *p = (ListNode *) malloc(sizeof(ListNode));
    p->val = val;
    p->next = NULL;
    return p;
}

ListNode *insert(ListNode *head, int val) {
    if (!head) return NewListNode(val);
    ListNode *p = head;
    while (p->next) p = p->next; 
    p->next = NewListNode(val);
    return head;
}

void clear(ListNode *head) {
    if (!head) return ;
    ListNode *p;
    while (head) {
        p = head->next;
        free(head);
        head = p;
    }
}


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p = NULL, *q;
    while (l1 || l2) {
        if (l1 && (!l2 || l1->val < l2->val)) {
            printf("l1->val = %d\n", l1->val);
            if (!p) p = l1, q = p, l1 = l1->next;
            else {
                p->next = l1;
                l1 = l1->next;
                p = p->next;
            }
        } else {
            printf("l2->val = %d\n", l2->val);
            if (!p) p = l2, q = p, l2 = l2->next;
            else {
                p->next = l2;
                l2 = l2->next;
                p = p->next;
            }
        }
    }
    return q;
}

int main() {
    ListNode *l1 = NULL, *l2 = NULL;
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        l1 = insert(l1, m);
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        l2 = insert(l2, m);
    }
    l1 = mergeTwoLists(l1, l2);
    while (l1) {
        printf("%d ", l1->val);
        l1 = l1->next;
    }
    printf("\n");
    return 0;
}

/*************************************************************************
	> File Name: 3.AC.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月28日 星期五 19时33分32秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;
#define BASE 26
#define BEGIN_LETTER 'a'

typedef struct Node {
    int flag;
    struct Node *next[BASE], *fail;
} Node;

typedef struct Queue {
    Node **data;
    int head, tail, size;
} Queue;

Queue *init_q(int n) {
    Queue *q = (Queue *) calloc(sizeof(Queue), 1);
    q->data = (Node **) calloc(sizeof(Node *), n);
    q->head = q->tail = 0;
    q->size = n;
    return q;
}

int empty(Queue *q) {
    return q->head == q->tail;
}

Node *front(Queue *q) {
    return q->data[q->head];
}

void push(Queue *q, Node *node) {
    q->data[q->tail++] = node;
}

void pop(Queue *q) {
    if (empty(q)) return ;
    q->head++;
}

void clear_queue(Queue *q) {
    if (!q) return ;
    free(q->data);
    free(q);
}

Node *getNewNode() {
    Node *p = (Node *) calloc(sizeof(Node), 1);
    return p;
}

int insert(Node *root, const char *str) {
    int cnt = 0;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        if (!p->next[str[i] - BEGIN_LETTER]) p->next[str[i] - BEGIN_LETTER] = getNewNode(), cnt++;
        p = p->next[str[i] - BEGIN_LETTER];
    }
    p->flag = 1;
    return cnt;
}

void clear(Node *p) {
    if (!p) return ;
    for (int i = 0; i < BASE; i++) clear(p->next[i]);
    free(p);
}

void build_ac(Node *root, int n) {
    Queue *q = init_q(n + 10); 
    root->fail = NULL;
    push(q, root);
    while (!empty(q)) {
        Node *now_node = front(q);
        pop(q);
        for (int i = 0; i < BASE; i++) {
            if (!now_node->next[i]) continue;
            Node *p = now_node->fail;
            while (p && p->next[i] == NULL) p = p->fail;
            if (!p) now_node->next[i]->fail = root;
            else now_node->next[i]->fail = p->next[i];
            push(q, now_node->next[i]);
        }
    }
}

int match(Node *root, const char *str) {
    Node *p = root;
    int cnt = 0;
    for (int i = 0; str[i]; i++) {
        int ind = str[i]  - BEGIN_LETTER;
        while (p && p->next[ind] == NULL) p = p->fail;
        if (p == NULL) p = root;
        else p = p->next[ind];
        Node *q = p;
        while (q) cnt += q->flag, q = q->fail;
    }
    return cnt;
}



int main() {
    Node *root = getNewNode();
    int n, cnt;
    int op;
    char str[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        cnt += insert(root, str);
    }
    // build fail pointer
    build_ac(root, n);
    scanf("%s", str);
    // match ac
    printf("match word count = %d\n", match(root, str));
    return 0;
}

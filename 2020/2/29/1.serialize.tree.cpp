/*************************************************************************
    > File Name: 1.serialize.tree.cpp
    > Author:赵睿 
    > Mail: 1767153298@qq.com
    > Created Time: 2020年02月29日 星期六 09时05分18秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

TreeNode *NewTreeNode(int val) {
    TreeNode *p = (TreeNode *) calloc(sizeof(TreeNode), 1);
    p->val = val;
    return p;
}

typedef struct Queue {
    TreeNode **data;
    int head, tail, size;
} Queue;

Queue *NewQueue(int size) {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->data = (TreeNode **) malloc(sizeof(TreeNode *) * (2 * size + 1));
    q->head = q->tail = 0;
    q->size = 2 * size;
    return q;
}

int empty(Queue *q) {
    return q->head == q->tail;
}

void push_queue(Queue *q, TreeNode *t) {
    if (!q) return ;
    if (q->size == q->tail) return ;
    q->data[q->tail++] = t; 
}

TreeNode *front(Queue *q) {
    if (!q) return NULL;
    if (empty(q)) return NULL;
    return q->data[q->head];
}

void pop_queue(Queue *q) {
    if (!q) return ;
    if (empty(q)) return ;
    q->head++;
}

void clearQueue(Queue *q) {
    if (!q) return ;
    free(q->data);
    free(q);
}

int node_count(TreeNode *root) {
    if (!root) return 0;
    return 1 + node_count(root->left) + node_count(root->right);
}

/** Encodes a tree to a single string. */
char* serialize(struct TreeNode* root) {
     int cnt = node_count(root), len = 1, num = 0;
     Queue *q = NewQueue(cnt);
     char *ret = (char *) calloc(sizeof(char), 16 * cnt + 5);
     ret[0] = '[';
     TreeNode *p = root;
    push_queue(q, p);
    while (!empty(q)) {
        p = front(q);
        pop_queue(q);
        printf("cnt = %d\n", cnt);
        if (!p) {
            if (!cnt) break;
            if (num) len += sprintf(ret + len, ",null");
            else len += sprintf(ret + len, "null");
            num++;
        } else {
            if (!cnt) break;
            if (num) len += sprintf(ret + len, ",%d", p->val), cnt--;
            else len += sprintf(ret + len, "%d", p->val), cnt--;
            num++;
        }
        if (p) push_queue(q, p->left), push_queue(q, p->right);
    }
    ret[len] = ']';
    return ret;
}

int value(char *str) {
    int ret = 0;
    if (str[0] != '-') {
        for (int i = 0; str[i]; i++) ret = ret * 10 + str[i] - '0';
    } else {
        for (int i = 1; str[i]; i++) ret = ret * 10 + str[i] - '0';
        ret = -ret;
    }
    return ret;
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {
    int len = strlen(data), cur_cnt = 1, next_cnt = 0;
    data[len - 1] = '\0';
    data++;
    char *str = strtok(data, ",");
    if (!str) return NULL;
    TreeNode *root = NewTreeNode(value(str)), *p;
    Queue *q = NewQueue(len);
    push_queue(q, root);
    while (!empty(q)) {
        p = front(q);
        pop_queue(q);
        str = strtok(NULL, ",");
        if (!str) return root;
        if (strcmp(str, "null")) {
            p->left = NewTreeNode(value(str));
            push_queue(q, p->left);
            next_cnt++;
        }
        str = strtok(NULL, ",");
        if (!str) return root;
        if (strcmp(str, "null")) {
            p->right = NewTreeNode(value(str));
            push_queue(q, p->right);
            next_cnt++;
        }
        cur_cnt--;
        if (!cur_cnt) cur_cnt = next_cnt, next_cnt = 0;
    }
    return root;
}
// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);
//
void output(TreeNode *root) {
    if (!root) return ;
    printf("%d ", root->val);
    output(root->left);
    output(root->right);
}


int main() {
    TreeNode *root = NewTreeNode(-1);
    root->left = NewTreeNode(0);
    root->right = NewTreeNode(1);
    //root->right->left = NewTreeNode(4);
    //root->right->right = NewTreeNode(5);
    
    output(root);
    printf("\n");
    char *s = serialize(root);
    printf("%s\n", s);
    TreeNode *ret = deserialize(s);
    output(ret);
    printf("\n");
    return 0;
}

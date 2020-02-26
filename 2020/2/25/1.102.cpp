/*************************************************************************
	> File Name: 1.102.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月25日 星期二 08时13分02秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 
typedef struct TreeNode TreeNode;

typedef struct queue {
    struct TreeNode **data;
    int head, tail, size;
} Queue;

Queue *NewQueue(int size) {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->data = (struct TreeNode **) malloc(sizeof(struct TreeNode *) * 2 *size); 
    q->head = q->tail = 0;
    q->size = 2 * size;
    return q;
}

TreeNode *NewTreeNode(int val) {
    TreeNode *t = (TreeNode *) malloc(sizeof(TreeNode));
    t->val = val;
    t->left = t->right = NULL;
    return t;
}

int empty(Queue *q) {
    return q->head == q->tail;
}

void push_queue(Queue *q, struct TreeNode *node) {
    if (q->tail == q->size) return ;
    q->data[q->tail++] = node;
}

struct TreeNode *front(Queue *q) {
    return q->data[q->head];
}

void pop(Queue *q) {
    if (!q) return ;
    if (empty(q)) return ;
    q->head++;
}

void clearQueue(Queue *q) {
    if (!q) return ;
    free(q->data);
    free(q);
}

int count_node(struct TreeNode *root) {
    if (!root) return 0;
    return 1 + count_node(root->left) + count_node(root->right);
}

int height(struct TreeNode *root) {
    if (!root) return 0;
    int h_l = height(root->left);
    int r_l = height(root->right);
    return 1 + (h_l > r_l ? h_l : r_l);
}

/*int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int count = count_node(root);
    int h = height(root);
    *returnSize = h;
    int **ret = (int **) malloc(sizeof(int *) * h);
    returnColumnSizes = (int **) malloc(sizeof(int *) * h);
    for (int i = 0; i < h; i++) ret[i] = (int *) malloc(sizeof(int) * count);
    Queue *q = NewQueue(count);
    int cur_cnt = 0, next_cnt = 0, layer = 0;
    push_queue(q, *root);
    cur_cnt++;
    while (!empty(q)) {
        int ind = 0;
        *returnColumnSizes[layer] = cur_cnt;
        while (cur_cnt--) {
            if (front(q).left) push_queue(q, *(front(q).left)), next_cnt++;
            if (front(q).right) push_queue(q, *(front(q).right)), next_cnt++;
            ret[layer][ind++] = front(q).val;
            pop(q);
        }
        cur_cnt = next_cnt;
        layer++;
    }
    return ret;
}
*/


int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int cnt = count_node(root);
    int h = height(root);
    *returnSize = h;
    int **ret = (int **) malloc(sizeof(int *) * h);
    *returnColumnSizes = (int *) malloc(sizeof(int) * h);
    for (int i = 0; i < h; i++) ret[i] = (int *) malloc(sizeof(int) * cnt);
    Queue *q = NewQueue(cnt);
    int cur_cnt = 0, next_cnt = 0, layer = 0;
    push_queue(q, root);
    cur_cnt++;
    while (!empty(q)) {
        int ind = 0;
        (*returnColumnSizes)[layer] = cur_cnt; 
        while (cur_cnt--) {
            if (front(q)->left) {
                push_queue(q, front(q)->left);
                next_cnt++;
            }
            if (front(q)->right) {
                push_queue(q, front(q)->right);
                next_cnt++;
            }
            ret[layer][ind++] = front(q)->val;
            pop(q);
        }
        cur_cnt = next_cnt;
        next_cnt = 0;
        layer++;
    }
    return ret;
}

void output(TreeNode *root) {
    if (!root) return ;
    printf("%d ", root->val);
    output(root->left);
    output(root->right);
}

int main() {
    TreeNode *root = NULL;
    int returnSize, *returnColumnSizes, **ret;
    ret =  levelOrder(root, &returnSize, &returnColumnSizes);
    printf("returnSize = %d\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            j && printf(" ");
            printf("%d", ret[i][j]);
        }
        printf("\n");
    }
    return 0;
}

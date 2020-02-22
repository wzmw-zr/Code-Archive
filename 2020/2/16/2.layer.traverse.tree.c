/*************************************************************************
	> File Name: 2.layer.traverse.tree.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月16日 星期日 08时09分02秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    char data;
    struct node *lchild, *rchild;
} Node;

typedef struct tree {
    Node *root;
} Tree;

typedef struct stack {
    Node **data;
    int size, top;
} Stack;

typedef struct queue {
    Node **data;
    int head, tail, size;
} Queue;

Node *NewNode(char c) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = c;
    node->lchild = node->rchild = NULL;
    return node;
}

Tree *NewTree() {
    Tree *tree = (Tree *) malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

Stack *NewStack(int n) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->data = (Node **) malloc(sizeof(Node *) * n);
    s->size = n;
    s->top = -1;
    return s;
}

int s_empty(Stack *s) {
    return s->top == -1;
}

Node *s_top(Stack *s) {
    return s->data[s->top];
}

int s_push(Stack *s, Node *node) {
    if (!s) return 0;
    if (s->top == s->size - 1) return 0;
    s->data[++s->top] = node;
    return 1;
}

Node *s_pop(Stack *s) {
    if (!s) return NULL;
    if (s_empty(s)) return NULL;
    return s->data[s->top--];
}



Queue *NewQueue(int n) {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->data = (Node **) malloc(sizeof(Node *) * n);
    q->size = n;
    q->head = q->tail = 0;
    return q;
}

int q_empty(Queue *q) {
    return q->head == q->tail;
}

Node *front(Queue *q) {
    return q->data[q->head];
}

int q_push(Queue *q, Node *node) {
    if (!q) return 0;
    if (q->tail == q->size - 1) return 0;
    q->data[q->tail++] = node;
    return 1;
}

Node *q_pop(Queue *q) {
    if (!q) return NULL;
    if (q_empty(q)) return NULL;
    return q->data[q->head++];
}


void clearNode(Node *root) {
    if (!root) return ;
    clearNode(root->lchild);
    clearNode(root->rchild);
    free(root);
    return ;
}

void clearTree(Tree *tree) {
    if (!tree) return ;
    clearNode(tree->root);
    free(tree);
    return ;
}

void clearStack(Stack *s) {
    if (!s) return ;
    free(s->data);
    free(s);
    return ;
}

void clearQueue(Queue *q) {
    if (!q) return ;
    free(q->data);
    free(q);
    return ;
}

Node *build(char *str, int *num) {
    Node *temp, *p;
    Stack *s = NewStack(strlen(str));
    int flag = 0;
    while (str[0]) {
        switch (str[0]) {
            case '(' : {
                s_push(s, temp);
                flag = 0;
                break;
            }
                case ',' : {
                    flag = 1;
                    break;
                }
                case ')' : {
                    p = s_pop(s);
                    break;
                }
            default : {
                *num++;
                temp = NewNode(str[0]);
                if (!s_empty(s) && flag == 0) {
                    s_top(s)->lchild = temp;
                }
                if (!s_empty(s) && flag == 1) {
                    s_top(s)->rchild = temp;
                }
                break;
            }
        }
        str++;
    }
    clearStack(s);
    if (!p) p = temp;
    return p;
}

void layer_traverse_node(Node *root, int n) {
    if (!root) return ;
    Queue *q = NewQueue(n);
    q_push(q, root);
    int flag = 0;
    while (!q_empty(q)) {
        Node *node = q_pop(q);
        flag && printf(" ");
        printf("%c", node->data);
        if (node->lchild) q_push(q, node->lchild);
        if (node->rchild) q_push(q, node->rchild);
        flag = 1;
    }
}

void layer_traverse(Tree *tree, int n) {
    if (!tree) return ;
    layer_traverse_node(tree->root, n);
    printf("\n");
    return ;
}

int main() {
    char str[100] = {0};
    scanf("%s", str);
    Tree *tree = NewTree();
    int num = 0;
    tree->root = build(str, &num);
    layer_traverse(tree, num); 
    return 0;
}

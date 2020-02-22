/*************************************************************************
	> File Name: 5.table.to.binary.tree.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月15日 星期六 20时31分38秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct node {
    char data;
    struct node *lchild, *rchild;
} Node;

typedef struct tree {
    Node *root;
    int n;
} Tree;

typedef struct stack {
    Node **data;
    int size, top;
} Stack;

Node *getNewNode(char val) {
    Node *p = (Node *) malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    return p;
}

Tree *getNewTree() {
    Tree *t = (Tree *) malloc(sizeof(Tree));
    t->root = NULL;
    t->n = 0;
    return t;
}


Stack *init_stack(int n) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->data = (Node **) malloc(sizeof(Node *) * n);
    s->size = n;
    s->top = -1;
    return s;
}

int empty(Stack *s) {
    return s->top == -1;
}

Node *top(Stack *s) {
    return s->data[s->top];
}

int push(Stack *s, Node *p) {
    if (!s) return 0;
    if (s->top == s->size - 1) return 0;
    s->data[++(s->top)] = p;
    return 1;
}

int pop(Stack *s) {
    if (!s) return 0;
    s->top--;
    return 1;
}

void clear_Node(Node *root) {
    if (!root) return ;
    clear_Node(root->lchild);
    clear_Node(root->rchild);
    free(root);
    return ;
}

void clear_Tree(Tree *tree) {
    if (!tree) return ;
    clear_Node(tree->root);
    free(tree);
    return ;
}

void clearStack(Stack *s) {
    if (!s) return ;
    free(s->data);
    free(s);
    return ;
}

Node *build(char *str, int *node_num) {
    Node *temp = NULL, *p = NULL;
    Stack *s = init_stack(strlen(str));
    int flag = 0;
    while (str[0]) {
        switch (str[0]) {
            case '(' : {
                push(s, temp);
                flag = 0;
                //temp = NULL;
                break;
            } 
            case ')' : {
                p = top(s);
                pop(s);
                break;
            }
            case ',' : {
                flag = 1;
                //temp = NULL;
                break;
            }
            case ' ' : break;
            default : {
                *node_num += 1;
                temp = getNewNode(str[0]);
                if (!empty(s) && flag == 0) {
                    top(s)->lchild = temp;
                }  else if (!empty(s) && flag == 1) {
                    top(s)->rchild = temp;
                }
                break;
            }
        }
        str++;
    }
    clearStack(s);
    if (temp && !p) p = temp; 
    return p;
}

void in_orderNode(Node *root) {
    if (!root) return ;
    in_orderNode(root->lchild);
    printf("%c ", root->data);
    in_orderNode(root->rchild);
    return ;
}

void in_order(Tree *tree) {
    if (!tree) return ;
    printf("in_order(%d) = ", tree->n);
    in_orderNode(tree->root);
    printf("\n");
}

void pre_orderNode(Node *root) {
    if (!root) return ;
    printf("%c ", root->data);
    pre_orderNode(root->lchild);
    pre_orderNode(root->rchild);
    return ;
}

void pre_order(Tree *tree) {
    if (!tree) return ;
    printf("pre_order(%d) = ", tree->n);
    pre_orderNode(tree->root);
    printf("\n");
}

void post_orderNode(Node *root) {
    if (!root) return ;
    post_orderNode(root->lchild);
    post_orderNode(root->rchild);
    printf("%c ", root->data);
    return ;
}

void post_order(Tree *tree) {
    if (!tree) return ;
    printf("post_order(%d) = ", tree->n);
    post_orderNode(tree->root);
    printf("\n");
}

int main() {
    char str[100];
    scanf("%[^\n]s", str);
    int node_num = 0;
    Tree *tree = getNewTree();
    tree->root = build(str, &node_num);
    tree->n = node_num;
    pre_order(tree), printf("\n");
    in_order(tree), printf("\n");
    post_order(tree),printf("\n");
    return 0;
}

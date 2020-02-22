/*************************************************************************
	> File Name: 7.recursive.delete.node.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月15日 星期六 23时05分45秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    char data;
    struct node *rchild, *lchild;
}Node;

typedef struct tree {
    Node *root;
} Tree;

typedef struct stack {
    Node **data;
    int size, top;
} Stack;

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
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->data = (Node **) malloc(sizeof(Node *) * n);
    stack->size = n;
    stack->top = -1;
    return stack;
}

int empty(Stack *s) {
    return s->top == -1;
}

Node *top(Stack *s) {
    return s->data[s->top];
}

int push(Stack *s, Node *node) {
    if (!s) return 0;
    if (s->top == s->size - 1) return 0;
    s->data[++(s->top)] = node;
    return 1;
}

Node *pop(Stack *s) {
    if (!s) return NULL;
    if (empty(s)) return NULL;
    return s->data[s->top--];
}

void clearNode(Node *node) {
    if (!node) return ;
    clearNode(node->lchild);
    clearNode(node->rchild);
    free(node);
    return ;
}

void clearTree(Tree *tree) {
    if (!tree) return ;
    clearNode(tree->root);
    free(tree);
    return ;
}

void clearStack(Stack *stack) {
    if (!stack) return ;
    free(stack->data);
    free(stack);
    return ;
}

Node *build(char *str) {
    Node *temp, *p;
    int flag = 0;
    Stack *s = NewStack(strlen(str));
    while (str[0]) {
        switch (str[0]) {
            case '(' : {
                push(s, temp); 
                flag = 0;
                break;
            }
            case ',' : {
                flag = 1; 
                break;
            }
            case ')' : {
                p = pop(s);
                break;
            }
            default : {
                temp = NewNode(str[0]);
                if (!empty(s) && flag == 0) {
                    top(s)->lchild = temp;
                }
                if (!empty(s) && flag == 1) {
                    top(s)->rchild = temp;
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

Node *DeleteNode(Node *node, char c) {
    if (!node) return NULL;
    if (node->data == c) {
        clearNode(node);
        return NULL;
    }
    node->lchild = DeleteNode(node->lchild, c);
    node->rchild = DeleteNode(node->rchild, c);
    return node;
}

void Delete(Tree *tree, char c) {
    if (!tree) return ;
    tree->root = DeleteNode(tree->root, c);
    return ;
}

void outputNode(Node *root) {
    if (!root) return ;
    printf("%c", root->data);
    if (root->lchild) {
        printf("(");
        outputNode(root->lchild);
        root->rchild && printf(",");
        if (!root->rchild) printf(")");
    }
    if (root->rchild) {
        if (!root->lchild) printf("(,");
        outputNode(root->rchild);
        printf(")");
    }
    return ;
}

void output(Tree *tree) {
    if (!tree) return ;
    outputNode(tree->root);
    printf("\n");
    return ;
}

int main() {
    char str[30], x;
    scanf("%[^\n]s", str);
    if (!strlen(str)) return 0;
    Tree *tree = NewTree();
    tree->root = build(str);
    output(tree);
    scanf("%c", &x);
    Delete(tree, x);
    output(tree);
    return 0;
}

/*************************************************************************
	> File Name: 2.binary.tree.delete.node.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月15日 星期六 13时43分49秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_n 40

typedef struct node {
    char c;
    struct node *lchild, *rchild;
} Node;

typedef struct tree {
    Node *root;
} Tree;

typedef struct stack {
    Node **data;
    int size, top;
} Stack;

Node *NewNode(char c) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->c = c;
    node->lchild = node->rchild = NULL;
    return node;
} 

Tree *NewTree() {
    Tree *tree = (Tree *) malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

Stack *newStack() {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->data = (Node **) malloc(sizeof(Node *) * max_n);
    s->size = max_n;
    s->top = -1;
    return s;
}

void push(Stack *s, Node *node) {
    s->data[++s->top] = node;
    return ;
}

Node *top(Stack *s) {
    return s->data[s->top];
}

void pop(Stack *s) {
    s->top--;
    return ;
}

void clearNode(Node *root) {
    if (!root) return ;
    clearNode(root->lchild);
    clearNode(root->rchild);
    free(root);
}

void clearTree(Tree *tree) {
    if (!tree) return ;
    clearNode(tree->root);
    return ;
}

void clearStack(Stack *s) {
    if (!s) return ;
    free(s->data);
    free(s);
    return ;
}

Node *buildNode(char *s) {
    int flag = -1;
    Node *p, *root;
    Stack *stack = newStack();
    for (int i = 0; i < strlen(s); i++) {
        char c = s[i];
        switch (c) {
            case '(': {
                flag = 0;
                push(stack, p);
            } break;
            case ',': {
                flag = 1; 
            } break;
            case ')' : {
                pop(stack);
            } break;
            default: {
                Node *tmp = NewNode(c);
                switch (flag) {
                    case -1 : {
                        root = tmp;
                        push(stack, root);
                    } break;
                    case 0 : {
                        if (top(stack) == p) pop(stack); 
                        top(stack)->lchild = tmp;
                        push(stack, tmp);
                    } break;
                    case 1 : {
                        pop(stack);
                        top(stack)->rchild = tmp;
                        push(stack, tmp);
                    } break;
                }
            } break;
        }
    }
    return root;
}

Tree *build(char *s) {
    Tree *tree = NewTree();
    tree->root = buildNode(s);
    return tree;
}

void output(Tree *tree) {
    if (!tree) return ;
    printf("tree");
}

int main() {
    return 0;
}

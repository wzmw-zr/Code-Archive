/*************************************************************************
	> File Name: 1.binary.tree.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月15日 星期六 08时26分32秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_n 30 

typedef struct node {
    char c;
    struct node *lchild, *rchild;
} Node;

typedef struct tree {
    Node *root;
} Tree;

typedef struct stack {
    Node **node;
    int size, top;
} Stack;

Node *newNode(char c) {
    Node *n  = (Node *) malloc(sizeof(Node));
    n->c = c;
    n->lchild = n->rchild = NULL;
    return n;
}

Tree *newTree() {
    Tree *t = (Tree *) malloc(sizeof(Tree));
    t->root = NULL;
    return t;
}

Stack *newStack() {
    Stack *s = (Stack *) malloc(sizeof(Stack)); 
    s->node = (Node **) malloc(sizeof(Node *) * max_n);
    s->size = max_n;
    s->top = -1;
    return s;
}

void push(Stack *s, Node *node) {
    if (!s) return ;
    if (s->top == s->size - 1) return ;
    s->node[++(s->top)] = node;
    return ;
}

Node *pop(Stack *s) {
    return s->node[(s->top)--];
}


void clearNode(Node *node); 

Node *buildNode(char *str, int len) {
    Stack *s = newStack();
    int k = -1;
    Node *p, *root = NULL;
    int i = 0;
    while (i < len) {
        switch (str[i]) {
            case '(' : {
                k = 0;
                push(s, p);
            } break;
            case ';' : {
                k = 1;
            } break;
            case ')' : {
                pop(s);
            } break;
            default : {
                Node *temp = newNode(str[i]);
                if (k == -1) {
                    root = temp;
                    push(s, temp);
                } 
                else if (k == 0) {
                    if (s->node[s->top] == p) pop(s);
                    s->node[s->top]->lchild = temp;
                    push(s, temp);
                } else {
                    pop(s);
                    s->node[s->top]->rchild = temp;
                    push(s, temp);
                }
            }
        }
        i++;
    }
    return root;
}


Tree *buildTree(char *s) {
    Tree *t = (Tree *) malloc(sizeof(Tree));
    int len = strlen(s);
    t->root = buildNode(s, len);
    return t;
}

void deleteNode(Node *root, char c) {
    if (!root) return ;
    if (root->c = c) {
        clearNode(root);
        return ;
    }
    deleteNode(root->lchild, c);
    deleteNode(root->rchild, c);
    return ;
}

void delete(Tree *t, char c) {
    if (!t) return ;
    deleteNode(t->root, c);
    return ;
}

void outputNode(Node *root) {
    if (!root) return ;
    printf("%c", root->c);
    if (root->lchild) {
        printf("(");
        outputNode(root->lchild);
        if (!root->rchild) printf(")");
    }
    if (root->rchild) {
        if (!root->lchild) printf("(");
        printf(",");
        outputNode(root->rchild);
        printf(")");
    }
    return ;
}

void outputTree(Tree *t) {
    if (!t) return ;
    outputNode(t->root);
    printf("\n");
    return ;
}

void clearNode(Node *node) {
    if (!node) return ;
    clearNode(node->lchild);
    clearNode(node->rchild);
    free(node);
    return ;
}

void clearTree(Tree *t) {
    if (!t) return ;
    clearNode(t->root);
    return ;
}

int main() {
    char s[30], u;
    scanf("%s\n", s);
    scanf("%c", &u);
    Tree *t = buildTree(s);
    delete(t, u);
    outputTree(t);
    return 0;
}

/*************************************************************************
	> File Name: 2.segment.tree.heap.store.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月08日 星期日 14时45分06秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;
#define MAX_N 20

typedef struct Node {
    int value, left, right, lazy;
} Node;

typedef struct SegmentTree {
    Node **data;
    int size;
} SegmentTree;

Node *getNewNode(int value, int left, int right) {
    Node *p = (Node *) malloc(sizeof(Node));
    p->value = value;
    p->left = left;
    p->right = right;
    p->lazy = 0;
    return p;
}

SegmentTree *getNewSegmentTree(int size) {
    SegmentTree *tree = (SegmentTree *) malloc(sizeof(SegmentTree));
    tree->data = (Node **) calloc(sizeof(Node *), size);
    tree->size = size;
    return tree;
}

void buildSegmentTree(int *arr, SegmentTree *tree, int ind, int left, int right) {
    if (left == right) {
        tree->data[ind] = getNewNode(arr[left], left, right);
        return ;
    }
    int mid = (left + right) >> 1;
    buildSegmentTree(arr, tree, ind << 1, left, mid);
    buildSegmentTree(arr, tree, ind << 1 | 1, mid + 1, right);
    tree->data[ind] = getNewNode(tree->data[ind << 1]->value + tree->data[ind << 1 | 1]->value, left, right);
}

void clearNode(Node *node) {
    if (!node) return ;
    free(node);
}

void clearTree(SegmentTree *tree) {
    for (int i = 1; i < tree->size; i++) {
        if (tree->data[i]) clearNode(tree->data[i]);
    }
    free(tree->data);
    free(tree);
}

void output(SegmentTree *tree, int ind) {
    if (!tree) return ;
    if (!tree->data[ind]) return ;
    if (ind >= tree->size) return ;
    printf("sum of index from %d to %d is %d\n", tree->data[ind]->left, tree->data[ind]->right, tree->data[ind]->value);
    output(tree, ind << 1);
    output(tree, ind << 1 | 1);
}

int query(SegmentTree *tree, int ind, int left, int right) {
    if (tree->data[ind]->left > right || tree->data[ind]->right < left) return 0;
    if (tree->data[ind]->left >= left && tree->data[ind]->right <= right) 
    return tree->data[ind]->value;
    tree->data[ind << 1]->lazy += tree->data[ind]->lazy;
    tree->data[ind << 1]->value += tree->data[ind << 1]->lazy * (tree->data[ind << 1]->right - tree->data[ind << 1]->left + 1);
    tree->data[ind << 1 | 1]->lazy += tree->data[ind]->lazy;
    tree->data[ind << 1 | 1]->value += tree->data[ind << 1 | 1]->lazy * (tree->data[ind << 1 | 1]->right - tree->data[ind << 1 | 1]->left + 1);
    tree->data[ind]->lazy = 0;
    return query(tree, ind << 1, left, right) + query(tree, ind << 1 | 1, left, right);
}

void one_element_modify(SegmentTree *tree, int ind, int elem_ind, int new_value) {
    if (tree->data[ind]->left == tree->data[ind]->right) {
        tree->data[ind]->value = new_value;
        return ;
    }
    int mid = (tree->data[ind]->left + tree->data[ind]->right) >> 1;
    if (mid >= elem_ind) one_element_modify(tree, ind << 1, elem_ind, new_value);
    else one_element_modify(tree, ind << 1 | 1, elem_ind, new_value);
    tree->data[ind]->value = tree->data[ind << 1]->value + tree->data[ind << 1 | 1]->value;
}

void interval_modify(SegmentTree *tree, int ind, int left, int right, int add_value) {
    if (tree->data[ind]->left > right || tree->data[ind]->right < left) return ;
    if (tree->data[ind]->left <= left && tree->data[ind]->right >= right)  {
        tree->data[ind]->value += add_value * (tree->data[ind]->right - tree->data[ind]->left + 1);
        tree->data[ind]->lazy += add_value;
        return ;
    }
    interval_modify(tree, ind << 1, left, right, add_value);
    interval_modify(tree, ind << 1 | 1, left, right, add_value);
    tree->data[ind]->value = tree->data[ind << 1]->value + tree->data[ind << 1 | 1]->value;
}

int main() {
    srand(time(0));
    int num[MAX_N + 5] = {0};
    for (int i = 1; i <= MAX_N; i++) num[i] = i;
    SegmentTree *tree = getNewSegmentTree(4 * MAX_N);
    buildSegmentTree(num, tree, 1, 1, MAX_N);
    //output(tree, 1);
    for (int i = 1; i <= 10; i++) {
        printf("the sum of index from %d to %d is %d\n", i, i + 5, query(tree, 1, i, i + 5));  
    }
    for (int i = 1; i <= 10; i++) {
        one_element_modify(tree, 1, i, i + 1);
    }
    printf("\n");
    for (int i = 1; i <= 10; i++) {
        printf("the sum of index from %d to %d is %d\n", i, i + 5, query(tree, 1, i, i + 5));  
    }
    printf("\n");
    output(tree, 1);
    printf("\n");
    interval_modify(tree, 1, 1, 10, 3);
    for (int i = 1; i <= 10; i++) {
        printf("the sum of index from %d to %d is %d\n", i, i + 5, query(tree, 1, i, i + 5));  
    }
    return 0;
}

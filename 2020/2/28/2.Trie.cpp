/*************************************************************************
	> File Name: 2.Trie.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月28日 星期五 15时43分49秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int N = 100010;
const int SIZE = 26;
const char BASE = 'a';

typedef struct TrieNode {
    int flag;
    struct TrieNode *next[SIZE];
} TrieNode, *Trie;

int sub_string_cnt(TrieNode *root) {
    if (!root) return 0;
    int cnt = root->flag;
    for (int i = 0; i < SIZE; i++)  cnt += sub_string_cnt(root->next[i]);
    return cnt;
}

TrieNode* new_node() {
    TrieNode *p = (TrieNode *) calloc(sizeof(TrieNode), 1); 
    return p;
}

void clear(TrieNode *root) {
    if (!root) return ;
    for (int i = 0; i < SIZE; i++) clear(root->next[i]);
    free(root);
}

void insert(TrieNode *root, char *str) {
    TrieNode *p = root;
    for (int i = 0; str[i]; i++) {
        if (!p->next[str[i] - BASE]) p->next[str[i] - BASE] = new_node();
        p  = p->next[str[i] - BASE];
    }
    p->flag = 1;
}


int main() {
    TrieNode *root = new_node();
    char str[N], temp[N];
    scanf("%s", str);
  	int len = strlen(str);
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            memset(temp, 0, sizeof(char) * N);
            memcpy(temp, str + i, j - i + 1);
            insert(root, temp);
        }
    }
    printf("%d\n", sub_string_cnt(root));
    return 0;
}

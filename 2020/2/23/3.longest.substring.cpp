/*************************************************************************
	> File Name: 3.longest.substring.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月23日 星期日 08时21分11秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    char c;
    int ind;
} Node;

typedef struct HashTable {
    Node **str;
    int size, cnt;
} HashTable; 

Node *NewNode(char c, int ind) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->c = c;
    node->ind = ind;
    return node;
}

HashTable *init(int n) {
    HashTable *h = (HashTable *) malloc(sizeof(HashTable));
    h->str = (Node **) calloc(sizeof(Node *), (n + 1));
    h->size = n;
    h->cnt = 0;
    return h;
}

int insert(HashTable *h, char c, int ind) {
    if (!h) return 0;
    h->str[c] = NewNode(c, ind); 
    h->cnt++;
    return 1;
}

int find(HashTable *h, char c) {
    if (h->str[c]) return 1;
    return 0;
}

void clear(HashTable *h) {
    if (!h) return ;
    free(h->str);
    free(h);
}

int lengthOfLongestSubstring(char * s){
    HashTable *h = init(10000);
    int max_l = 0, cur_l = 0;
    for (int i = 0; s[i]; i++) {
        if (find(h, s[i]))  {
            if (cur_l > max_l) max_l = cur_l;
            i = h->str[s[i]]->ind;
            memset(h->str, 0, sizeof(char) * (h->size) + 1);
            cur_l = 0;
        } else {
            insert(h, s[i], i);
            cur_l++;
        }
    }
    if (cur_l > max_l) max_l = cur_l;
    return max_l;
}

int main() {
    char str[100];
    scanf("%s", str);
    printf("result = %d\n", lengthOfLongestSubstring(str));
    return 0;
}

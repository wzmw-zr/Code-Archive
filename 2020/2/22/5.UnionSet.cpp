/*************************************************************************
	> File Name: 4.UnionSet.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月22日 星期六 20时19分12秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define swap(a, b) {\
    a ^= b; b ^= a; a ^= b;\
}

typedef struct UnionSet {
    int *father, *size;
    int n;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *s = (UnionSet *) malloc(sizeof(UnionSet));
    s->father = (int *) malloc(sizeof(int) * (n + 1));
    s->size = (int *) malloc(sizeof(int) * (n + 1));
    s->n = n;
    for (int i = 1; i <= n; i++) {
        s->father[i] = i;
        s->size[i] = 1;
    }
    return s;
}

int find(UnionSet *u, int x) {
    return u->father[x] = u->father[x] == x ? x : find(u, u->father[x]);
}

int merge(UnionSet *u, int a, int b) {
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return 0;
    if (u->size[fa] > u->size[fb]) swap(fa, fb);
    u->father[fa] = fb;
    u->size[fb] += u->size[fa];
    return 1;
}

void clear(UnionSet *u) {
    if (!u) return ;
    free(u->father);
    free(u->size);
    free(u);
}


int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    UnionSet *u = init(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        switch (a) {
            case 1: {
                merge(u, b, c);
            } break;
            case 2: {
                printf("%s\n", find(u, b) == find(u, c) ? "Yes" : "No");
            } break;
        }
    }
    clear(u);
    return 0;
}

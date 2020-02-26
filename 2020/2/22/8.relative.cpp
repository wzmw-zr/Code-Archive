/*************************************************************************
	> File Name: 8.relative.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月22日 星期六 21时39分01秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define swap(a, b) {\
    a ^= b, b ^= a, a ^= b;\
}

typedef struct UnionSet {
    int *father, *size, n;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *) malloc(sizeof(UnionSet));
    u->father = (int *) malloc(sizeof(int) * (n + 1));
    u->size = (int *) malloc(sizeof(int) * (n + 1));
    u->n = n;
    for (int i = 0; i <= n; i++) {
        u->father[i] = i;
        u->size[i] = 1;
    }
    return u;
}

int find(UnionSet *u, int x) {
    if (u->father[x] == x) return x;
    return u->father[x] = find(u, u->father[x]);
}

int merge(UnionSet *u, int a, int b) {
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return 0;
    if (fa > fb) swap(fa, fb);
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
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    UnionSet *u = init(n);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        merge(u, a, b);
    }
    for (int i = 1; i <= p; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%s\n", find(u, a) == find(u, b) ? "Yes" : "No");
    }
    return 0;
}

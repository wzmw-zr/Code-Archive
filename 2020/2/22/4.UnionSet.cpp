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

typedef struct UnionSet {
    int *color;
    int n;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *s = (UnionSet *) malloc(sizeof(UnionSet));
    s->color = (int *) malloc(sizeof(int) * (n + 1));
    s->n = n;
    for (int i = 1; i <= n; i++) {
        s->color[i] = i;
    }
    return s;
}

int find(UnionSet *u, int x) {
    return u->color[x];
}

int merge(UnionSet *u, int a, int b) {
    int ca = find(u, a), cb = find(u, b);
    if (ca == cb) return 0;
    for (int i = 1; i <= u->n; i++) {
        if (u->color[i] != ca) continue;
        u->color[i] = cb;
    }
    return 1;
}

void clear(UnionSet *u) {
    if (!u) return ;
    free(u->color);
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

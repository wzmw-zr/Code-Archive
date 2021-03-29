/*************************************************************************
	> File Name: 4.LeetCode990.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月30日 星期二 01时21分46秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct UnionSet {
    vector<int> fa;
    
    UnionSet() : fa(26) {
        for (int i = 0; i < 26; i++) fa[i] = i;
    }

    int get(int x)  {
        return fa[x] = (x == fa[x] ? x : get(fa[x]));
    }
    
    void merge(int a, int b) {
        int x = get(a);
        int y = get(b);
        if (x == y) return ;
        fa[x] = y;
    }

};

bool equationsPossible(vector<string>& equations) {
    UnionSet u;
    for (string &s : equations) {
        if (s[1] == '=') u.merge(s[0] - 'a', s[3] - 'a');
    }
    for (string &s : equations) {
        if (s[1] == '!') {
            int x = u.get(s[0] - 'a');
            int y = u.get(s[3] - 'a');
            if (x == y) return false;
        }
    }
    return true;
}

int main() {
    return 0;
}

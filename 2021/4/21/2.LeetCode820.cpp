/*************************************************************************
	> File Name: 2.LeetCode820.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月21日 星期三 22时22分03秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

struct UnionSet {
    int n;
    vector<int> fa;

    UnionSet() = default;

    UnionSet(int n) : n(n), fa(vector<int>(n)) {
        for (int i = 0; i < n; i++) fa[i] = i;
    }

    int get(int x) {
        return fa[x] = (x == fa[x]) ? x : get(fa[x]);
    }

    void merge(int x, int y) {
        int a = get(x);
        int b = get(y);
        if (a == b) return ;
        fa[a] = b;
    }
};

bool is_suffix(string &s1, string &s2) {
    int len_1 = s1.size(), len_2 = s2.size();
    for (int i = 0; i < len_2; i++) {
        if (s1[len_1 - 1 - i] == s2[len_2 - 1 - i]) continue;
        return false;
    }
    return true;
}

int minimumLengthEncoding(vector<string>& words) {
    int n = words.size();
    UnionSet u(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int ind_1 = u.get(i);
            int ind_2 = u.get(j);
            int len_1 = words[ind_1].size();
            int len_2 = words[ind_2].size();
            if (len_1 >= len_2) {
                if (is_suffix(words[ind_1], words[ind_2]))
                    u.merge(ind_2, ind_1);
            } else {
                if (is_suffix(words[ind_2], words[ind_1]))
                    u.merge(ind_1, ind_2);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (u.fa[i] == i) ans += words[i].size() + 1;
    }
    return ans;
}

int main() {
    return 0;
}

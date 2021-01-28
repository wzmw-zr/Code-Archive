/*************************************************************************
	> File Name: 2.scc_tarjan.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月28日 星期四 09时43分05秒
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
#define MAX_N 10010

int n;

vector<vector<int>> graph(MAX_N, vector<int>(0));

vector<int> dfn(MAX_N, 0);
vector<int> low(MAX_N, 0);
int dfncnt;

stack<int> st;
vector<int> in_stack(MAX_N, 0);

vector<int> scc(MAX_N, 0);
vector<int> sz(MAX_N, 0);
int sc;

void tarjan(int u) {
    if (dfn[u]) return ;
    st.push(u);
    in_stack[u] = 1;
    dfn[u] = ++dfncnt;
    for (int &v : graph[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else {
            if (in_stack[v]) low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        ++sc;
        while (st.top() != u) {
            scc[st.top()] = sc;
            sz[sc]++;
            in_stack[st.top()] = 0;
            st.pop();
        }
        scc[st.top()] = sc;
        sz[sc]++;
        in_stack[st.top()] = 0;
        st.pop();
    }
}

int main() {
    return 0;
}

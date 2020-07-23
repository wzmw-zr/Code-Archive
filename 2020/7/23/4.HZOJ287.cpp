/*************************************************************************
	> File Name: 4.HZOJ287.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月23日 星期四 18时53分42秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

typedef pair<int, int> PII;

int n, num, t, sum;
set<PII> st;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        st.insert(PII(num, t++));
    }
    for (int i = 0; i < n - 1; i++) {
        int a = st.begin()->first;
        st.erase(st.begin());
        int b = st.begin()->first;
        st.erase(st.begin());
        sum += a + b;
        st.insert(PII(a + b, t++));
    }
    cout << sum;
    return 0;
}

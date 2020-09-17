/*************************************************************************
	> File Name: 6.2019D.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月17日 星期四 22时27分42秒
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

int t, n;

void check(int n) {
    if (n == 1) {
        cout << "No" << endl;
        return ;
    }
    int rest = 1;
    set<int> st;
    while (rest) {
        if (st.find(rest) != st.end()) {
            cout << "Yes" << endl;
            return ;
        }
        st.insert(rest);
        rest *= 10;
        rest %= n;
    }
    cout << "No" << endl;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        check(n);
    }
    return 0;
}

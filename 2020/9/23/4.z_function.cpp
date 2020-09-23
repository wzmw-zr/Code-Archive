/*************************************************************************
	> File Name: 4.z_function.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月23日 星期三 15时09分56秒
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

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n, 0);
    for (int i = 1; i < n; i++) {
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
    }
    return z;
}

int main() {
    string s;
    getline(cin, s);
    auto z = z_function(s);
    for (auto &x : z) cout << x << " ";
    cout << endl;
    return 0;
}

/*************************************************************************
	> File Name: 5.static_variable.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月17日 星期一 18时09分18秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int main() {
    vector<int> xs = { 3, 5, 1, 4, 2 };
    sort(begin(xs), end(xs));
    for (auto x : xs) cout << x << " ";
    cout << endl;

    sort(rbegin(xs), rend(xs));
    for (auto x : xs) cout << x << " ";
    cout << endl;
    return 0;
}

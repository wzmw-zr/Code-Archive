/*************************************************************************
	> File Name: 4.LeetCode1276.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月26日 星期四 19时54分27秒
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

vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
    if (cheeseSlices * 2 > tomatoSlices) return vector<int>(0);
    if (cheeseSlices * 4 < tomatoSlices) return vector<int>(0);
    int rest = tomatoSlices - cheeseSlices * 2;
    if (rest & 1) return vector<int>(0);
    return vector<int>({rest / 2, cheeseSlices - rest / 2});
}

int main() {
    int tomatoSlices, cheeseSlices;
    cin >> tomatoSlices >> cheeseSlices;
    vector<int> ans = numOfBurgers(tomatoSlices, cheeseSlices);
    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}

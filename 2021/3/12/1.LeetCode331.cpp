/*************************************************************************
	> File Name: 1.LeetCode331.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月12日 星期五 07时44分46秒
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

bool isValidSerialization(string preorder) {
    stack<int> cnt; 
    cnt.push(1);
    for (int i = 0; preorder[i];) {
        if (cnt.empty()) return false;
        if (preorder[i] == ',') {
            i++;
        } else if (preorder[i] == '#') {
            if (--cnt.top() == 0) cnt.pop();
            i++;
        } else {
            while (preorder[i] && preorder[i] >= '0' && preorder[i] <= '9') i++;
            if (--cnt.top() == 0) cnt.pop();
            cnt.push(2);
        }
    }
    return cnt.empty();
}

int main() {
    string s;
    cin >> s;
    cout << (isValidSerialization(s) ? "True" : "False") << endl;
    return 0;
}

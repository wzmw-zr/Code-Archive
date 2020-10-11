/*************************************************************************
	> File Name: 4.unseriallize_array.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月11日 星期日 08时32分31秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> unserialize_array(string &s) {
    vector<int> ans;
    s.erase(s.begin());
    s.erase(s.end() - 1);
    int left = 0, right = 0;
    while ((right = s.find(",", left)) != string::npos) {
        ans.push_back(stoi(s.substr(left, right - left)));
        left = right + 1;
    }
    ans.push_back(stoi(s.substr(left, s.size() - left)));
    return ans;
}

int main() {
    string s;
    cin >> s;
    vector<int> ans = unserialize_array(s);
    for (int &x : ans)  cout << x << " ";
    cout << endl;
    return 0;
}

/*************************************************************************
	> File Name: 4.LeetCode722.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月07日 星期三 14时00分51秒
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

vector<string> removeComments(vector<string>& source) {
    vector<string> ans;
    for (int i = 0; i < source.size(); ) {
        string temp = "";
        if (source[i].find("//") != string::npos) {
            temp += source[i].substr(0, source[i].find("//"));
            if (temp != "") ans.push_back(temp);
            i++;
        } else if (source[i].find_first_of("/*") != string::npos) {
            temp += source[i].substr(0, source[i].find("/*"));
            if (source[i].find_last_of("*/") != string::npos) {
                temp += source[i].substr(source[i].find_last_of("*/") + 2);
                if (temp != "") ans.push_back(temp);
                i++;
                break;
            }
            i++;
            while (i < source.size()) {
                if (source[i].find_last_of("*/") == string::npos) {
                    i++;
                    continue;
                }
                temp += source[i].substr(source[i].find_last_of("*/") + 2);
                i++;
                break;
            }
            if (temp != "") ans.push_back(temp);
        } else ans.push_back(source[i++]);
    }
    return ans;
}

int main() {
    return 0;
}

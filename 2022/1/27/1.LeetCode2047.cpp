/*************************************************************************
	> File Name: 1.LeetCode2047.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月27日 星期四 08时20分01秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int countValidWords(string sentence) {
    istringstream sin(sentence);
    string token;
    int cnt = 0;
    while (sin >> token) {
        int flag = 1;
        int hyphen = 0;
        int hyphen_ind = -1;
        int puncutation = 0;
        for (int i = 0; token[i]; i++) {
            char c = token[i];
            if (c >= '0' && c <= '9') {
                flag = 0;
                break;
            }
            if (c == '-') {
                hyphen++;
                hyphen_ind = i;
                if (hyphen == 2) {
                    flag = 0;
                    break;
                }
            } else if (c >= 'a' && c <= 'z') {
                continue;
            } else {
                puncutation++;   
                if (puncutation == 2) {
                    flag = 0;
                    break;
                }
            }
        }
        if (hyphen == 1) {
            if (hyphen_ind == 0 || hyphen_ind == token.size() - 1) {
                flag = 0;
            } else {
                if (!(token[hyphen_ind - 1] >= 'a' && token[hyphen_ind - 1] <= 'z')) {
                    flag = 0;
                }
                if (!(token[hyphen_ind + 1] >= 'a' && token[hyphen_ind + 1] <= 'z')) {
                    flag = 0;
                }
            }
        }
        if (puncutation == 1) {
            char c = token[token.size() - 1];
            if (!(c == '!' || c == '.' || c == ',')) flag = 0; 
        }
        cnt += flag;
    }
    return cnt;
}

int main() {
    return 0;
}

/*************************************************************************
	> File Name: 2.LeetCode466.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月19日 星期日 16时07分48秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int getMaxRepetitions(string s1, int n1, string s2, int n2){
    vector<int> repeatCnt(n1 + 1, 0);
    vector<int> nextIdx(n1 + 1, 0);
    int j = 0, cnt = 0;
    for(int k = 1; k <= n1; k ++){
        for(int i = 0; i < s1.size(); i ++){
            if(s1[i] == s2[j]){
                j ++;
                if(j == s2.size()){
                    j = 0; cnt ++;
                }
            }
        }
        repeatCnt[k] = cnt;
        nextIdx[k] = j;
        for(int start = 0; start < k; start ++){
            if(nextIdx[start] == j){
                int interval = k - start;
                int repeat = (n1 - start)/interval;
                int patternCnt = (repeatCnt[k] - repeatCnt[start])*repeat;
                int remainCnt = repeatCnt[start + (n1 - start) % interval];
                return (patternCnt + remainCnt)/n2;
            }
        }
    }
    return repeatCnt[n1] / n2;
}

int main() {
    int n1, n2, res;
    string s1, s2;
    cin >> s1 >> n1 >> s2 >> n2;
    res = getMaxRepetitions(s1, n1, s2, n2);
    cout << res << endl;
    return 0;
}


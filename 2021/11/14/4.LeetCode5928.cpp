/*************************************************************************
	> File Name: 3.LeetCode5928.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月14日 星期日 11时03分43秒
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
using namespace std;

string decodeCiphertext(string encodedText, int rows) {
    int wzmw_zr_q3 = 0;
    int n = encodedText.size();
    int cols = n / rows;
    vector<vector<char>> matrix(rows, vector<char>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) matrix[i][j] = encodedText[i * cols + j];
    }
    string ans = "";
    for (int i = 0; i < cols; i++) {
        int t = min(rows, cols - i);
        for (int j = 0; j < t; j++) ans += matrix[j][i + j];
    }
    while (*ans.rbegin() == ' ') ans.erase(prev(ans.end()));
    return ans;
}

int main() {
    string encodedText;
    int rows;
    getline(cin, encodedText);
    cin >> rows;
    cout << encodedText << " " << rows << endl;
    cout << decodeCiphertext(encodedText, rows) << endl;
    return 0;
}

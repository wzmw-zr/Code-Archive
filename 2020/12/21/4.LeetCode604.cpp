/*************************************************************************
	> File Name: 4.LeetCode604.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月21日 星期一 13时53分49秒
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

class StringIterator {
public:
    struct Node {
        char c;
        int cnt;
        Node() = default;
        Node(char c, int cnt) : c(c), cnt(cnt) {}
    };

    vector<Node> chars;
    int ind;

    StringIterator(string compressedString) {
        int i = 0;
        ind = 0;
        while (compressedString[i]) {
            char c = compressedString[i++];
            string temp = "";
            while (compressedString[i] && compressedString[i] >= '0' && compressedString[i] <= '9') temp += compressedString[i++];
            chars.push_back(Node(c, stoi(temp)));
        }
    }

    char next() {
        if (ind == chars.size() - 1 && chars[ind].cnt == 0) return ' ';
        char ans;
        if (ind < chars.size() - 1) {
            ans = chars[ind].c;
            if (!(--chars[ind].cnt)) ind++;
        } else {
            ans = chars[ind].c;
            chars[ind].cnt--;
        }
        return ans;
    }

    bool hasNext() {
        if (ind == chars.size() - 1 && chars[ind].cnt == 0) return false;
        return true;
    }
};

int main() {
    return 0;
}

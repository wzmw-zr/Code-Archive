/*************************************************************************
	> File Name: 2.LeetCode1875.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月09日 星期三 09时36分03秒
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

struct BigNumber {
    vector<int> digit;
    BigNumber() = default;
    BigNumber(int n) {
        do {
            digit.push_back(n % 10);
            n /= 10;
        } while (n);
    }
    BigNumber(vector<int> &nums) : digit(nums) {}
    BigNumber(vector<int> &&nums) : digit(nums) {}
    BigNumber(const struct BigNumber &a) : digit(a.digit) {}
    //BigNumber(struct BigNumber &&a) : digit(a.digit) {}

    void operator=(struct BigNumber &a) {
        this->digit = a.digit;
    }

    void operator=(struct BigNumber &&a) {
        this->digit = a.digit;
    }

    void update() {
        for (int i = 0; i < digit.size(); i++) {
            if (digit[i] < 10) continue;
            if (i + 1 == digit.size()) digit.push_back(0);
            digit[i + 1] += digit[i] / 10;
            digit[i] %= 10;
        }
    }

    struct BigNumber operator*(int n) {
        BigNumber temp(this->digit);
        for (int &x : temp.digit) x *= n;
        temp.update();
        return temp;
    }

    bool operator<(const struct BigNumber &a) const {
        if (this->digit.size() > a.digit.size()) return true;
        if (this->digit.size() < a.digit.size()) return false;
        int n = this->digit.size();
        for (int i = n - 1; i >= 0; i--) {
            if (this->digit[i] == a.digit[i]) continue;
            return this->digit[i] > a.digit[i];
        }
        return true;
    }

    string change_to_string() {
        string ans = "";
        for (int x : this->digit) ans += x + '0';
        return ans;
    }
};

int getKthMagicNumber(int k) {
    string ans;
    priority_queue<BigNumber> que;
    unordered_set<string> st;
    que.push(BigNumber(1));
    st.insert("1");
    while (k--) {
        BigNumber temp = que.top();
        ans = temp.change_to_string();
        que.pop();
        BigNumber t_1 = temp * 3;
        BigNumber t_2 = temp * 5;
        BigNumber t_3 = temp * 7;
        string s_1 = t_1.change_to_string();
        string s_2 = t_2.change_to_string();
        string s_3 = t_3.change_to_string();
        if (!st.count(s_1)) {
            st.insert(s_1);
            que.push(t_1);
        }
        if (!st.count(s_2)) {
            st.insert(s_2);
            que.push(t_2);
        }
        if (!st.count(s_3)) {
            st.insert(s_3);
            que.push(t_3);
        }
    }
    reverse(ans.begin(), ans.end());
    return stoi(ans);
}

int main() {
    int k;
    cin >> k;
    cout << getKthMagicNumber(k) << endl;
    return 0;
}

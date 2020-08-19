/*************************************************************************
	> File Name: 7.HZOJ471.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月27日 星期一 21时52分15秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class BigInt{
public:
    BigInt() = default;

    BigInt(string &s) {
        for (int i = s.size() - 1; i >= 0; i--) {
            this->num.push_back(s[i] - '0');
        }
    }

    BigInt(vector<int> a) {
        for (int i = a.size() - 1; i >= 0; i--) {
            this->num.push_back(a[i]);
        }
    }

    void process_digit() {
        for (int i = 0; i < this->num.size(); i++) {
            if (this->num[i] < 10) continue;
            if (i + 1 == this->num.size()) this->num.push_back(0);
            this->num[i + 1] += this->num[i] / 10;
            this->num[i] %= 10;
        }
        while (this->num.size() > 1 && this->num[this->num.size() - 1] == 0) this->num.pop_back();
    }

    BigInt operator*(const BigInt &a) {
        int len = this->num.size() + a.num.size();
        BigInt temp = vector<int>(len, 0);
        for (int i = 0; i < this->num.size(); i++) {
            for (int j = 0; j < a.num.size(); j++) {
                temp.num[i + j] += this->num[i] * a.num[j];
            }
        }
        temp.process_digit();
        return temp;
    }

    vector<int> num;
};

ostream &operator<<(ostream &out, BigInt c) {
    for (int i = c.num.size() - 1; i >= 0; i--) {
        out << c.num[i];
    }
    return out;
}

int main() {
    BigInt a, b;
    string str_a, str_b;
    cin >> str_a >> str_b;
    a = str_a;
    b = str_b;
    cout << a * b << endl;
    return 0;
}

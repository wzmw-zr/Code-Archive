/*************************************************************************
	> File Name: 1.LeetCode537.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月08日 星期四 07时20分36秒
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

struct Plural {
    int real, img;

    Plural(int real, int img) : real(real), img(img) {}

    Plural operator*(Plural &b) {
        int r = this->real * b.real - this->img * b.img;
        int i = this->real * b.img + this->img * b.real;
        return Plural(r, i);
    }
};

string complexNumberMultiply(string a, string b) {
    int plus_a = a.find("+");
    int plus_b = b.find("+");
    Plural p_a(stoi(a.substr(0, plus_a)), stoi(a.substr(plus_a + 1, a.size() - plus_a)));
    Plural p_b(stoi(b.substr(0, plus_b)), stoi(b.substr(plus_b + 1, b.size() - plus_b)));
    Plural ans = p_a * p_b;
    return to_string(ans.real) + "+" + to_string(ans.img) + "i";
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << complexNumberMultiply(a, b) << endl;
    return 0;
}

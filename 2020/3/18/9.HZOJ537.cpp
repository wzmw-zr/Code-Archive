/*************************************************************************
	> File Name: 9.HZOJ537.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月18日 星期三 20时43分49秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int l, c, ans_cnt, fu, yuan, cnt;
char letter[30], ans[30];

int func(int s, int left) {
    if (left == 0) {
        if (yuan >= 1 && fu >= 2) {
            for (int i = 0; i < ans_cnt; i++) cout << ans[i];
            cout << endl;
            cnt++;
            if (cnt == 25000) {
                return -1;
            }
        }
        return 0;
    }
    for (int i = s; i < c; i++) {
        ans[ans_cnt] = letter[i];
        ans_cnt++;
        int f = 0;
        if (letter[i] == 'a' || letter[i] == 'e' || letter[i] == 'o' || letter[i] == 'i' || letter[i] == 'u') {
            yuan++;
            f = 1;
        } else {
            fu++;
        }
        if (func(i + 1, left - 1) == -1) return -1;
        if (f == 1) yuan--;
        else fu--;
        ans_cnt--;
    }
    return 0;
}

int main() {
    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        cin >>letter[i];
    }
    sort(letter, letter + c);
    func(0, l);
    return 0;
}

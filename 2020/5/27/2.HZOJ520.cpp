/*************************************************************************
	> File Name: 2.HZOJ520.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月27日 星期三 18时05分28秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_A 20000000

long a, num[MAX_A + 5];

int main() {
    cin >> a;
    for (int i = 1; i <= 20000000; i++) {
        num[i] = num[i - 1] + i;
    }
    for (int i = a; 1; i++) {
        int l = i + 1, r= 20000000;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (num[mid] - num[i] == num[i - 1]) {
                cout << i << " " << mid << endl;
                return 0;
            }
            if (num[mid] - num[i] > num[i - 1]) r = mid - 1;
            else l = mid + 1;
        }
    }
    return 0;
}

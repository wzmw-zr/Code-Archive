/*************************************************************************
	> File Name: 9.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月15日 星期日 22时35分37秒
 ************************************************************************/

#include<iostream>
using namespace std;


int is_val(int n) {
    if (n % 3 == 0 || n % 5 == 0) return 1;
    return 0;
}

int get_sum(int n) {
    int sum = 0;
    for (int i = 1; i <= 1000; i++) {
        if (i % n == 0) sum += i; 
    }
    return sum;
}

int main() {
    int sum = 0;
    
    return 0;
}

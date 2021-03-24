/*************************************************************************
	> File Name: 3.LeetCode223.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月25日 星期四 00时32分43秒
 ************************************************************************/

#include<iostream>
using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int area_1 = (C - A) * (D - B);
    int area_2 = (G - E) * (H - F);
    int w = max(0, min(C, G) - max(A, E));
    int h = max(0, min(D, H) - max(B, F));
    int inter = w * h;
    return area_1 + area_2 - inter;
}

int main() {
    return 0;
}

/*************************************************************************
	> File Name: 4.LeetCode1634.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月08日 星期五 08时14分10秒
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

struct PolyNode {
    int coefficient, power;
    PolyNode *next;
    PolyNode() : coefficient(0), power(0), next(nullptr) {}
    PolyNode(int x, int y) : coefficient(x), power(y), next(nullptr) {} 
};

PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
    map<int, int> mp;
    PolyNode *temp_1 = poly1, *temp_2 = poly2;
    while (temp_1) {
        mp[temp_1->power] += temp_1->coefficient;
        temp_1 = temp_1->next;
    }
    while (temp_2) {
        mp[temp_2->power] += temp_2->coefficient;
        temp_2 = temp_2->next;
    }
    PolyNode *ans = new PolyNode();
    for (auto &&[power, coefficient] : mp) {
        if (!coefficient) continue;
        PolyNode *temp = new PolyNode(coefficient, power);
        temp->next = ans->next;
        ans->next = temp;
    }
    return ans->next;
}

int main() {
    return 0;
}

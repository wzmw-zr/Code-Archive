/*************************************************************************
	> File Name: 5.LeetCode1634.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月08日 星期五 08时23分30秒
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

PolyNode *reverse_list(PolyNode *head) {
    PolyNode *ans = new PolyNode();
    while (head) {
        PolyNode *temp = head->next;
        head->next = ans->next;
        ans->next = head;
        head = temp;
    }
    PolyNode *res = ans->next;
    delete ans;
    return  res;
}

void show(PolyNode *head) {
    while (head) {
        cout << "[" << head->coefficient << " " << head->power << "], ";
        head = head->next;
    }
    cout << endl;
}

PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
    poly1 = reverse_list(poly1);
    poly2 = reverse_list(poly2);
    PolyNode *head = new PolyNode();
    while (poly1 || poly2) {
        if (!poly1) {
            while (poly2) {
                PolyNode *temp = new PolyNode(poly2->coefficient, poly2->power);
                temp->next = head->next;
                head->next = temp;
                poly2 = poly2->next;
            }
        } else if (!poly2) {
            while (poly1) {
                PolyNode *temp = new PolyNode(poly1->coefficient, poly1->power);
                temp->next = head->next;
                head->next = temp;
                poly1 = poly1->next;
            }
        } else {
            if (poly1->power < poly2->power) {
                PolyNode *temp = new PolyNode(poly1->coefficient, poly1->power);
                temp->next = head->next;
                head->next = temp;
                poly1 = poly1->next;
            } else if (poly1->power > poly2->power) {
                PolyNode *temp = new PolyNode(poly2->coefficient, poly2->power);
                temp->next = head->next;
                head->next = temp;
                poly2 = poly2->next; 
            } else {
                int coefficient = poly1->coefficient + poly2->coefficient;
                if (coefficient) {
                    PolyNode *temp = new PolyNode(coefficient, poly1->power);
                    temp->next = head->next;
                    head->next = temp;
                }
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        }
    }
    return head->next;
}

int main() {
    return 0;
}

/*************************************************************************
	> File Name: 3.LeetCode1041.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月31日 星期三 00时42分06秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

void turn_left(vector<int> &dir) {
    if (dir[0] == 0 && dir[1] == 1) dir[0] = -1, dir[1] = 0;
    else if (dir[0] == -1 && dir[1] == 0) dir[0] = 0, dir[1] = -1;
    else if (dir[0] == 0 && dir[1] == -1) dir[0] = 1, dir[1] = 0;
    else dir[0] = 0, dir[1] = 1;
}

void turn_right(vector<int> &dir) {
    if (dir[0] == 0 && dir[1] == 1) dir[0] = 1, dir[1] = 0;
    else if (dir[0] == 1 && dir[1] == 0) dir[0] = 0, dir[1] = -1;
    else if (dir[0] == 0 && dir[1] == -1) dir[0] = -1, dir[1] = 0;
    else dir[0] = 0, dir[1] = 1;
}

bool isRobotBounded(string instructions) {
    vector<int> dir({0, 1});
    vector<int> offset(2, 0);
    int angle = 0;
    for (char c : instructions) {
        switch (c) {
            case 'G': {
                offset[0] += dir[0], offset[1] += dir[1];
            } break;
            case 'L': {
                turn_left(dir);
                angle += 90;
            } break;
            case 'R': {
                turn_right(dir);
                angle -= 90;
            }
        }
    }
    angle %= 360;
    if (offset[0] == 0 && offset[1] == 0) return true;
    return angle != 0;
}


int main() {
    string instructions;
    cin >> instructions;
    cout << (isRobotBounded(instructions) ? "true" : "false") << endl;
    return 0;
}

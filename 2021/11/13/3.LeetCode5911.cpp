/*************************************************************************
	> File Name: 3.LeetCode5911.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月13日 星期六 22时47分42秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Robot {
public:
    int width;
    int height;
    int x;
    int y;
    vector<vector<int>> dir;
    int ind;
    unordered_map<int, string> num_to_dir;

    Robot(int width, int height) : width(width), height(height), x(0), y(0), ind(0), dir({{1, 0}, {0, 1}, {-1, 0}, {0, -1}}){
        int wzmw_zr_q2 = 1;
        num_to_dir[0] = "East";
        num_to_dir[1] = "North";
        num_to_dir[2] = "West";
        num_to_dir[3] = "South";
    }

    void move(int num) {
        if (num == 0) return ;
        if (dir[ind][0]) {
            if (dir[ind][0] == 1) {
                if (x + num < width) x += num;
                else {
                    num -= (width - 1 - x);
                    num %= 2 * (width + height) - 4;
                    x = width - 1;
                    ind = (ind + 1) % 4;
                    if (num == 0) ind = (ind + 3) % 4;
                    move(num);
                }
            } else {
                if (x - num >= 0) x -= num;
                else {
                    num -= x;
                    num %= 2 * (width + height) - 4;
                    x = 0;
                    ind = (ind + 1) % 4;
                    if (num == 0) ind = (ind + 3) % 4;
                    move(num);
                }
            }
        } else {
            if (dir[ind][1] == 1) {
                if (y + num < height) y += num;
                else {
                    num -= (height - 1 - y);
                    num %= 2 * (width + height) - 4;
                    y = height - 1;
                    ind = (ind + 1) % 4;
                    if (num == 0) ind = (ind + 3) % 4;
                    move(num);
                }
            } else {
                if (y - num >= 0) y -= num;
                else {
                    num -= y;
                    num %= 2 * (width + height) - 4;
                    y = 0;
                    ind = (ind + 1) % 4;
                    if (num == 0) ind = (ind + 3) % 4;
                    move(num);
                }
            }
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        return num_to_dir[ind];
    }
};

int main() {
    return 0;
}

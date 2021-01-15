/*************************************************************************
	> File Name: 1.LeetCode351.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月15日 星期五 23时27分23秒
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

typedef pair<int, int> PII;

struct Direction {
    int x;
    int y;
    string name;
    vector<PII> nodes;
    Direction() = default;
    Direction(int x, int y) : x(x), y(y), name(to_string(x) + "," + to_string(y)) {}
    Direction(int x, int y, vector<PII> nodes) : x(x), y(y), name(to_string(x) + "," + to_string(y)), nodes(nodes) {}
    bool operator==(const struct Direction &a) const {
        return this->x == a.x && this->y == a.y;
    }
};

struct DirectionHash {
    size_t operator()(const Direction &a) const {
        return hash<string>()(a.name);
    }
};

struct DirectionEqual {
    bool operator()(const Direction &a, const Direction &b) const {
        return a.x == b.x && a.y == b.y;
    }
};

void init(unordered_map<Direction, vector<PII>, DirectionHash, DirectionEqual> &dir) {
    Direction d1(1, 0);
    Direction d2(-1, 0);
    Direction d3(0, 1);
    Direction d4(0, -1);
    Direction d5(2, 0);
    Direction d6(-2, 0);
    Direction d7(0, 2);
    Direction d8(0, -2);

    Direction d9(1, 1);
    Direction d10(1, -1);
    Direction d11(-1, 1);
    Direction d12(-1, -1);
    Direction d13(2, 2);
    Direction d14(2, -2);
    Direction d15(-2, 2);
    Direction d16(-2, -2);

    Direction d17(1, 2);
    Direction d18(1, -2);
    Direction d19(-1, 2);
    Direction d20(-1, -2);
    Direction d21(2, 1);
    Direction d22(2, -1);
    Direction d23(-2, 1);
    Direction d34(-2, -1);
}

int numberOfPatterns(int m, int n) {
    unordered_map<Direction, vector<PII>, DirectionHash, DirectionEqual> dir;
    init(dir);
    return 0;
}

int main() {
    return 0;
}

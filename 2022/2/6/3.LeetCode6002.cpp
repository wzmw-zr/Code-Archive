/*************************************************************************
	> File Name: 3.LeetCode6002.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月06日 星期日 10时51分13秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

class Bitset {
public:
    vector<bool> digits_;
    int zero_;
    int one_;
    bool flip_;

    Bitset(int size) : digits_(vector<bool>(size, false)), zero_(size), one_(0), flip_(false) {
    }

    void fix(int idx) {
        if (flip_) {
            if (digits_[idx]) {
                digits_[idx] = false;
                zero_--;
                one_++;
            }
        } else {
            if (!digits_[idx]) {
                digits_[idx] = true;
                zero_--;
                one_++;
            }
        }
    }

    void unfix(int idx) {
        if (flip_) {
            if (!digits_[idx]) {
                digits_[idx] = true;
                zero_++;
                one_--;
            }
        } else {
            if (digits_[idx]) {
                digits_[idx] = false;
                zero_++;
                one_--;
            }
        }
    }

    void flip() {
        flip_ = !flip_;
        swap(one_, zero_);
    }

    bool all() {
        return one_ == digits_.size();
    }

    bool one() {
        return one_ > 0;
    }

    int count() {
        return one_;
    }

    string toString() {
        string str(digits_.size(), '0');
        if (flip_) {
            flip_ = false;
            for (int i = 0; i < digits_.size(); i++) {
                digits_[i] = !digits_[i];
            }
        }
        for (int i = 0; i < digits_.size(); i++) {
            str[i] = digits_[i] ? '1' : '0';
        }
        return str;
    }
};

int main() {
    return 0;
}

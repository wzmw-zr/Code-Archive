/*************************************************************************
	> File Name: 1.LeetCode1603.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月19日 星期五 00时02分36秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class ParkingSystem {
public:
    vector<int> cars;

    ParkingSystem(int big, int medium, int small) : cars({0, big, medium, small}) {}

    bool addCar(int carType) {
        if (!cars[carType]) return false;
        cars[carType]--;
        return true;
    }
};

int main() {
    return 0;;
}

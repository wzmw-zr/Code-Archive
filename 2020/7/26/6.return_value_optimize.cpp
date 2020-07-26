/*************************************************************************
	> File Name: 6.return_value_optimize.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月26日 星期日 20时55分56秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

class People {
public:
    People(string name) {
        cout << "parameter ocnstructor" << endl;
        this->name = name;
    }

    People(const People &a) {
        cout << "copy constructor" << endl;
        this->name = a.name;
    }

private:
    string name;
};

People func() {
    People temp_a("zhaorui");
    return temp_a;
}

int main() {
    People a = func();
    return 0;
}

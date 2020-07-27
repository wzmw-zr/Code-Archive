/*************************************************************************
	> File Name: 4.operator.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月27日 星期一 18时29分49秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

namespace haizei {
    class istream {
    public:
        istream &operator>>(int &n) {
            std::cin >> n;
            return *this;
        }

    private:
    };

    class ostream {
    public:
        ostream &operator<<(int &n) {
            std::cout << n;
            return *this;
        }
        
        ostream &operator<<(const char *msg) {
            std::cout << msg;
            return *this;
        }

    private:
    };

    istream cin;
    ostream cout;
};

haizei::ostream &operator<<(haizei::ostream &out, double &z) {
    std::cout << z;
    return out;
}

std::ostream &operator+(std::ostream &out, const int &n) {
    out << n;
    return out;
}


int main() {
    int n, m;
    haizei::cin >> n >> m;
    haizei::cout << n << " " << m << "\n";
    double k = 5.6;
    haizei::cout << k << "\n";
    (((((std::cout + 8) << " ") + 9) << " ") + 10) << std::endl;
    return 0;
}

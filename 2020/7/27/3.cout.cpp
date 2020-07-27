/*************************************************************************
	> File Name: 3.cout.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月27日 星期一 16时44分01秒
 ************************************************************************/

#include<iostream>

namespace haizei {
    class ostream {
    public:
        ostream &operator<<(int x) {
            printf("%d", x);
            return *this;
        }
        ostream &operator<<(const std::string &str) {
            printf("%s", str.c_str());
            return *this;
        }
        ostream &operator<<(const char &ch) {
            printf("%c", ch);
            return *this;
        }
    };
    char endl = '\n';
    ostream cout;
};

int main() {
    haizei::cout << "hello world" << haizei::endl;
    return 0;
}

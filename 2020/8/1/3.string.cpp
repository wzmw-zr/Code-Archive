/*************************************************************************
	> File Name: 3.string.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月01日 星期六 14时32分59秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

namespace haizei {
    class string {
    public:
        string() {
            this->__buff_size = 10;
            this->buff = new char[this->__buff_size]{'\0'};
            this->__length = 0;
        }

        string(const char *str) {
            this->__buff_size = strlen(str) + 1;
            this->buff = new char[this->__buff_size]{'\0'};
            strcpy(this->buff, str);
            this->__length = this->__buff_size - 1;
        }

        char &at(int ind) {
            if (ind < 0 || ind >= __length) {
                cout << "String Error : out of range" << endl;
                return __end;
            }
            return buff[ind];
        }

        char &operator[](int ind) {
            return buff[ind];
        }

        const char *c_str() const {
            return this->buff;
        }

        string operator+(const string &s) {
            int size = this->__length + s.__length + 1;
            char *temp = new char[size]{'\0'};
            strcpy(temp, this->buff);
            strcpy(temp, s.buff);
            return temp;
        }

        int size() {
            return this->__length;
        }

    private:
        int __length, __buff_size;
        char *buff;
        char __end;
    };
};

ostream &operator<<(ostream &out, const haizei::string &s) {
    out << s.c_str() << endl; 
    return out;
}

int main() {
    haizei::string s1 = "hello world", s2 = ", haizei", s3 = "harbin.";
    cout << s1 << endl;
    s1[3] = '6';
    cout << s1 << endl;
    cout << s1 + s2 + s3 << endl;
    for (int i = 0; i < s1.size(); i++) cout << s1[i];
    cout << endl;
    return 0;
}

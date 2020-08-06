/*************************************************************************
	> File Name: 1.move_constructor.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月06日 星期四 09时41分45秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

namespace haizei {
    class string {
    public:
        string() {
            cout << "string : default constructor, " << this << endl;
            this->__buff_size = 10;
            this->buff = new char[this->__buff_size]{'\0'};
            this->__length = 0;
        }

        string(const char *str) {
            cout << "string : const char constructor, " << this << endl;
            this->__buff_size = strlen(str) + 1;
            this->buff = new char[this->__buff_size]{'\0'};
            strcpy(this->buff, str);
            this->__length = this->__buff_size - 1;
        }

        string(haizei::string &&str) : __length(str.__length), __end(str.__end), __buff_size(str.__buff_size) {
            cout << "move constructor" << endl;
            this->buff = str.buff;
            str.buff = nullptr;
        }
        
        string(const string &str) : __length(str.__length), __end(str.__end), __buff_size(str.__buff_size) {
            cout << "copy constructor" << endl;
            this->buff = new char[this->__buff_size];
            strcpy(this->buff, str.buff);
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
            cout << "add operation" << endl;
            int size = this->__length + s.__length + 1;
            char *temp = new char[size]{'\0'};
            strcpy(temp, this->buff);
            strcpy(temp + strlen(temp), s.buff);
            return temp;
        }

        int size() {
            cout << "size, " << this << endl;
            return this->__length;
        }

        virtual ~string() {
            cout << "destructor, " << this << endl;
            delete[] this->buff;
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
    cout << "=========s4=========" << endl;
    haizei::string s4 = s1 + s2 + s3;
    haizei::string s5 = s4;
    cout << s4 << endl;
    cout << s5 << endl;
    s4[3] = '=';
    cout << s4 << endl;
    cout << s5 << endl;
    cout << "=========s4=========" << endl;

    haizei::string s6 = haizei::string("welcome!");
    cout << s6 << endl;
    return 0;
}

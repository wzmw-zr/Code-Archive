/*************************************************************************
	> File Name: string.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月29日 星期三 13时58分33秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

namespace haizei {
    class string {
    public:
        string() : __size(0), __len(24) {
            this->__p = new char[this->__len]();
        }

        string(const char *msg) {
            this->__size = strlen(msg);
            this->__len = max((int) strlen(msg) * 2, 24);
            this->__p = new char[this->__len]();
            for (int i = 0; i < this->__size; i++) {
                this->__p[i] = msg[i];
            }
        }

        int size() const {
            return this->__size;
        }

        char &operator[](int ind) {
            if (ind >= this->__size) return this->__p[this->__size];
            return this->__p[ind];
        }

        char operator[](int ind) const {
            if (ind >= this->__size) return 0;
            return this->__p[ind];
        }

        void operator=(const string &a) {
            char *temp = new char[2 * a.size()]();
            for (int i = 0; i < a.size(); i++) temp[i] = a[i];
            this->__size = a.size();
            this->__len = 2 * a.size();
            delete[] this->__p;
            this->__p = temp;
        }

        void operator+=(const string &a) {
            if (a.size() + this->__size < this->__len) {
                for (int i = 0; i < a.size(); i++) {
                    this->__p[this->__size++] = a[i];
                }
            } else {
                char *temp = new char[2 * (a.size() + this->__size)]();
                strncat(temp, this->__p, strlen(this->__p));
                int t_len = this->__size;
                for (int i = 0; i < a.size(); i++) temp[t_len + i] = a[i];
                this->__size += a.size();
                this->__len = 2 * this->__size;
                delete[] this->__p;
                this->__p = temp;
            }
        }

        void operator+=(char a) {
            if (this->__size + 1 < this->__len) {
                this->__p[this->__size++] = a;
            } else {
                char *temp = new char[2 * this->__len]();
                strncat(temp, this->__p, strlen(this->__p));
                temp[this->__size++] = a;
                this->__len *= 2;
                delete[] this->__p;
                this->__p = temp;
            }
        }

        void clear() {
            this->__size = 0;
            memset(this->__p, 0, sizeof(this->__p));
        }

        void inc() {
            this->__size++;
            if (this->__size == this->__len) {
                this->__size *= 2;
                this->__len = 2 * this->__size;
                char *temp = new char[this->__len]();
                memcpy(temp, this->__p, strlen(this->__p));
                delete[] this->__p;
                this->__p = temp;
            }
        }

        ~string() {
            delete[] this->__p;
        } 

    private:
        char *__p;
        int __size;
        int __len;
    };
};

ostream &operator<<(ostream &out, haizei::string &a) {
    for (int i = 0; i < a.size(); i++) out << a[i];
    return out;
}

istream &operator>>(istream &in, haizei::string &a) {
    char ch;
    a.clear();
    while (ch = getchar()) {
        if (ch == ' ' || ch == '\n' || ch == '\t') break;
        a.inc();
        a[a.size() - 1] = ch;
    }
    return in;
}


int main() {
    haizei::string str1, str2;
    cin >> str1 >> str2;
    cout << str1 << " " << str2 << endl;
    #if 0
    cout << str1 << " " << str2 << endl;
    str1 += str2;
    cout << str1 << endl;
    #endif
    //cout << str1 << " " << str2 << endl;
    return 0;
}

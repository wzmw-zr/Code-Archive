/*************************************************************************
	> File Name: 3.shared_ptr.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月20日 星期四 15时31分08秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<memory>
using namespace std;

namespace haizei {
    template<typename T>
    class shared_ptr {
    public : 
        shared_ptr() : ptr(nullptr), pcnt(nullptr) {}
        shared_ptr(T *ptr) : ptr(ptr), pcnt(new int(1)) {}
        shared_ptr(const shared_ptr<T> &p) : ptr(p.ptr), pcnt(p.pcnt) {
            *pcnt += 1;
        }
        T *operator->() { return this->ptr; }
        T &operator*() { return *(this->ptr); }
        int use_count() { return (pcnt ? *pcnt : 0); }
        shared_ptr<T> &operator=(shared_ptr<T> &p) {
            this->use_count_des();
            this->ptr = p.ptr;
            this->pcnt = p.pcnt;
            *(this->pcnt) += 1;
            return *this;
        }
        ~shared_ptr() {
            this->use_count_des();
        }
    private : 
        void use_count_des() {
            if (*pcnt) {
                *pcnt -= 1;
                if (*pcnt == 0) {
                    delete pcnt;
                    delete ptr;
                }
            }
        }
        T *ptr;
        int *pcnt;
    };

}

class A {
public:
    int x, y;
    A() : x(123), y(456) {
        cout << this << " constructor" << endl;
    }
    ~A() {
        cout << this << " destructor" << endl;
    }
    haizei::shared_ptr<A> p;
};


int main() {
    haizei::shared_ptr<A> p(new A()), q = p;
    haizei::shared_ptr<A> k(new A());
    cout << p->x << " " << p->y << endl;
    cout << q->x << " " << q->y << endl;
    cout << p.use_count() << endl;
    q = k;
    cout << p.use_count() << endl;
    p->p = k;
    k->p = p;
    return 0;
}

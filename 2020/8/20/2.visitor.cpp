/*************************************************************************
    > File Name: 2.visitor.cpp
    > Author:赵睿 
    > Mail: 1767153298@qq.com
    > Created Time: 2020年08月20日 星期四 10时35分59秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<algorithm>
using namespace std;

class Cat;
class Dog;
class Mouse;
class Bat;

class Animal {
public:
    class IVisitor {
    public : 
        virtual void count_sub_class_obj(Cat *) = 0;
        virtual void count_sub_class_obj(Dog *) = 0;
        virtual void count_sub_class_obj(Mouse *) = 0;
        virtual void count_sub_class_obj(Bat *) = 0;
        virtual void visit(Cat *) = 0;
        virtual void visit(Dog *) = 0;
        virtual void visit(Mouse *) = 0;
        virtual void visit(Bat *) = 0;
    };
    virtual void Accept(IVisitor *) = 0;
    virtual ~Animal() {};
};

class AnimalCout : public Animal::IVisitor {
public:
    static int sub_class_obj_cnt;
    virtual void count_sub_class_obj(Cat *obj) override {
        sub_class_obj_cnt++;
    }
    virtual void count_sub_class_obj(Dog *obj) override {
        sub_class_obj_cnt++;
    }
    virtual void count_sub_class_obj(Mouse *obj) override {
        sub_class_obj_cnt++;
    }
    virtual void count_sub_class_obj(Bat *obj) override {
        sub_class_obj_cnt++;
    }

    virtual void visit(Cat *obj) override {
        cout << "this is a cat" << endl;
    }
    virtual void visit(Dog *obj) override {
        cout << "this is a dog" << endl;
    }
    virtual void visit(Mouse *obj) override {
        cout << "this is a mouse" << endl;
    }
    virtual void visit(Bat *obj) override {
        cout << "this is a bat" << endl;
    }
};

int AnimalCout::sub_class_obj_cnt = 0;

class Cat : public Animal {
public : 
    Cat() {}
    Cat(IVisitor *vis) {
        vis->count_sub_class_obj(this);
    }
    virtual void Accept(IVisitor *vis) override {
        vis->visit(this);
    }
};

class Dog : public Animal {
public:
    Dog() {}
    Dog(IVisitor *vis) {
        vis->count_sub_class_obj(this);
    }
    virtual void Accept(IVisitor *vis) override {
        vis->visit(this);
    }
};

class Mouse : public Animal {
public:
    Mouse() {}
    Mouse(IVisitor *vis) {
        vis->count_sub_class_obj(this);
    }
    virtual void Accept(IVisitor *vis) override {
        vis->visit(this);
    }
};

class Bat : public Animal {
public:
    Bat() {}
    Bat(IVisitor *vis) {
        vis->count_sub_class_obj(this);
    }
    virtual void Accept(IVisitor *vis) override {
        vis->visit(this);
    } 
};



int main() {
    srand(time(0));
    Animal *arr[10];
    AnimalCout vis;
    for (int i = 0; i < 10; i++) {
        switch (rand() % 4) {
            case 0 : arr[i] = new Cat(&vis); break;
            case 1 : arr[i] = new Dog(&vis); break;
            case 2 : arr[i] = new Mouse(&vis); break;
            case 3 : arr[i] = new Bat(&vis); break;
        }
    }
    for (int i = 0; i < 10; i++) {
        arr[i]->Accept(&vis);
    }
    cout << vis.sub_class_obj_cnt << endl;
    return 0;
}

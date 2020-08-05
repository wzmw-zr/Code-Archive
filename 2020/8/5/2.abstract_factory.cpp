/*************************************************************************
	> File Name: 2.abstract_factory.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月05日 星期三 09时03分03秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<ctime>
using namespace std;

class ICar {
public:
    class IFactory {
    public:
        virtual ICar *create() = 0;
    };

    class IHandler {
    public:
        IHandler() : next(nullptr) {}
        virtual bool is_vaild(int x) = 0;
        virtual ICar *do_it() = 0;
        IHandler *next;
    };
    virtual void run() = 0;
protected:
    ICar() {}
    ~ICar() {}
};

class BenzCar : public ICar {
    BenzCar() {}
public:
    class Factory : public ICar::IFactory, public ICar::IHandler {
    public:
        virtual ICar *create() override {
            return new BenzCar();
        }

        virtual bool is_vaild(int x) override {
            return x == 0;
        }
        virtual ICar *do_it() override {
            return this->create();
        }
    };

    void run() override {
        cout << "Benz run" << endl;
    }
};

class BmwCar : public ICar {
    BmwCar() {}
public:
    class Factory : public ICar::IFactory, public ICar::IHandler {
    public:
        virtual ICar *create() override {
            return new BmwCar();
        }
        
        virtual bool is_vaild(int x) override {
            return x == 1;
        }

        virtual ICar *do_it() override {
            return this->create();
        }
    };

    void run() override {
        cout << "Bmw run" << endl;
    }
};

class AudiCar : public ICar {
    AudiCar() {}
public:
    class Factory : public ICar::IFactory, public ICar::IHandler {
    public:
        virtual ICar *create() override {
            return new AudiCar();
        }

        virtual bool is_vaild(int x) override {
            return x == 2; 
        }

        virtual ICar *do_it() override {
            return this->create();
        }
    };

    void run() override {
        cout << "Audi cun" << endl;
    }
};

class ChainMaster {
public:
    static ICar::IHandler *getInstance() {
        if (head == nullptr) {
            buildChain();
        }
        return head;
    }
private:
    static ICar::IHandler *head;
    static void buildChain() {
        head = new BenzCar::Factory();
        head->next = new BmwCar::Factory();
        head->next->next = new AudiCar::Factory();
    }
};

ICar::IHandler *ChainMaster::head = nullptr;

int main() {
    srand(time(0));
    ICar *cars[10];
    for (int i = 0; i < 10; i++) {
        int req = rand() % 3;
        for (auto p = ChainMaster::getInstance(); p; p = p->next) {
            if (p->is_vaild(req)) {
                cars[i] = p->do_it();   
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        cars[i]->run();
    }
    return 0;
}

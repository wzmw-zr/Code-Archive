/*************************************************************************
	> File Name: 3.singleton.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月04日 星期二 21时57分42秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<mutex>
using namespace std;

class HttpServer {
public:
    static HttpServer *getInstance() {
        if (instance == nullptr) {
            instance = new HttpServer();
        }
        return instance;
    }

private:
    static HttpServer *instance;
    HttpServer() {};
    HttpServer(const HttpServer &) = delete;
    ~HttpServer() = delete;
};

HttpServer *HttpServer::instance = nullptr;

int main() {
    HttpServer *t1 = HttpServer::getInstance();
    HttpServer *t2 = HttpServer::getInstance();
    cout << t1 << " " << t2 << endl;
    return 0;
}

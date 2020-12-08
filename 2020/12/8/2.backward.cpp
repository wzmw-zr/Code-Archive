/*************************************************************************
	> File Name: 2.backward.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月08日 星期二 10时37分57秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<algorithm>
using namespace std;

struct Op {
    virtual double grad() = 0;
};

struct Pow : public Op {
    double base;
    double power;

    Pow() = default;
    Pow(double base, double power) : base(base), power(power) {}

    double grad() override {
        return power * pow(base, power - 1);
    }
};

struct Exp : public Op {
    double power;
    Exp() = default;
    Exp(double power) : power(power) {}

    double grad() override {
        return exp(power);
    }
};

struct Add : public Op {
    double left;
    double right;
    Add() = default;
    Add(double left, double right) : left(left), right(right) {}

    double grad() override {
        return 1;
    }
};

struct Mul : public Op {
    double var;
    double times;
    Mul() = default;
    Mul(double var, double times) : var(var), times(times) {}

    double grad() override {
        return times;
    }
};

struct Single : public Op {
    double grad() override {
        return 1;
    }
};

struct Node {
    double val;
    double grad;
    Op *op;
    vector<Node *> forward;
    vector<Node *> backward;
    Node(double val) : val(val), grad(0.0), op(nullptr) {}
    Node(double val, Op *op) : val(val), grad(0.0), op(op) {} 
};

Node *my_pow(Node *pre, double power) {
    Op *op = new Pow(pre->val, power);
    Node *next = new Node(pow(pre->val, power), op);
    pre->forward.push_back(next);
    next->backward.push_back(pre);
    return next;
}

Node *my_exp(Node *pre) {
    Op *op = new Exp(pre->val);
    Node *next = new Node(exp(pre->val), op);
    pre->forward.push_back(next);
    next->backward.push_back(pre);
    return next;
}

Node *my_add(Node *left, Node *right) {
    Op *op = new Add(left->val, right->val);
    Node *next = new Node(left->val + right->val, op);
    left->forward.push_back(next);
    right->forward.push_back(next);
    next->backward.push_back(left);
    next->backward.push_back(right);
    return next;
}

Node *my_mul(Node *pre, double times) {
    Op *op = new Mul(pre->val, times);
    Node *next = new Node(pre->val * times, op);
    pre->forward.push_back(next);
    next->backward.push_back(pre);
    return next;
}

void dfs(Node *node, unordered_map<Node *, int> &mp) {
    if (!node) return ;
    mp[node] = node->forward.size();
    for (Node *x : node->backward) {
        if (mp.count(x)) continue;
        dfs(x, mp);
    }
}

void backward(Node *node) {
    queue<Node *> que;
    que.push(node);
    unordered_map<Node *, int> mp;
    dfs(node, mp);
    //for (auto &x : mp) cout << x.first->val << " " << x.second << endl;
    //cout << endl;
    node->grad = node->op->grad();
    while (!que.empty()) {
        Node *temp = que.front();
        //cout << temp->grad << endl;
        que.pop();
        for (Node *x : temp->backward) {
            x->grad += x->op->grad() * temp->grad;
            if (!(--mp[x])) que.push(x);
            //cout << x->val << " " << mp[x] << endl;
        }
    }
}

int main() {
    Node *x = new Node(1, new Single());
    Node *y = my_pow(x, 2);
    Node *z = my_mul(x, 3);
    Node *a = my_add(y, z);
    Node *b = my_exp(a);
    Node *c = my_add(b, z);
    //cout << x << " " << y->backward[0] << endl;
    //cout << x->val << " " << y->val << " " << z->val << " " << a->val << " " << b->val << " " << c->val << endl;
    backward(c);
    cout << x->grad << endl;
    return 0;
}

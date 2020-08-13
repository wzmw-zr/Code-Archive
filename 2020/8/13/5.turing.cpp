/*************************************************************************
	> File Name: 5.turing.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月13日 星期四 14时28分34秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

template<int n>
struct IsEven {
    static constexpr int r = !(n % 2);
};


template<int n>
struct Add {
    static constexpr int r = n + Add<n - 1>::r;
};

template<>
struct Add<1> {
    static constexpr int r = 1;
};

template<int n>
struct Factorial {
    static constexpr int r = n * Factorial<n - 1>::r;   
};

template<>
struct Factorial<0> {
    static constexpr int r = 1;
};

template<int n, int div>
struct Remain {
    static constexpr bool r = (n % div) ? (Remain<n, div - 1>::r) : 0;
};

template<int n>
struct Remain<n, 2> {
    static constexpr bool r = ((n % 2) != 0);
};

template<int n>
struct Remain<n, 1> {
    static constexpr bool r = 1;
};

template<int n>
struct IsPrime {
    static constexpr bool r = Remain<n, (int) sqrt(n)>::r;
};

template<int n>
struct PrimeSum {
    static constexpr int r = (IsPrime<n>::r ? n : 0) + PrimeSum<n - 1>::r;
};

template<>
struct PrimeSum<2> {
    static constexpr int r = 2;
};

template<int n>
void PrintPrime() {
    PrintPrime<n - 1>();
    IsPrime<n>::r && (cout << n << " ");
};

template<>
void PrintPrime<2>() {
    cout << 2 << " ";
};

int main() {
    cout << IsEven<123>::r << endl;
    cout << IsEven<124>::r << endl;
    cout << Factorial<5>::r << endl;
    cout << Factorial<10>::r << endl;
    cout << IsPrime<9973>::r << endl;
    cout << IsPrime<87>::r << endl;
    cout << IsPrime<1537>::r << endl;
    cout << IsPrime<65>::r << endl;
    cout << PrimeSum<10>::r << endl;
    PrintPrime<100>();
    cout << endl;
    return 0;
}

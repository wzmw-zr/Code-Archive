/*************************************************************************
	> File Name: 7.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月07日 星期二 20时11分46秒
 ************************************************************************/

#include<iostream>
#include<assert.h>
using namespace std;

float Q_rsqrt( float number )
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y   = number;
	i   = * ( long * ) &y;   // evil floating point bit level hacking
	i   = 0x5f3759df - ( i >> 1 ); // what the fuck?
	y   = * ( float * ) &i;
	y   = y * ( threehalfs - ( x2 * y * y ) ); // 1st iteration
	// y   = y * ( threehalfs - ( x2 * y * y ) ); // 2nd iteration, this can be removed

	return y;
} 

int main() {
    float x;
    cin >> x;
    cout << Q_rsqrt(x) << endl;
}

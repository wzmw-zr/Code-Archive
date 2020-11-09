/*************************************************************************
	> File Name: transfer_time.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月26日 星期二 23时50分45秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main () {
    int t;
    cin >> t;
    if (t < 43200) {
        int h = t / 3600;
        int m = (t % 3600) / 60;
        int s =  t % 60;
        if (h >= 10 && m >= 10 && s >= 10) {
            cout << h << ":" << m << ":" << s << " am";
            return 0;
        }
        if (h >= 10 && m >= 10 && s < 10) { 
            cout << h << ":" << m << ":" << 0 <<  s << " am";
            return 0;
        }
        if (h >= 10 && m < 10 && s >= 10) {  
           cout << h << ":" <<  0 << m << ":" << s << " am";
           return 0; 
        }
        if (h >= 10 && m < 10 && s < 10) {
            cout << h << ":" << 0 << m << ":" << 0 << s <<" am";
            return 0;
        } 
        if (h < 10 && m >= 10 && s >= 10) {
            cout << 0 << h << ":" << m << ":" << s << " am";
            return 0;
        }
        if (h < 10 && m >= 10 && s < 10) { 
            cout << 0 << h << ":" << m << ":" << 0 <<  s << " am";
            return 0;
        }
        if (h < 10 && m < 10 && s >= 10) {  
           cout << 0 << h << ":" <<  0 << m << ":" << s << " am";
           return 0; 
        }
        if (h < 10 && m < 10 && s < 10) {
            cout << 0 << h << ":" << 0 << m << ":" << 0 << s <<" am";
            return 0;
        }
    }
    
    if (t >= 43200 && t < 46800) {  
        int h = t / 3600; 
        int m = (t % 3600) / 60;
        int s =  t % 60;
        if (m >= 10 && s >= 10) {
            cout << h << ":" << m << ":" << s << " midnoon";
            return 0;
        }
        if (m >= 10 && s < 10) { 
            cout << h << ":" << m << ":" << 0 <<  s << " midnoon";
            return 0;
        }
        if (m < 10 && s >= 10) {  
           cout << h << ":" <<  0 << m << ":" << s << " midnoon";
           return 0; 
        }
        if (m < 10 && s < 10) {
            cout << h << ":" << 0 << m << ":" << 0 << s <<" midnoon";
            return 0;
        }
    }

    int h = (t / 3600) % 12;
    int m = (t % 3600) / 60;
    int s =  t % 60;
    if (h >= 10 && m >= 10 && s >= 10) {
        cout << h << ":" << m << ":" << s << " pm";
        return 0;
    }
    if (h >= 10 && m >= 10 && s < 10) { 
        cout << h << ":" << m << ":" << 0 <<  s << " pm";
        return 0;
    }
    if (h >= 10 && m < 10 && s >= 10) {  
        cout << h << ":" <<  0 << m << ":" << s << " pm";
        return 0; 
    }
    if (h >= 10 && m < 10 && s < 10) {
        cout << h << ":" << 0 << m << ":" << 0 << s <<" pm";
        return 0;
    } 
    if (h < 10 && m >= 10 && s >= 10) {
        cout << 0 << h << ":" << m << ":" << s << " pm";
        return 0;
    }
    if (h < 10 && m >= 10 && s < 10) { 
        cout << 0 << h << ":" << m << ":" << 0 <<  s << " pm";
        return 0;
    }
    if (h < 10 && m < 10 && s >= 10) {  
        cout << 0 << h << ":" <<  0 << m << ":" << s << " pm";
        return 0; 
    }
    if (h < 10 && m < 10 && s < 10) {
        cout << 0 << h << ":" << 0 << m << ":" << 0 << s <<" pm";
        return 0;
    }
}

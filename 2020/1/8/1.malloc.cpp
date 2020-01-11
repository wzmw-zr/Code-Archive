/*************************************************************************
	> File Name: 1.malloc.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月08日 星期三 09时26分41秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#include<ctime>
using namespace std;

char *find_my_mood() {
    char *my_mood;
    my_mood = (char *) malloc(sizeof(char) * 10);
    sprintf(my_mood, "%s", "happy");
    return my_mood;
}

int main() {
    char *mood;
    mood = find_my_mood();
    printf("I am currently %s\n", mood);
    free(mood);
    return 0;
}

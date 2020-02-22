/*************************************************************************
	> File Name: 3.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月26日 星期日 23时06分05秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
int main(){
    char * argv[ ]={"ls","-al","/etc/passwd",(char *)0};
    char * envp[ ]={"PATH=/bin",0};
    execve("/bin/ls",argv,envp);
    return 0;
}

# C语言字符串问题一些典型例子

## 一、二维字符数组输入字符串的问题(一行表示一个字符串)

### (一)字符串中不含有空格

```c
#include <stdio.h>
#include <string.h>

int main () {
    char name_list[10][20];
    char name[20];
    char c;
    //不包含空格的二维字符数组——每一行表示一个字符串
    for (int i = 0; i < 10; i++) {
        scanf("%s", name_list[i]);
    }

    //类似于冒泡排序，表示多个字符串的二维字符数组中可以使用string[i]这种方式表示一行的字符串
    //字符串之间不能直接赋值，而是要通过strcpy这种方式进行赋值
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= 9 - i; j++) {
            if (strcmp(name_list[j], name_list[j + 1]) > 0) {
                strcpy(name, name_list[j]);
                strcpy(name_list[j], name_list[j + 1]);
                strcpy(name_list[j + 1], name);
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("%s\n", name_list[i]);
    }
    return 0;
}
```

事实上，二维字符数组的每一行`string[i]`都可以表示一个字符串，并且这个字符串可以被赋值(**通过`strcpy`的方式**)，简而言之，二维字符串数组`char string[x] [y]`可以通过`string[i]`的方式使用某一行的字符串，并且本身可以被赋值修改。



### (二)字符串中含有空格的情况(以及不知道读入有多少行的情况，处理输入结束)

```c
#include <stdio.h>
#include <string.h>


int main () {
    int n;
    scanf("%d\n", &n);
    char new_string[101]; //这里如果不写\n的话，光标位置实际上就还在\n以前
    char string[n][101]; //为啥是101呢？100字符串+一格=个结尾字符
    char c;
    int i, j;
    i = j = 0;
    while (scanf("%c", &c) != EOF) {
        if (c != '\n') {
            string[i][j] = c;
            j++;
        }else {
            string[i][j] = '\0';
            j = 0;
            i++;//检测到行末的\n,数组就换行读入下一个名字
        }
    }
    strcpy(new_string, string[0]);
    for (int i = 1; i < n; i++) {
        if (strlen(string[i]) > strlen(new_string)) {
            strcpy(new_string, string[i]);
        }
    }
    printf("%s", new_string);
    return 0;
}
```

这里的核心代码就是

```c
    while (scanf("%c", &c) != EOF) {//处理输入结束
        if (c != '\n') {
            string[i][j] = c;
            j++;
        }else {
            string[i][j] = '\0';//字符串最后一位都默认是'\0'
            j = 0;
            i++;//检测到行末的\n,数组就换行读入下一个名字
        }
    }
```


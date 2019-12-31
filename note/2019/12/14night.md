# 2019.12.14

## 一、结构体

### 1.结构体的对齐

计算机中会以结构体中变量类型最大的一个值作为对齐的标准，比方说

```c
struct person {
	char name[20];
    int age;
    char gender;
    float height;
};
// 是根据最大的类型来确定其对齐方式，而不是根据字段大小
```

中，类型最大的是`int`，则对齐标准为4字节，`char name[20]`以4字节对齐，占5个。

> 可以使用宏`program`来改变对其方式，`program`可以定义为2的自然数次幂的大小

**相同类型字段定义时要放在一起。**



### 2.结构体元素的访问

#### (1)直接访问

```c
struct node {
    int x;
};
struct node a;
a.x = 1; //通过.下标来访问
```



#### (2)间接访问

```c
struct node {
    int x;
};
struct node *a;
a->x = 1; //通过->下标来访问
```



## 二、共用体(联合体)

```c
union register {
    struct {
        char b1, b3, b3, b4;
    } bytes;
    int number;
}
```

共用体具有一片公用的取存储空间，当一个变量的值改变，其他变量的值也要改变。

共用体取最大的数据对象类型的大小作为开辟空间的标准。

### 1.大端、小端

大端机：高位存储在低地址，低位存储在高地址

小端机：高位存储在高地址，低位存储在低地址

> 取地址取的是较小的地址

```c
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;


union IP {
    unsigned int num;
    struct {
        unsigned char a1;
        unsigned char a2;
        unsigned char a3;
        unsigned char a4;
    } ip;
};

int is_little() {
    int x = 1;
    return ((char *)(&x))[0];
}

int main () {
    union IP p;
    char str[25];
    unsigned int arr[4];
    /*while (~scanf("%s", str)) {
        sscanf(str, "%d.%d.%d.%d", arr, arr + 1, arr + 2, arr + 3);
        p.ip.a1 = arr[0];
        p.ip.a2 = arr[1];
        p.ip.a3 = arr[2];
        p.ip.a4 = arr[3];
        printf("%d\n", p.num);
    }
*/
    printf("%d\n", is_little());
    return 0;
}
```



## 三、指针

内存当中的地址是按照字节来划分的，而变量的指针指向的是最低位的地址。

> 指针变量也是变量。
>
> 指针变量前的类型是作为读取、操作指针所对应变量的标准。
>
> 指针变量在64位系统下为8字节，32位系统下为4字节

### (1)间接访问

```c
int *p = &a;
p->filed = (*p).filed = a.filed; // ->:通过指针变量进行间接访问
```



```c
(*p + 1)->x;
((*p) + 1).x;
```



### (2)函数指针

```c
int *add(int, int); //函数声明，返回值为int *
int (*add)(int, int); // 函数指针
```



### (3)`typedef `的用法

`typedef `用于给变量类型重命名。

```c
typedef long long ll;
typedef char * pchar;

typedef struct __node {
    int x, y;
} Node, *PNode; // *PNode 是该结构体的指针重命名


int (*add)(int, int);// 函数变量
typedef int (*add)(int, int); // 函数类型
```



### (4)`main`函数的参数

```c
int main ();
int main (int argc, char *argv[]);
int main (int argc, char *argv[], char **env);
//第一个argc表示参数个数，第二个*argv[]表示传入的参数，第三个**env表示操作系统环境变量
// 一般情况下main函数由操作系统调用
```





### (5)指针的应用

```c
#include<iostream>
using namespace std;

int main () {
    int num1=  0x616263;
    int num2=  0x61626364;
    printf("%s\n", (char *) (&num1)); // 将num1以字符类型读取
    printf("%s\n", (char *) (&num2));
    printf("%s\n", (char *) (&num2 + 1));
    return 0;
}
```

输出为

```shell
cba
dcba #这是因为我们的电脑的栈中num2在num1后面
cba
```


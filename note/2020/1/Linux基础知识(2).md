# Linux基础知识(2)

> ```shell
> sudo ln -s /usr/bin/python3 usr/bin/python
> ```
>
> 这里i实际上相当于实现了一个软链接，让`python`链接到`python3`
>
> ```shell
> sudo !! 
> #这条命令的功能是将上一条命令重新执行一遍，加上sudo命令
> ```
>
> `Errno 13`是权限错误

## 一、进程的创建—`fork()`

所有进程是复制产生的，这就是`fork()`的作用，但是这样父进程和子进程的功能一样，所以，如果需要子进程执行新的功能，就需要使用`execve`系列的函数来进行进程的变身。

进程的创建是一个复制的过程，这种复制是一种"写复制(写copy)"。

"写复制(写copy)"：在创建完子进程之后如果变量数据没有发生改变，那么子进程还是使用的父进程的地址空间。但是，当数据发生变化，子进程就会进行对父进程地址空间的拷贝。

子进程创建结束，那么父进程就会等待子进程结束，也就是`wait()`。

如果创建了子进程之后没有做任何该改变，那么子进程就相当于继续执行父进程。(因为子进程，父进程此时是共享地址空间与代码段的)。

而子进程可以通过`exec`类的函数来进行变身，能够执行其他的函数。

> ```c++
> void getpid(void);
> // 功能： 获取当前进程的进程号
> void getppid(void);
> // 功能： 获取当前进程的父进程的进程号
> ```

> 孤儿进程：如果父进程先执行完，但是子进程没有执行结束，此时的子进程就是孤儿进程，所有的孤儿进程都由1号进程接收。==通常这种情况是父进程没有等待子进程，所以，我们可以使用 `wait()`函数来使父进程来等待子进程。==

```c++
void wait(int *stat_loc);
// wait()会挂起父进程，直至子进程结束或者一个信号到达，stat_loc区域将包含子进程的退出的状态信息。
```



## 二、进程的变身—`exec()`家族

`exec()`家族的函数是用新的进程的镜像来替换当前的进程镜像。

`exec()`家族的函数只有当出错的时候才会返回，这个返回值是-1,并且`errno`会被设置好来展示这个错误。

`exec()`家族的函数在被调用之后，父进程剩下的部分在子进程没有出错的情况下是不会执行的。

```c++
// execl类：l是list的意思，表示参数是以列表的方式来传递进去
// path:是可执行程序的路径
int execl(const char *pathname, const char *arg, ...
          /* (char  *) NULL */);
// execlp:file ：在PATH下的可执行文件的名
int execlp(const char *file, const char *arg, ...
           /* (char  *) NULL */);
// execle: envp[]: 增加了环境变量
int execle(const char *pathname, const char *arg, ...
           /*, (char *) NULL, char * const envp[] */);

// execv类：v是vector的意思，表示参数是以矢量的形式传递进来的。
int execv(const char *pathname, char *const argv[]);
int execvp(const char *file, char *const argv[]);
int execvpe(const char *file, char *const argv[],
            char *const envp[]);
// p是文件，e是环境变量
```

关于`execl()`函数的使用，其中后缀"l"代表list也就是参数列表的意思，第一参数path字符指针所指向要执行的文件路径， 接下来的参数代表执行该文件时传递的参数列表：`argv[0]`,`argv[1]`... 最后一个参数须用空指针NULL作结束。

举例如下：

```c++
execl("/bin/ls", "ls", "-al", "/etc", NULL);
// 第一个参数path字符指针指向要执行的文件路径，参数列表的第一个参数是要执行的程序的名称，之后的是各个参数，最后一个参数必须使用空指针来结束。
```

1，带l 的exec函数：`execl,execlp,execle`，表示后边的参数以可变参数的形式给出且都以一个空指针结束。举例如下：

```c++
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    printf("entering main process---\n");
    execl("/bin/ls","ls","-l",NULL);
    printf("exiting main process ----\n");
    return 0;
}
```

2，带 p 的exec函数：`execlp,execvp`，表示第一个参数path不用输入完整路径，只有给出命令名即可，它会在环境变量PATH当中查找命令

3，不带 l 的exec函数：`execv,execvp`表示命令所需的参数以`char *arg[]`形式给出且`arg`最后一个元素必须是NULL。举例如下：

```c++
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    printf("entering main process---\n");
    int ret;
    char *argv[] = {"ls","-l",NULL};
    ret = execvp("ls",argv);
    if(ret == -1)
        perror("execl error");
    printf("exiting main process ----\n");
    return 0;
}
```

4，带 e 的exec函数：`execle`表示，将环境变量传递给需要替换的进程

从上述的函数原型中我们发现：

extern char **environ;

此处的environ是一个指针数组，它当中的每一个指针指向的char为`“XXX=XXX”`

举例如下：

```c++
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    //char * const envp[] = {"AA=11", "BB=22", NULL};
    printf("Entering main ...\n");
    int ret;
    ret =execl("./hello", "hello", NULL);
    //execle("./hello", "hello", NULL, envp);
    if(ret == -1)
        perror("execl error");
    printf("Exiting main ...\n");
    return 0;
}
```



> ```c++
> char *strstr(const char *haystack, const char *needle);
> // strstr在haystack 中查找第一个子串needle
> // 如果能够定位到needle子串，则返回第一次出现needle的指针，如果没有找到，那么就返回NULL
> ```


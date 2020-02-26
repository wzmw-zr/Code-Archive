# 2020.1.16—Linux基础知识

## 一、shell

shell是一种人机交互的接口，shell有壳的意思，是指"提供使用者使用界面"软件，是一种命令解释器。

shell不仅仅只是命令语言。其实GUI也是一种shell。

在shell内执行命令的过程：

shell接受用户端的命令—判断是否内置，如果i内置，则进行内核中的系统调用，否则，在系统中调入内存执行(这就是系统调用)。

shell并不是确定的程序，而是一组程序。

```shell
# Pathnames of valid login shells.
# See shells(5) for details.

/bin/sh
/bin/bash
/bin/zsh
/usr/bin/zsh
/usr/bin/git-shell
```



## 二、命令

命令是人和计算机交互的基本单位，人使用命令将要做什么事传给计算机，计算机作出解析，并作出回应。

命令也有自己的语法结构：

命令的主要结构也可以看作为主谓宾的简单句和复杂句。在命令中，省略主语。

```shell
cp(谓语动词) fileA(宾语) fileB(宾语)
cp(谓语动词) -ar(方式状语) fileA(宾语) fileB(宾语)
```

> 一般情况下，-后面加选项的缩写，--后面加选项的全写



## 三、程序与进程

程序是一组指示i计算机执行动作或作出判断的指令，通常使用某种程序设计语言编写，运行于某个目标体系结构之上。

进程是程序在内存中的映像。



## 四、路径

### 1.绝对路径

绝对路径是以根目录作为起始点。

### 2.相对路径

相对路径的起始点是当前i路径`.`

### 3.远程路径

远程路径是用来访问i本机之外的资源。

远程路径的一般表示法为：`协议：//用户名：密码@位置/路径：端口`



## 五、软件的相关知识

通常，一个软件包含的内容会分别拷贝到同级别的`bin`,`lib`，`share`，和`/etc`目录下。

1. `bin`存放可执行文件，在系统环境变量中将该路径加进去，就可以直接执行程序
2. `lib`库文件集中存放，方便共享
3. `share`存放程序所需要的其他资源
4. `/etc`配置文件存放路径，大部分程序的配置文件都可以在这个路径下找到
5. `src`是用来存放软件的源代码的



## 六、配置文件

> 关于热插拔的概念

### 1.修改网络配置的方法

直接修改配置文件，或者使用`ifconfig`命令直接修改网络的配置，(`ifconfig`命令是`Internet interface configure`的缩写)

```shell
ifconfig eth0 127.17.211.175
```



## 七、隐藏文件

文件的第一个字符是.的文件，就是隐藏文件。



## 八、Linux下文件的类型

| 缩写 | 全称         | 说明                                             |
| ---- | ------------ | ------------------------------------------------ |
| `-`  | regular file | 普通文件                                         |
| `d`  | directory    | 目录                                             |
| `l`  | link         | 链接                                             |
| `b`  | block        | 块设备，存储数据以供系统存取的接口设备，也就是盘 |
| `c`  | character    | 字符设备，串口设备，键盘、鼠标等                 |
| `s`  | socket       | 套接字                                           |
| `p`  | pipe         | 管道                                             |

普通文件又可以分为以下三种：

1. 纯文本文件
2. 二进制文件
3. 数据格式的文件



## 九、文件的权限

> `alias`别名:可以在系统中指定一个命令的别名。
>
> ```shell
> alias # 显示系统中所有的别名
> alias ll='ls -alF' #指定某一个命令的系统别名
> #由于在shell中空格具有明确的含义，作用就是分隔宾语，所以在指定别名的时候，在等于号两侧是i不允许有空格的
> ```

### 1.与文件权限相关的命令

```shell
chmod #更改文件的权限
chown #更改文件的所属用户
chgrp #更改文件所属的组
```

### 2.`chmod`的用法

> 三种不同用户：使用者user(-u)，组别group(-g)， 其他人others(-o)

```shell
chmod a+x file #给file文件的ugo都赋予执行的权限
chmod o-x file #给file文件的others减去执行的权限
chmod 755 file #设置文件的权限为rwxr-xr-x
chmod u=rwx,go=rx file #设置file文件的权限为rwxr-xr-x
```

### 3.`chown`的用法

```shell
chown user:group file #修改文件file的所属u用户为user，所属组为group
chown -R user:group directory #修改目录directory及目录下的所有文件的所属用户为user,所属组为group
chown user file #修改file的所属用户为user
```

### 4.`chgrp`的用法

```shell
chgrp root file #修改文件的所属组为root
```

> 错误代码13：权限错误。


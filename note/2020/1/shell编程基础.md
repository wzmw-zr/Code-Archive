# shell编程基础

## 一、输出

```shell
echo "hello world"
```



## 二、变量与局部变量

### 1.变量的定义

```shell
a=12
a=helloworld
a=`pwd` #``命令替换符
a=$a:a
```

### 2.局部变量

```shell
local a=12
```

> ```shell
> #对变量进行输出
> echo ${a}
> ```
>
> ==由于在shell中空格是有特殊分隔作用的，所以在shell脚本中相邻的符号之间不要有空格。==比方说：
>
> ```shell
> a = 12
> # 在这里， a会被看成一个命令 =是一个选项 12是一个变量
> ```

### 3.位置变量

```shell
$0 #获取当前执行的shell脚本的文件名，包括路径
$n #获取当前执行脚本的第n个传入参数，n=1,2,...9,如果n大于9,那么就需要将n使用大括号i括起来
$* #获取当前shell的所有传入参数，将所有的命令行参数视作单个字符，相当于"$1$2$3"
$# #得到执行当前脚本的传入参数个数
$@ #获取这个程序的所有传入参数，并保留参数之间的任何空白，相当于"$1" "$2" "$3",这是将参数传给其他程序的最好办法
```

### 4.状态变量

```shell
$? #判断上一个指令是否成功执行，0为成功，非0为不成功
$$ #取当前进程的PID
$! #上一个指令的PID
```



## 三、变量，参数展开

```shell
${parameter:-word} #如果变量未定义，则表达式的值为word
${parameter:=word} #如果变量未定义，则设置变量的值为word，返回表达式的值也是word
${parameter:?word} #用于捕捉由于变量未定义而导致的错误并退出程序
${parameter:+word} #如果变量已经定义，返回word,也就是真

#以上是用来判断变量存不存在，以及不存在时的相应的做法

${!prefix*} #以prefix开头的变量名
${!prefix@} #prefix开头的变量
```



## 四、字符串展开

```shell
${#parameter} #输出字符串长度

${parameter:offset} #从第offset个字符开始截取
${parameter:offset:length} #从第offset个字符开始截取，取length长度

${parameter#pattern} #从头删除最短匹配
${parameter##pattern} #从头删除最长匹配
${parameter%pattern} #从尾删除最短匹配
${parameter%%pattern} #从尾删除最长匹配

${parameter/pattern/string} #第一个匹配被替换
${parameter//pattern/string} #全局匹配被替换
${parameter/#pattern/string} #字符串开头的替换
${parameter/%pattern/string} #字符串结尾的替换

${parameter,,} ${parameter^^} #全部转为小写，大写
${parameter,} ${parameter^} #首字母n转化为小写，大写
```



## 五、输入—`read`

```shell
read [-options] [variable]
# -a array: 把输入赋值到数组array中，从索引号0开始
# -d delimiter: 把字符串delimiter中的第一个字符指示输入结束，而不是一个换行符
# -e: 使用Readline来处理输入，这使得与命令行相同的方式编辑输入
# -n num: 读取num个输入字符，而不是整行 (一般而言，分隔符就是换行符)

# -p prompt: 为输入显示提示信息，使用字符串prompt (就是回显模式)
# -r: Raw mode.不把反斜杠字符解释为转义字符
# -s: Slient mode
# -t seconds: 超时
# -u fd: 使用文件描述符fd中的输入，而不是标准输入
```

> 另一种输出方式：
>
> ```shell
> printf "%s is %d old\n" $name $age
> ```



## 六、函数

```shell
function _printf_() {
	# function body
	return 
}

# or
function _printf_ {
	#function body
	return
}
```

> 函数的使用方法：比如`_printf_ "Hello Haizei"`

## 七、流程控制—if

```shell
#格式一
if [[ condition ]] then #这里的 [[ condition ]]实际上是一个test表达式
# 注意这里的[[  ]]中间的表达式需要距离括号一个空格的距离
	#statements
fi

#格式二
if [[ condition ]]hen
	#statements
else
	#statements
fi

#格式三
if [[ condition ]]hen
	#statements
elif [[ condition ]]hen
	#statements
elif [[ condition ]]n
	#statements
else
	#statements
fi
```

> 关于test表达式的内容我们可以查看man手册 `man test`
>
> test表达式可以判断整型数字之间，字符串之间，文件之间的比较关系。



## 八、流程控制—`while`

```shell
while [[ condition ]]; do
	#statements
done
```



## 九、流程控制—`for`

```shell
# 形式1
for i in words; do
	#statements
done

#形式2
#依旧需要注意与括号之间的一个空格的问题
for (( i = 0; i < 10; i++ )); do
	#statements
done
```



## 十、流程控制—`until`

```shell
until [[ condition ]]; do
	#statements
done
```



## 十一、流程控制—`case`

```shell
case word in
	pattern )
	;;
esac
```



## 十二、数组

### 1.数组的声明

```shell
declare -a a
#定义a是一个数组
# 关于赋值与定义
name[subscript]=value
name={value1 vlaue2 ...}
```

### 2.数组操作

```shell
# 输出数组内容
${array[*]}
${array[@]}
# 确定数组元素个数
${#array[@]}
# 找到的数组的下标
${!array[@]}

#数组追加
array+={a b c}
#数组排序
sort
#删除数组与元素 (unset可以用来清空任意变量)
unset
```



> 注意`eval`的用法。
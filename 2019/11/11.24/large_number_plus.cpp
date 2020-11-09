#include <iostream>
#include <string>
using namespace std;


// 交换两个数，因为传入的值需要改变，所以使用取地址符
void swap(string &number_1, string &number_2) {
    string temp = number_1;
    number_1 = number_2;
    number_2 = temp;
}


// 比较两个数的大小，使大数在number_1，小数在number_2
void compare_and_swap_two_number(string &number_1, string &number_2) {
    int length_1 = number_1.length();
    int length_2 = number_2.length();
    // 若number_1长度小于number_2长度，则交换，使得大数在前，小数在后
    if (length_1 < length_2) {
        swap(number_1, number_2);
        return;
    }// 若number_1长度大于number_2长度，则直接返回
    else if (length_1 > length_2) return;
    // 若两个数的长度相等，则从高位到低位比较两个数在相同数位的大小
    else {
        int i = 0;
        while (i < length_1) {
            // 若该位number_1的数字大，则直接返回
            if (number_1[i] > number_2[i]) return;
            // 若该位number_2的数字大，则交换两个数之后返回
            else if (number_1[i] < number_2[i]) {
                swap(number_1, number_2);
                return;
            }else i++; // 否则i++，继续比较下一位
        }
        // 两数相等，直接返回
        return;
    }
}


// 使得字符串反转， 方便后续处理
void reverse_string(string &a) {
    int length = a.length();
    int i = 0, j = length - 1;
    while (i <= j) {
        char temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
}


// 两数相加，要求第一个参数number_1是值大的数，第二个参数number_2是较小的数，传入的都是已经经过反转的数
void add_two_number(string &number_1, string &number_2) {
    // 类似于竖式加法的处理， 将较小的数加到大数上, 由于要处理进位， 不能仅仅就止步于此， 同时需要考虑两数长度相等但是最后一位会有进位的情况
    for (int i = 0; i < number_2.length() - 1; i++) {
        int temp = number_1[i] - '0' + number_2[i] - '0';
        number_1[i] = temp % 10 + '0';
        number_1[i+1] += temp / 10;
    }

    // 防止两数长度相等而最后会有进位的情况
    int position = number_2.length() -1;
    int temp = number_1[position] - '0' + number_2[position] - '0';
    number_1[position] = temp + '0';

    // 处理较大数上的进位
    for (int i = position; i < number_1.length(); i++) {
        int temp = number_1[i] - '0';
        // 如果没有到最后一位， 因为到了最后一位可能会需要有进位
        if (i < number_1.length() - 1) {
            number_1[i] = temp % 10 + '0';
            number_1[i+1] += temp / 10;
        }
        // 处理最后一位的情况
        else {
            // 判断是否需要进位，temp >= 10就需要进位处理
            if (temp >= 10) {
                number_1[i] = temp % 10 + '0';
                char c = temp / 10 + '0';
                // 在字符串末尾加上进位
                number_1 += c;
            }else { // 不需要处理进位的情况
                number_1[i] = temp + '0';
            }
        }
    }
}


// 两个大数之间的加法
string add_two_large_number(string &number_1, string &number_2) {
    compare_and_swap_two_number(number_1, number_2);
    // 使得两个加数反转
    reverse_string(number_1);
    reverse_string(number_2);
    // 两数相加
    add_two_number(number_1, number_2);
    // 将结果反转
    reverse_string(number_1);
    // 将number_2恢复成原样
    reverse_string(number_2);
    return number_1;
}


int main () {
    string a, b;
    cin >> a >> b;
    string result = add_two_large_number(a, b);
    cout << result;
    return 0;
}
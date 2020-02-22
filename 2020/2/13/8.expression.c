/*************************************************************************
	> File Name: 8.expression.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月13日 星期四 23时00分27秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
#define ERROR 0
#define OK 1

typedef struct Stack {
    int *elements;
    int max_size, top_index;
} Stack;

void init(Stack *stack, int length) {
    stack->elements = (int *) malloc(sizeof(int) * length);
    stack->max_size = length;
    stack->top_index = -1;
}

int push(Stack *stack, int elements) {
    if (stack->top_index >= stack->max_size - 1) return ERROR;
    stack->top_index++;
    stack->elements[stack->top_index] = elements;
    return OK;
}

int pop(Stack *stack) {
    if (stack->top_index == -1) return ERROR;
    stack->top_index--;
    return OK;
}

int top(Stack *stack) {
    return stack->elements[stack->top_index]; 
}

int empty(Stack *stack) {
    return stack->top_index == -1;
}

int precede(char a, char b) {
    if (a == '*' || a == '/') {
        if (b == '+' || b == '-') return 1;
        return 0;
    } 
    return 0;
}
int operate(char theta, int a, int b) {
    switch (theta) {
        case '+' : return a + b;
        case '-' : return a - b;
        case '*' : return a * b;
        case '/' : return a / b;
    }
}
void calc(Stack *numbers, Stack *operators) {
    int a = top(numbers);
    pop(numbers);
    int b = top(numbers);
    pop(numbers);
    push(numbers, operate(top(operators), b, a));
    pop(operators);
}

void clear(Stack *stack) {
    free(stack->elements);
    free(stack);
}

int main() {
    char *buffer = (char *) malloc(sizeof(char) * 25);
    scanf("%s", buffer);
    Stack *numbers = (Stack *) malloc(sizeof(Stack));
    Stack *operators = (Stack *) malloc(sizeof(Stack));
    init(numbers, 20);
    init(operators, 20);
    int i = 0, flag = 0, num = 0;
    while (i < strlen(buffer)) {
        if (isdigit(buffer[i])) {
            if (flag) {
                pop(numbers);
                push(numbers, 10);
                flag = 0;
            } else {
                push(numbers, buffer[i] - '0');
                flag = 1;
            }
            i++;
        } else {
            flag = 0;
            if (empty(operators) || precede(buffer[i], top(operators))) {
                push(operators, buffer[i]);
                i++;
            } else {
                calc(numbers, operators);
            }
        }
    }
    while (!empty(operators)) {
        calc(numbers, operators);
    }
    printf("%d\n", top(numbers));
    clear(numbers);
    clear(operators);
    free(buffer);
    return 0;
}

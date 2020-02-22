/*************************************************************************
	> File Name: haizei_test.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月14日 星期二 16时46分05秒
 ************************************************************************/

#include<haizei_test.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

Function head, *tail = &head;
function_info info;

int RUN_ALL_TESTS() {
    Function *p = head.next;
    for (; p != NULL; p = p->next) {
        printf(GREEN("[====RUN====]")" : " RED("%s") "\n", p->str);
        info.total = info.success = 0;
        (p->func_name)();
        printf(GREEN("[  "));
        double rate = 100.0 * info.success / info.total;
        if (rate == 100.0)  printf(BLUE_HL("%6.2lf%%"), rate);
        else printf(RED_HL("%6.2lf%%"), rate); 
        printf(GREEN("  ]") " ");
        printf("total : %d    success : %d\n", info.total, info.success);
        printf("RUN END\n");
    }
    return 0;
}

void add_funtion(Func_t func, const char *str) {
    Function *p = (Function *)malloc(sizeof(Function));
    p->func_name = func;
    p->str = strdup(str);
    p->next = NULL;
    tail->next = p;
    tail = p;
}

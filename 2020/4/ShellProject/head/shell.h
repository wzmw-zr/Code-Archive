/*************************************************************************
	> File Name: shell.h
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月12日 星期日 19时06分40秒
 ************************************************************************/

#ifndef _SHELL_H
#define _SHELL_H
void PrintLinePre();
//char **ParseCommand();
void HandleCommand();
char **Split_Command(char *command, char *c);
void do_input(char *command);
void do_output(char *command);
void do_pipe(char *command);
#endif

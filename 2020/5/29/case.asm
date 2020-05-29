section .data
    char db '?'
section .text 
global _start
_start:
        mov ax,char
        mov ds,ax
 
        mov ah,0    ;进行输入
        int 16h
        mov char,al
 
        mov ah,2    ;进行输出
        mov dl,char
        int 21h
 
        mov ax,4ch
        int 21H

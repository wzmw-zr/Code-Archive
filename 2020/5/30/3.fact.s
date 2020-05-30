.data
InputMessage: .asciiz "input an integer which is between 1 and 100 :"
PrintMessage: .asciiz "Factorial = %g\n\n"
.align 2
PrintPar: .word PrintMessage
Printf: .space 8

.text
.global main

main:
        addi r1,r0,InputMessage
        jal InputUnsigned

        movi2fp f10,r1
        cvti2d f0,f10
        addi r2,r0,1
        movi2fp f11,r2
        cvti2d f2,f11
        movd f4,f2

Loop:
        led f0,f4
        bfpt Finish
        multd f2,f2,f0
        subd f0,f0,f4
        j Loop
Finish:
        sd Printf,f2
        addi r14,r0,PrintPar
        trap 5
        
over:   trap 0


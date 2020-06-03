.data
InputMessage: .asciiz "input an integer which is between 1 and 100 :"
PrintMessage: .asciiz "the sum of cube from 1 to %g"
Result: .asciiz " is %g\n"
.align 2
PrintPar: .word PrintMessage
Printf: .space 32
PrintParII: .word Result
Num: .space 32

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
        movi2fp f12,r0
        movd f6,f12

        sd Printf,f0
        addi r14,r0,PrintPar
        trap 5

OutLoop:
        ltd f0,f2
        bfpt End
        movd f8,f0
        multd f14,f0,f0
        multd f8,f14,f0
        addd f6,f6,f8
        subd f0,f0,f4
        j OutLoop

End:
        sd Num,f6
        addi r14,r0,PrintParII
        trap 5
        
over:   trap 0


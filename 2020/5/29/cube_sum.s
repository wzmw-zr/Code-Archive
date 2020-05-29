.data
InputMessage: .asciiz "input an integer which is between 1 and 100 :"
PrintMessage: .asciiz "the sum of cube from 1 to %g\n"
PrintPar: .word PrintMessage
Printf: .space 8

.text
.global main

main:
        addi r1,r0,InputMessage
        jal InputUnsigned
        add r2,r0,r1
        add r3,r0,1
        add r4,r0,r1
        addi r6,r0,0
        addi r7,r0,1
        addi r8,r0,0

OutLoop:
        beqz r4, End
        addi r9,r0,3
        add r5,r0,1
InnerLoop:
        beqz r9, Back
        mult r5,r5,r3
        subi r9,r9,1
        j InnerLoop
Back:
        add r6,r6,r5
        addi r3,r3,1
        subi r4,r4,1
        j OutLoop
End:
        sw Printf(r0),r6
        lf f0,Printf(r0)
        sd Printf,f0
        addi r14,r0,PrintPar
        trap 5
        
over:   trap 0

;Ascending order Selection Sorting
.MODEL SMALL
ORG 0X0100 

.STACK 100H

.DATA   

A DW 60, 55, 45, 50, 40, 35, 25, 30, 10, 0
MIN DW 0  ;used to store minimum value in a single iteration 


.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    MOV AX, [A] 
    MOV DX, 9
    CALL SELECTIONSORT
    .EXIT
MAIN ENDP

SELECTIONSORT PROC
    MOV SI, 0
    
    ITERATION:
    MOV CX, DX
    MOV DI, SI
    MOV AX, [A+SI]
    MOV [MIN], AX
    MOV BX, DI
    
    LOOP1:
    ADD DI, 2
    MOV AX, [A+DI]
    CMP [MIN], AX
    JB NOTGREATER
    MOV [MIN], AX
    MOV BX, DI
    
    NOTGREATER:
    LOOP LOOP1
    
    MOV AX, [A+SI]
    MOV [A+BX], AX
    MOV AX, [MIN]
    MOV [A+SI], AX
    ADD SI, 2
    SUB DX, 1
    CMP SI, 18
    JNE ITERATION
    
    EX:
    RET
SELECTIONSORT ENDP
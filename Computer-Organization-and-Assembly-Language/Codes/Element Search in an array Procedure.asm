.MODEL SMALL
ORG 0X0100 

.STACK 100H

.DATA   

A DW 60, 55, 45, 50, 40, 45, 25, 30, 10, 45
SEARCH DW 45   ;Number to be search in the array
FOUND DW 0    ;If the search number is found in an array (It works like a flag)
TIMES DW 0  ;How many times a number searched has occured in an array


.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    MOV AX, [SEARCH] 
    CALL BinarySearch
    .EXIT
MAIN ENDP

BinarySearch PROC
    MOV SI, 0
    MOV CX, 0
    
    ITERATION:
    CMP AX, [A+SI]
    JE SUCCESS
    ADD SI, 2
    CMP SI, 20
    JNE ITERATION
    JMP T1
    
    SUCCESS:
    ADD CX, 1
    ADD SI, 2
    CMP SI, 20
    JNE ITERATION
    
    T1:
    CMP CX, 1
    JAE FO:
    JMP EX
    
    FO:
    MOV [FOUND], 1
    MOV [TIMES], CX
    
    EX:
    RET
BinarySearch ENDP
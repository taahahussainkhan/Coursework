.MODEL SMALL
ORG 0X0100 

.STACK 100H

.DATA   

NUM DB 0x12
PR DB 0
NPR DB 0

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    MOV AL, [NUM] 
    CALL PRIMENUMBER
    .EXIT
MAIN ENDP

PRIMENUMBER PROC
    CMP AL, 2           
    JB  NPRIME
    MOV BL, 02H
    MOV BH,00H
    MOV DX,0000H
    MOV AH,00H
    
    UP:DIV BL 
    CMP AH,00H
    JNE NEXT
    INC BH
    NEXT: CMP BH, 02H
    JE NPRIME
    INC BL
    MOV AX, 0000H
    MOV DX, 0000H
    MOV AL, [NUM]
    CMP BL, [NUM]
    JBE UP
    
    PRIME: 
    INC [PR]
    JMP EX
    
    NPRIME: 
    INC [NPR]
    
    EX:
    RET
PRIMENUMBER ENDP
.model small 

.data   

str db 'Sum of A and B is  : $' 

A db 5,1,6,0,7 

B db 1,8,3,9,1 

C db ?          

.code   

jmp start 

SUM proc  

    mov bx,0 

    l1:      

    mov al,A[bx] 

    add al,B[bx] 

    mov C[bx],al 

    inc bx 

    loop l1 

    ret 

    SUM endp 

start: 

main proc 

mov ax,@data 

mov ds,ax 

mov cx,5 

mov ax,0 

call SUM  

mov cx,5 

mov bx,0  

mov dx,offset str 

mov ah,9 

int 21h 

l2:      

mov dl,C[bx] 

add dl,48 

mov ah,2 

int 21h 

mov dl,' ' 

mov ah,2 

int 21h 

inc bx 

loop l2 

.exit                  

main endp 
.model small
.data 
arr db "Sum of A and B is : $"
A dw 1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,4
B dw 1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,4 
C dw 20 dup(0)
.code
mov ax,@data
mov ds,ax
mov bx,0
mov cx,20
mov ax,0
l1:
mov ax,A[bx]
add ax,B[bx]
mov C[bx],ax
inc bx
inc bx
loop l1
lea dx,arr
mov ah,9
int 21h
mov cx,20
mov bx,0
l2:
mov dx,','
mov ah,2
int 21h
mov dx,C[bx]
add dx,48
mov ah,2
int 21h
inc bx
inc bx
loop l2
.exit
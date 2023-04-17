.model small
.data
sum db 0
arr db 0,1,1,1,1,1,1,1,1,1
output db "Sum is : $"
.code
mov ax,@data
mov ds,ax
mov cx,10
mov ax,0
mov bx,0
l1:     
add al,arr[bx]
inc bx
loop l1
mov sum,al
add sum,48
lea dx,output
mov ah,9
int 21h
mov dl,sum
mov ah,2
int 21h
.exit

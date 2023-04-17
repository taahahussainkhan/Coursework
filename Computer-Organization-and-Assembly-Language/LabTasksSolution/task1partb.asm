.model small
.data
arrA dw 1,2,3,4,5,6,7,8,9
arrB dw 1,2,3,4,5,6,7,8,9
arrC dw 9 dup ?
.code
mov ax,@data
mov ds,ax
mov ax,0
mov bx,0
mov dx,0
mov cx,9
l1:
mov ax,[arrA+bx]
mov dx,[arrB+bx]
cmp ax,dx
ja cr
jb low
low:
mov [arrC+bx],dx
add bx,2
dec cx                                 
jz x
jmp l1
cr:
mov [arrC+bx],ax
add bx,2
dec cx
jz x
jmp l1
x:
.exit
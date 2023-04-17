.model small
.data
arr dw 9,2,4,1,1,3,3,6,7,9,2,4,1,1,3,3,6,5,7
.code
mov ax,@data
mov ds,ax
mov ax,0
mov bx,0
l1:
mov cx,19
mov si,0
l2:
mov ax,arr[bx]
cmp ax,arr[si]
jg noswap
jng swap
swap:
mov ax,arr[bx]
xchg ax,arr[si]
mov arr[bx],ax 
jmp l3
noswap:
jmp l3
l3:
inc si
inc si
loop l2
inc bx
inc bx
cmp bx,40
jne l1
mov bx,0
mov cx,20
l4:
mov dx,arr[bx]
add dx,48
mov ah,2
int 21h
inc bx
inc bx
loop l4
.exit

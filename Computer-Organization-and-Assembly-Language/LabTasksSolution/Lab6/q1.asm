.model small
.data
str1 db "Enter number which you want to check : $"
str2 db " Occurrence is : $"
arr db 9,2,4,6,5,4,2,1,2,1,2,3,6,7,8,9,4,2,6,7
.code
mov ax,@data
mov ds,ax
lea dx,str1
mov ah,9
int 21h
mov ah,1
int 21h
mov dl,al
sub dl,48
mov bx,0
mov cx,20
mov ax,0
mov dh,0
l1:
mov al,arr[bx]
cmp al,dl
je equal
jne n_equal
equal:
add dh,1
inc bx
jmp i
n_equal:
inc bx
jmp i
i:
loop l1
add dh,48
mov cl,dh
lea dx,str2
mov ah,9
int 21h
mov dl,cl
mov ah,2
int 21h
.exit
.model small
.data
arrA dw 1,2,3,4,5,6,7,8,9
arrB dw 1,2,3,4,5,6,7,8,9
arrC dw 9 dup ?
.code
moc ax,@data
mov ds,ax
mov cx,9
mov ax,0
mov bx,0
l1:
mov ax,[arrA+bx]
add ax,[arrB+bx]
mov [arrC+bx],ax
add bx,2
dec cx
loop l1
.exit
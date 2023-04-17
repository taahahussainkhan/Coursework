.model small
.data 
.code
mov ax, 100h ; initialize AX with 0100h
mov bx, 55ABh ; initialize BX with 55ABh
mov cx, 0A11h ; initialize CX with 0A11h
mov dx, 0001h ; initialize DX with 0001h
; DX = AX + BH - CL + DX
add ah,bh
sub ah,cl
add ax,dx
mov dx,ax
 
.exit
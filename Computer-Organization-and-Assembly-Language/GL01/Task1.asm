
.model small

.data

.code     
mov ax,100h         
mov bx,14h
mov cx,18h         
mov dx,29h

sub ax,bx;(AX-BX)  

sub ax,cx;((AX-BX)-CX)

sub dx,cx;(DX-CX)

add bx,ax;((AX-BX)-CX)+B   

add bx,dx;((AX-BX)-CX)+BX+(DX-CX) 

mov cx,bx;CX=((AX-BX)-CX)+BX+(DX-CX)


hlt



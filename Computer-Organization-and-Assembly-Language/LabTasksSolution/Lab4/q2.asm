.model small
.data             
X dw ?
.code  
mov ax,@data
mov ds,ax
mov ax,0x2113
or ax,0x2340
and ax,0xABFF
mov bx,0xFF12   
not bx
xor ax,bx
mov X,ax
.exit
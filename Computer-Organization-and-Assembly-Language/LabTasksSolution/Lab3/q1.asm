.model small 
.data 
number dw 0x1F00 , 0xA0B1 , 0x1254 , 0x34EF , 0x8700
ans dw 0
.code
mov ax,@data
mov ds,ax 
mov bx,0x1000        ; storing all numbers in ds with little inian notation
mov cx,5
mov si,0
l1:
mov ax,number [si]
mov word ptr ds:[bx],ax  
add si,2
add bx,2
loop l1
                     ; calculate sum of all numbers 
mov cx,5
mov bx,0
l2:
mov ax,number[bx] 
add ans,ax                   
add bx,2
loop l2              ; store sum at the physical address

mov bx,ans
mov ax,0xCD1F 
mov ds,ax     

mov word ptr ds:[0x0003],bx
                                                         
.exit

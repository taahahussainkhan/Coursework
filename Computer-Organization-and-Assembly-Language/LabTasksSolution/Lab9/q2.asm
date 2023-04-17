.model small 

.data 

arr1 db 1,2,3,4,5,6,7,8,9 

   

arr2 db 9 dup(0) 

.code 

mov ax,@data 

mov ds,ax 

mov ax,0  

 

mov ah,0 

mov si,0 

mov bx,0  

mov dx,0 

nested:  

mov cx,3 

l1: 

mov al,arr1[bx] 

mov arr2[si],al 

inc si 

add bx,3 

loop l1  

mov bx,0  

inc dx 

mov bx,dx 

inc ah 

cmp ah,3 

jne nested  

.exit 
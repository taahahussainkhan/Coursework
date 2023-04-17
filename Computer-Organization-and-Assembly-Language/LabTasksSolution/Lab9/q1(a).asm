.model small 

.data 

arr1 dw 4,2,3,4,5,6,7,8,9,0,1,2,3,4,5,4 

arr2 dw 2,9,8,7,6,5,4,3,2,1,2,3,4,5,6,1 

arr3 dw 16 dup(0) 

.code 

mov ax,@data 

mov ds,ax 

mov ax,0 

mov cx,16 

mov bx,0 

l1:  

mov ax,arr1[bx] 

mul arr2[bx] 

mov arr3[bx],ax 

inc bx 

inc bx   

mov ax,0 

loop l1   

.exit 
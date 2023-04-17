.model small 

.data 

arr1 dw 4,2,3,4       ; 2 by 2 matrix miltiplication 

arr2 dw 1,4,3,2 

arr3 dw ?    

.code 

mov ax,@data 

mov ds,ax 

mov ax,0   

mov bx,0  

mov si,0 

mov ax,arr1[bx] 

mul arr2[bx] 

mov cx,ax 

mov ax,0 

mov ax,arr1[bx+2]  

mul arr2[bx+4] 

add cx,ax  

mov arr3[si],cx 

mov cx,0 

mov ax,0 

mov ax,arr1[bx] 

mul arr2[bx+2] 

mov cx,ax 

mov ax,0 

mov ax,arr1[bx+2] 

mul arr2[bx+6] 

add cx,ax  

inc si 

inc si 

mov arr3[si],cx 

mov cx,0 

mov ax,0 

mov ax,arr1[bx+4] 

mul arr2[bx] 

mov cx,ax 

mov ax,0 

mov ax,arr1[bx+6] 

mul arr2[bx+4] 

add cx,ax  

inc si 

inc si 

mov arr3[si],cx 

mov cx,0 

mov ax,0 

mov ax,arr1[bx+4] 

mul arr2[bx+1] 

mov cx,ax 

mov ax,0 

mov ax,arr1[bx+6] 

mul arr2[bx+6]  

mov cl,ch 

add cx,ax 

mov ch,0  

inc si  

inc si 

mov arr3[si],cx 

mov cx,0 

mov ax,0  

.exit 
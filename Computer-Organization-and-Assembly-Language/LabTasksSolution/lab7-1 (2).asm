.model small
.data
A dw 1,2,5,6,7
b dw 6,7,5,2,1
c dw 5 dup ?

.code
 main proc
 mov ax,@data
 mov ds,ax 
 mov bx, offset A
 mov ax,5
 push ax
 push bx
 mov bx,offset b
 push bx
 mov bx,offset c
 push bx
 
 call sum
 
 pop ax 
  pop ax 
   pop ax
    pop ax
    
    .exit
    
    
    Main endp
 
 sum proc
    push bp
    push cx
    push si           
    
    
    mov bp,sp
    mov cx,[bp+14]
    mov dx,[bp+12]
    mov bx,[bp+10]
    mov ax,[bp+8]   
    mov bp, ax
    mov ax,0
    mov si,0
    l1:
    mov ax,ds:[dx+si]
    add ax,ds:[bx+si]
    mov ds:[bp+si],ax
    add si,2
    loop l1
    pop si
    pop cx
    pop bp
    
    ret
    
    sum endp
 
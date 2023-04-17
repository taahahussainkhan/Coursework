.model small


.stack 100h


.data
    arr dw 1,5,2,4,2,8,5,2,3,1,4,1,7,8,9 
    

.code
    mov ax,@data
    mov ds,ax       
    mov si,offset arr
    mov cx,15
    
    outer:
    mov bx,cx
    mov si,0
    
    compl:
    mov ax,[si]
    mov dx,[si+2]
    cmp ax,dx
    
    jc noSwap
    
    mov [si],dx
    mov [si+2],ax
    
    noSwap:
    inc si 
    inc si
    dec bx 
    jnz compl
    
    loop outer                                          

hlt
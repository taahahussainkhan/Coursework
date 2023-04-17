
.model small


.stack 100h


.data

nam1 db "Taaha",0 
temp db 6 dup(0)
.code

   
   main proc
   
   mov ax,@data
   mov ds,ax
   
   
   mov bx,offset nam1
   
   push bx
   
   call reverse
   
   main endp
   
   
   reverse proc
    
    push bx
    push cx
    push dx
    push si
    push di
    push bp
    mov bp,sp 
    push es   
        
   mov bx,[bp+14]  
    
    mov cx,0
    mov si,0  
    
    l1:
    
    mov al,[bx+si] 
   
    cmp al,0
    jz l1end
    push ax
    
    inc cx
    inc si
    jmp l1
    
   
   
   l1end: 
    
  
    mov si,0 
    
    l2: 
    pop dx
    
    mov [temp+si],dl
    
    
    inc si
    loop l2 
    
    mov dx,11001011b
    mov ax,0xb800
    mov es,ax
    
    mov si,0x7D0
    
    mov bx,offset temp
    mov di,0 
    
    
    loopx:
    
    mov al,[bx+di]
    cmp al,0
    je end
    
    mov es:[si],al
    
    mov es:[si+1],dx
    
    add si,2
    inc di  
    add dx, 10110000b
    
    jmp loopx
    
    end:
    
        
   reverse endp     
   
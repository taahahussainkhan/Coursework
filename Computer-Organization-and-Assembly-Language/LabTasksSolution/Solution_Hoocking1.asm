 .model small
.stack 100h

.data  
 msg: db "Press 1 to add, Press 2 to multiply, Press 3 to divide $"
 num1 dw 0057h
 num2 dw 0078h
 numd db 02h
 result dw 0


.code

   mov ax,@data
   mov ds,ax
   
   mov ax,0h
   mov es,ax
   
  mov word ptr es:[194h],isr65
   mov word ptr es:[196h],cs 
   
   mov si,offset num1
   mov di, offset num2
   mov bx, offset result
   
   int 0x65



.exit


isr65 proc  
    
 
   mov dx,offset msg
   mov ah,9
   int 0x21  
    
   mov ah,0x1 
   int 0x21
   sub al,0x30 
   mov ah,al
   
   cmp ah,0x1
   je addition 
                
   cmp ah,0x2
   je multiply
   
   cmp ah,0x3
   je divide
   
   
   addition:
       mov dx,[si]
       add dx,[di]
       mov [bx],dx
       jmp end 
       
        
   multiply:
       mov ax,[si]
       mov dx,[di]
       mul dx
       mov [bx],ax
       jmp end 
             
    
    divide:
       mov di,offset numd
       mov ax,[si]
       mov dl,[di]
       div dl
       jmp end 
    
    
   end:
   iret 
    
isr65 endp    
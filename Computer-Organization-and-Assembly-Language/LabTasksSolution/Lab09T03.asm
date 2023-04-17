


.model small


.stack 100h



.data

num1 dw 0
num2 dw 0 
sum dw 0


msg db 0Ah, 0Dh,"Enter First Number: $"
msg1 db 0Ah, 0Dh,"Enter second Number: $"
msg2 db 0Ah, 0Dh,"The Sum is: $"

.code


                mov ax,@data
                mov ds,ax    
                
                mov cx,04
                mov si,offset num1
                
                
                lea dx,msg
                mov ah,0x9
                int 21h
                
                
    l1:            

                mov ah, 1 
                int 21h    
                mov ah, 0
                sub ax, 0x30  
                push ax
                loop l1
                
                
                mov bx, 0
                mov cx, 0x10
                
                pop ax          
                add bx, ax
                
                pop ax
                mul cx 
                         
                add bx, ax
                
                pop ax
                mov cx, 0x100    
                mul cx
                add bx, ax
                
                pop ax
                mov cx, 0x1000   
                mul cx
                add bx, ax
                
                
                mov [si], bx
                
                
      
     ok: 
       mov cx,04
        mov si,offset num2 
        
        lea dx,msg1
         mov ah,0x9
          int 21h
                
    l2:            

                mov ah, 1 
                int 21h    
                mov ah, 0
                sub ax, 0x30  
                push ax
                loop l2
                
                
                mov bx, 0
                mov cx, 0x10
                
                pop ax          
                add bx, ax
                
                pop ax
                mul cx 
                         
                add bx, ax
                
                pop ax
                mov cx, 0x100    
                mul cx
                add bx, ax
                
                pop ax
                mov cx, 0x1000   
                mul cx
                add bx, ax
                
                
                mov [si], bx
                
                
                
                 
                
                
                mov ax,num1
                mov bx,num2 
                
                add ax,bx
                
                 
            
                mov bx, 10h
                mov cx, 0x4   


flip:
                
                div bx
                push dx
                loop flip
                 
                mov cx, 0x4
                lea dx, msg2
                mov ah, 09h
                int 21h                                  
              
              
output: 
                pop ax
                add al, 0x30 
                mov dl, al
                mov ah, 2
                int 21h 
                loop output
                



                        
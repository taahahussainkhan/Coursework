.model small



.stack 100h



.data

num dw 0

msg db "Enter a number: $"


.code

        mov ax,@data
        mov ds,ax
        
        
        mov cx, 4h
                
                
                lea dx, msg
                mov ah, 0x9
                int 0x21  
                mov si,offset num
        
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
                
                jmp end 
                
                end:     
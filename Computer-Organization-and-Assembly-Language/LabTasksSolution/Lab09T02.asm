




             
             
      .model small
      
      
      .stack 100h
      
      
      .data
      
        num dw 6543h
      
        msg1 db "The numer is: $"
      .code
      
      
                mov ax,@data
                mov ds,ax   
                
                
                mov si,offset num
                
                mov ax, [si] 
                mov bx, 10h
                mov cx, 0x4   


flip:
                
                div bx
                push dx
                loop flip
                 
                mov cx, 0x4
                lea dx, msg1
                mov ah, 09h
                int 21h                                  ;<Raise interrupt 21h. This call the MS-DOS service to print the "msg1" string.>
              
              
output: 
                pop ax
                add al, 0x30 
                mov dl, al
                mov ah, 2
                int 21h 
                loop output
              
                


end:

                

        
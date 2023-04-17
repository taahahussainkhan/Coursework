.model smal
.stack
.data
      integer1 dw 0
      integer2 dw 0
.code
     mov ax,@data
     mov ds,ax  
     
     mov ax,0 
     mov cx,4
     l1:
       mov bx,offset integer1
       mov ax,[bx+si]
       mov bx,10
       mul bx 
       mov bx,offset integer1
       mov [bx+si],ax
       
       mov ax,0
       mov ah,01h
       int 21h 
       
       mov ah,0
       sub al,30h 
       mov bx,offset integer1
        
       add [bx+si],ax
       loop l1
               
     mov ax,0 
     mov cx,4
     l2: 
       mov bx,offset integer2
       mov ax,[bx+si]
       mov bx,10
       mul bx 
       mov bx,offset integer2
       mov [bx+si],ax
       
       mov ax,0
       mov ah,01h
       int 21h 
       
       mov ah,0
       sub al,30h 
       mov bx,offset integer2
        
       add [bx+si],ax
       loop l2 
       
       mov bx,[integer1] 
       push bx 
       
       mov bx,[integer2] 
       push bx 
       
       call function1
       
       pop ax
       mov [integer2],ax
       
       pop ax
       mov [integer1],ax 
       
       
       mov bx,[integer1] 
       push bx 
       
       mov bx,[integer2] 
       push bx 
       
       call function2 
       
       pop bx
       pop bx
       
       
      
.exit   


function1 proc  
    push ax
    push bx
    push bp
    
    mov bp,sp
    
    mov ax,[bp+8]
    shl ax,1;for multiplication by 2
    
    mov [bp+8],ax 
    
    mov ax,[bp+10]
    shl ax,1
    
    mov [bp+10],ax 
    
    pop bp
    pop bx
    pop ax
    ret
    
    
    
    
    
endp  function1   


function2 proc 
    
       
       push ax
       push bx
       push bp
       
       mov bp,sp
       mov ax,[bp+10]
       mov bx,[bp+8]
       sub ax,bx
       
       mov bx,0001h
       
       mov word ptr ds:[bx],ax 
       
       pop bp
       pop bx
       pop ax
       ret
    
endp function2
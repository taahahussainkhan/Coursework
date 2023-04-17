
.model small

.stack 100h

.data

x db 0D5h,041h,0A7h,0B4h  
y db 0B3h,0FEh,0E8h,021h 

temp db 4 dup(0) ;temporary array for comparison

result db 8 dup(0);Resultant Array to store 64 bit number             


.code

    main proc
    mov ax,@data
    mov ds,ax
    
    
    mov cx,4 
    mov si,0
    
    l1:
      
      mov al,[y+si]
      mov [temp+si],al
      inc si
      loop l1  
    
    call multiplier 
    
    main endp                   
  
   multiplier proc
        
 ;Taking Backup of the registers that will be used in this procedure
        
    push cx
    push bx
    push dx
    push si
    push di
    push bp
    mov bp,sp     
    
   
    mov ch,4   ;Counter for Outer loop
    
    mov ax,0
    
    mov si,0   ;Index  
    mov di,0
 
     mov ax,0
 Outer: 
      
    
    mov bl,[x+si] 
    
    mov dl,[y+si]  
   
    mov cl,8;Inner loop counter
     
     mov ax,0
 
 Inner:   
     
    shr [temp+si],1
    
    jnc no 
    
    
    add ax,bx   
    jmp no
    
    no:
    
    shl bl,1
    
    shr dl,1   
    
    ;mov [result+di],ah 
    
   ; mov [result+di+1],al    
    
    dec cl 
    
    cmp cl,0
    
    jne Inner
     
    
    mov [result+di],ah   ;Saving the 64-bit result in a third array (as required)    
    mov [result+di+1],al 
    

     inc di
     inc di
    
     inc si 
    
    dec ch
    jnz Outer
   
           
           pop bp
           pop di
           pop si
           pop dx
           pop bx
           pop cx
     
    
     multiplier endp
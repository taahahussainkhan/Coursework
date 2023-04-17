.model small


.stack 100h  

.data      

arr db 1,2,3,1,1,1,1,1,1,2,1,1,4,3,2,1,1,3,2,1
one db 1

.code
  
  mov ax,@data
  mov ds,ax
  
  mov si,offset arr
  mov cx,20      
  mov dl,0
  mov bl,one
loopx:
  
  mov al,[si]
  
  cmp bl,al
  
  jz same
  jnz then1
    
  
  same:
     inc dl 
      inc si
      jmp exit1
      
  then1:            
    inc si       
  
  exit1:
             
 
    loop loopx
     
      mov one,dl
hlt



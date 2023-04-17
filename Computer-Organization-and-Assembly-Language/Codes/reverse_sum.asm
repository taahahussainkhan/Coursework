.model small


.data


A dw 5,2,5,6,1,8,9,1,4,5,3,4,5,6,7,4,4,2,1,2
B dw 1,2,5,3,2,8,9,2,1,2,3,4,5,6,7,3,1,5,7,1
C dw 20 dup(?)

.code

mov ax,@data
mov ds,ax
   
   
   mov cx,20
   mov si,0
   mov di,0
   
   l1:
         
        mov dx,[B+di]
        push dx    
        
      inc di
      inc di  
      
         loop l1 
         
            
     
      mov cx,20 ;reseting counter    
            
            
      l2:
      
      mov ax,[A+si]    
      
      pop dx 
      
      add ax,dx   
     mov [C+si],ax  
      
   
      inc si
      inc si  
      
      loop l2 
              
   
     mov si,0         
     mov cx,20 ;reseting counter
      
      
      l3:
      
       push [C+si] 
           
        inc si
        inc si  
        
        loop l3  
        
        mov si,0
        mov cx,20  ;reseting counter   
             
      l4:
      
      pop [C+si]  
      
      inc si
      inc si
      
      loop l4 
      
 

hlt 
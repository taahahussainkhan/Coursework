.model small 

.stack 75h  

.data

arr1 db 2,5,1,4,2,9,6,2,4 ;First 3x3 matrix  
arr2 db 3,6,4,6,3,7,9,1,3 ;Second 3x3 matrix
resultant db 9 dup (?)   ; Resultant 3x3 matrix

.code

mov ax, @data
mov ds, ax
   
;(a) Write a program to add same indices of two matrices A and B and place their sum
;in the third matrix in the same index as shown in figure below for your reference.


mov bx, 5000h   
mov di, 5200h   


mov si, 0 
mov cx, 9 ;Counter of 9 as the matrix is of 3x3=9 size             
 

 l1:             

; using AL,BL as temporary registers  

 mov al, [arr1+si]   ; Temporarily moving each value of first matrix into al  
 mov bl, [arr2+si]   ; Temporarily moving each value of seconf matrix into bl
 add bl, al    
      
 mov [resultant+si], bl        

 mov [di], bl        
 

 inc si      ; incrementing index
 inc di      ; incrementing destination index

 loop l1

 
   
;(b)Compare the values with the same indices of two matrices A and B and place the
;maximum of the two values in the same index of the third matrix C. You are
;required to perform the comparison considering the signed numbers.





 mov si,0    ;index
 mov dx, 9   ; counter

 mov bx, 5000h 
 mov di, 5200h
 mov ax, 5100h

    iter:     
        mov al, [arr1+si]     
        mov bl, [arr2+si]
        cmp al,bl   
            
            
           
           
        jnle greater      ; if ( al > bl ) 
        
        mov cl,bl   
        mov [di], cl 
        
        
        
        
        inc di  ;Incementing index to reach next index
        inc si  ;Incrementing destination index
        dec dx  ;Decrementing counter 
             
      
        jnz iter   
    
           
           
  greater: 
                mov cl, al
                mov [di], cl 
                inc si ;Incementing index to reach next index
                inc di ;Incrementing destination index
                dec dx ;Decrementing counter    
       
       
       
       
        jnz iter
    
hlt
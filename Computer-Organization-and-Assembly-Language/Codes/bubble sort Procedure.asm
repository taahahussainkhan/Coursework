.model small
  
org 0x0100
.data

D dw 60, 55, 45, 50, 40, 35, 25, 30, 10, 0 
swap db 0 


.code 
MAIN PROC   
    
    CALL BubbleSort
      
    .exit  
    
MAIN ENDP 

BubbleSort PROC

start: mov bx, 0 ; initialize array index to zero 
       mov [swap], 0 ; rest swap flag to no swaps 
 
loop1: mov ax, [D+bx] ; load number in ax 
       cmp ax, [D+bx+2] ; compare with next number 
       jbe noswap ; no swap if already in order 
 
       xchg ax, [D+bx+2]
       mov [D+bx], ax ; store second number in first 
       mov [swap], 1 ; flag that a swap has been done 
 
noswap: add bx, 2 ; advance bx to next index 
        cmp bx, 18 ; are we at last index 
        jne loop1 ; if not compare next two 
 
        cmp [swap], 1 ; check if a swap has been done 
        je start ; if yes make another pass 
        
        RET
        
BubbleSort ENDP
        
        
END MAIN     

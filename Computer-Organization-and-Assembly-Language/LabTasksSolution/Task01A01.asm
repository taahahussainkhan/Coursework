.model small


.data
    arr1 db 1,2,3,4,5,6,7,8,9 ;first 3x3 matrix
    arr2 db 1,2,3,4,5,6,7,8,9 ;second 3x3 matrix
    resultant  db 9 dup(?) ;third 3x3 matrix

.code

    mov ax,@data
    mov ds,ax

    mov si,offset arr1
    mov di,offset arr2  
    mov cx,09h  ;counter for loop
     
 L1:  

 mov dl,[si]  ;Temporarily storing first matrix's elements in dl register
 mov bl,[di]  ;Temporarily storing second matrix's elements in bl register
 
 add dl,bl;Adding elements in dl register for temporay purpose      
 
 mov [resultant+si],dl ;Moving the sum of two matrices to a third resultant array through a temporay register DL. 

 inc si ;Incrementing the index of first array 
 inc di ;Incrementing the index of second array
 
    loop l1
           
           
           hlt
   

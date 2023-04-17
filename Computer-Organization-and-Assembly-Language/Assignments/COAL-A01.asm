.model small
.stack 100h
.data

arr1 db 1,2,3,4,5,6,7,8,9  
arr2 db 4,6,1,1,9,3,8,1,2
arr3 db 9 dup (0)   ; array 3 of size 9 having nine 0 elements

.code

mov ax, @data
mov ds, ax

mov bx, 2000h   ; giving address to base register
mov di, 2200h   ; giving address to destinaition index 

; counters
mov si, 0 
mov cx, 9              

l1:     ; a) for addition of 2 arrays ( 3 x 3 )
                    ; NOTE: i'm using AL,BL as temporary registers
mov bl, [arr1+si]   ; moving each value of array 1 into base register (bl - 8 bits)  
mov al, [arr2+si]   ; moving each value of array 2 into accumulator register (al - 8 bits)
add al, bl          ; adding bl into al ( adding arr1 into arr2 )
mov [arr3+si], al   ; moving the SUM into array 3 indices
mov [di], al        ; moving the SUM into DI register
 

inc si      ; incrementing
inc di      ; incrementing
dec cx      ; decrementing 

jnz l1

;----------------------------------------------------------------

l2:     ; b) for finding maximum values between array 1 & array 2 and placing it into array 3 

; resseting counters and register addresses  
mov si,0
mov dx, 9   ; using different counter to avoid overlapping
mov bx, 2000h 
mov di, 2200h
mov ax, 2100h

    again:      ; a separate label for next procedure so that it can't reset counters and registers repeatedly
        mov bl, [arr1+si]   ; as i've reset everything so that's why putting values in bl and al again  
        mov al, [arr2+si]
        cmp bl,al   
            jg max      ; if ( bl > al ) this will skip to label "max"  otherwise code will run following the sequence
        mov cl,al   
        mov [di], cl
        inc di
        inc si
        dec dx      
        jnz again   ; it'll go to the start point of label "again" and check the other elements of arrays
    
            max: 
                mov cl, bl
                mov [di], cl 
                inc si
                inc di
                dec dx     
        jnz again   ; it'll go to the start point of label "again" and check the other elements of arrays    
    
.exit

; To see results, search in memory "ds:2200" there you'll see the desired outputs.
.model small
.data
.code    
call random 
mov byte ptr cs:[bx+0x30],0xF4
.exit



random proc
    pop bx   ; to store address current offsett  
    push bx 
   ret
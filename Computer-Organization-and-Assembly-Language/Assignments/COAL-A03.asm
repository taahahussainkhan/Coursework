.model small
.data

msg1 db "Enter Number: $"
msg2 db 0Ah, 0Dh, ">> Your Number is: $"   ; 0A = 10, used for newline 
                                        ; 0D = 13, used for carraige return

num dw 0000

.code  

mov ax, @data
mov ds, ax

mov ax, 0
mov es, ax


mov si, offset num 

mov word ptr es:[65*4], isr65
mov word ptr es:[65*4+2], cs

mov ah, 1   ; for READING 
int 65   

mov ah, 2   ; for DISPLAYING
int 65

jmp END_PROGRAM


isr65 proc
     
cmp ah, 1
je READ

cmp ah, 2
je DISPLAY

jmp RETURN



READ:

mov cx, 4h ; size for loop

; printing message
lea dx, msg1
mov ah, 09h
int 21h

; runtime input using int 21/1
INPUT:            
mov ah, 1 
int 21h    
mov ah, 0
sub ax, 30h  ;converting ASCII
push ax
loop INPUT

; extracting numbers (1,2,3,4) from stack into one variable (4321)
mov bx, 0
mov cx, 10h

pop ax          ; ax = 1, bx = 1
add bx, ax

pop ax
mul cx          ; ax = 2, bx = 21
add bx, ax

pop ax
mov cx, 100h    ; ax = 3, bx = 321
mul cx
add bx, ax

pop ax
mov cx, 1000h   ; ax = 4, bx = 4321
mul cx
add bx, ax


mov [si], bx

jmp RETURN



DISPLAY:

mov ax, [si] 
mov bx, 10h
mov cx, 4h ; size of loop  

; inverting 4321 to 1234
inv:
div bx
push dx
loop inv
 
mov cx, 4h ; size of loop
; printing message
lea dx, msg2
mov ah, 09h
int 21h 
 
OUTPUT: 
pop ax
add al, 30h  ; converting ASCII
mov dl, al
mov ah, 2
int 21h 
loop OUTPUT



RETURN:

iret
isr65 endp   



END_PROGRAM:

.exit
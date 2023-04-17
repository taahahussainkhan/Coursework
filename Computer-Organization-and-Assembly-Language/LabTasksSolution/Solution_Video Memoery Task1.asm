.model small
.stack 100h
.data

    msg db "Print",0
    cursor dw 0
.code
main proc
    mov ax,@data
    mov ds,ax
    Mov ax,0xb800
    Mov es,ax
    mov bx,offset msg
    push bx
    push cursor
    call Display
    pop cx
    pop cx


.exit
main endp

Display proc
    
    push si
    push bx
    push di
    mov si, cursor
    mov bx,offset msg
    mov di,0
    l1:
    mov al,[bx+di]  ; mov one character from array to al
    cmp al,0        ; compare is that character is null
    je end          ; if null, terminate loop
    
    
    mov es:[si],al  ; otherwise, mov that character to video memory
    add si,2        ; add 2 to si, skipping the attribute part
    inc di          ; inc di to access the next character of array
  jmp l1            ; iterate loop

 end:

  mov cursor,si
  
  pop di
  pop bx
  pop si
  
  
  ret
  
  Display endp
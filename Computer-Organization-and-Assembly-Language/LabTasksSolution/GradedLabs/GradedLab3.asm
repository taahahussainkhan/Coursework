.model small
.stack 100h
.data
size dw ?
str1 db "Haroon Babar!" 
color db 0x0a,0x0b,0x0c,0x0d,0x0e,0x0f 
.code 
main proc
    mov ax,@data
    mov ds,ax
    mov ax,0xb800
    mov es,ax
    mov ax,0   
    mov di,0
    length:
    mov al,str1[di]
    inc di
    inc size 
    cmp al,0x21 
    jne length
    mov ah,0x0a
    mov di,0 
    mov si,0
    dec size
    mov cx,size
    mov bx,1980
    l1: 
    mov al,str1[di] 
    mov ah,color[si]
    mov es:[bx],ax
    inc bx
    inc bx
    inc di 
    inc si
    cmp si,6
    je gozero
    jne gonotzero
    gonotzero:
    jmp l2
    gozero:
    mov si,0
    jmp l2
    l2:
    loop l1    
main endp
.exit
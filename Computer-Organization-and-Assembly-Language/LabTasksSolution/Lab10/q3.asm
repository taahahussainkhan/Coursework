.model small  

.stack 100h 

.data  

r db 24 

c db 0  

temp dw ?        ; it will store correct address of the screen by using cursor position 

row db 9         ; cursor position x axis 

col db 31         ; cursor position y axis 

str db "Hellow World" 

.code 

main proc 

mov ax,@data 

mov ds,ax 

mov ax,0xb800 

mov es,ax 

; we will find address of the screen by using formula 

; formula = (row address x number of colomn x 2) + (colomn address x 2)  

mov ax,0  

mov al,80 

mul row  

mov [temp],ax 

mov ax,0 

mov al,2 

mul temp 

mov temp,ax 

mov ax,0 

mov al,2 

mul col 

add temp,ax 

mov bx,0  

mov si,temp  

mov cx,12  

l1: 

mov al,str[bx] 

mov ah,0x5a 

mov word ptr es:[si],ax 

inc si 

inc si 

inc bx 

loop l1 

l2: 

mov ax,0  

mov al,80 

mul r  

mov [temp],ax 

mov ax,0 

mov al,2 

mul temp 

mov temp,ax 

mov ax,0 

mov al,2 

mul c 

add temp,ax 

mov bx,0  

mov si,temp  

mov al,' ' 

mov ah,0x5a 

mov word ptr es:[si],ax 

inc si 

inc si 

inc bx 

inc c 

inc c 

cmp c,80 

jne l2   

main endp 

.exit 
.model small  

.stack 100h 

.data   

size dw ?        ; size of the string 

temp dw ?        ; it will store correct address of the screen by using cursor position 

row db 5         ; cursor position x axis 

col db 20         ; cursor position y axis 

str db "My name is",9,"Haroon",10,"Babar",13,"Malik!" 

.code 

main proc 

mov ax,@data 

mov ds,ax 

mov ax,0xb800 

mov es,ax 

; we will find address of the screen by using formula 

; formula = (row address x number of colomn x 2) + (colomn address x 2)  

mov bx,0  

mov cx,0 

length: 

inc size 

mov al,str[bx] 

inc bx 

cmp al,0x21 

jne length 

mov cx,size 

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

call print 

main endp 

.exit 

print proc 

l1: 

mov al,str[bx] 

mov ah,0x5a   

cmp al,09 

je tab 

jne checkNewLine   

checkNewLine: 

cmp al,10 

je newLine 

jne checkCret 

checkCret: 

cmp al,13 

je cret 

jne continue 

tab: 

add si,16 

jmp continue  

newline: 

add si,160 

jmp continue 

cret: 

mov dl,col 

add dl,dl 

sub si,dx   

mov dx,0 

mov dx,size 

add dx,dx 

sub si,dx 

sub si,2 

jmp continue 

continue: 

mov word ptr es:[si],ax 

inc si 

inc si 

inc bx 

loop l1 

ret  

print endp 
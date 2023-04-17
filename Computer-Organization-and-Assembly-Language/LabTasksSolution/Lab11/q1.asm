.model small 

.stack 100h 

.data 

variable dw ? 

.code 

mov ax,@data 

mov ds,ax 

mov ah,1 

int 21h 

sub al,48     

mov cl,10h 

mul cl  

mov bh,al 

mov ah,1 

int 21h 

sub al,48 

add bh,al 

mov ah,1 

int 21h  

sub al,48     

mul cx  

mov bl,al 

mov ah,1 

int 21h 

sub al,48 

add bl,al 

adc bh,0 

mov variable,bx 

.exit 
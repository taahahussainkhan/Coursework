.model small 

.stack 100h 

.data 

variable dw ? 

print db " Your number is : $" 

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

mul cl  

mov bl,al 

mov ah,1 

int 21h 

sub al,48 

add bl,al 

mov variable,bx 

 

mov di,10h 

mov ax,variable 

div di 

push dx 

 

div di 

push dx 

 

div di 

push dx 

 

div di 

push dx 

       

       

lea dx,print     

mov ah,9 

int 21h 

 

pop ax 

mov dl,al 
cmp dl,0xa

add dl,48

mov ah,2 

int 21h 

 

pop ax 

mov dl,al 

add dl,48 

mov ah,2 

int 21h 

 

pop ax 

mov dl,al 

add dl,48 

mov ah,2 

int 21h 

 

pop ax 

mov dl,al 

add dl,48 

mov ah,2 

int 21h 

.exit 

 
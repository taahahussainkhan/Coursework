.model small  

.stack 100h 

.data 

a dw 4 

b dw 2 

c dw 2 dup(0)     

d db 2  

str1 db " Addition is exicuted(int 65h) $"  

str2 db " Multiplication is exicuted(int 65h) $" 

str3 db " Division is exicuted(int 65h) $" 

.code 

main proc  

l1: 

mov ax,@data 

mov ds,ax 

mov ax,0 

mov es,ax 

lea si,a 

lea di,b  

lea bx,c 

mov ah,1 

int 21h 

sub al,48  

cmp al,1 

je addition 

cmp al,2 

je multiplication 

cmp al,3 

je division 

.exit 

addition:  

mov word ptr es:[0x0194],sum 

mov word ptr es:[0x0196],cs 

int 65h  

jmp l1 

.exit 

multiplication: 

mov word ptr es:[0x0194],multiply 

mov word ptr es:[0x0196],cs 

int 65h   

jmp l1 

.exit 

division: 

mov word ptr es:[0x0194],divide 

mov word ptr es:[0x0196],cs 

int 65h 

jmp l1 

.exit 

main endp 

 

sum proc  

    mov c[0],0  

    mov c[2],0 

    lea dx,str1 

    mov ah,9 

    int 21h 

    mov dx,0 

    mov dx,si[0] 

    add dx,di[0]  

    mov bx[0],dx     

    iret 

 

multiply proc 

    mov c[0],0  

    mov c[2],0 

    lea dx,str2 

    mov ah,9 

    int 21h 

    mov dx,0 

    mov ax,si[0] 

    mul di[0] 

    mov bx[0],dx 

    mov bx[2],ax         

    iret 

 

divide proc 

    mov c[0],0  

    mov c[2],0  

    lea dx,str3 

    mov ah,9 

    int 21h 

    mov dx,0   

    mov ax,si[0]  

    lea di,d 

    div di[0] 

    iret 
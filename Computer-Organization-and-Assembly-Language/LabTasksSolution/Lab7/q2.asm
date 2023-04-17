.model small  

.stack 100h 

.data  

strtrue db "Word is palindrome. $"  

strfalse db "Word is not palindrome. $" 

arr1 db 'E','N','G','L','I','S','H' 

arr2 db ?          

.code  

call main   

main proc       

mov ax,@data 

mov ds,ax 

mov ax,0   

mov cx,7 

mov bx,0 

l1:      

mov al, arr1[bx] 

push ax      

inc bx  

loop l1  

mov bp,sp 

mov bx,0  

mov cx,7 

mov di,0 

l2:      

mov ax,[bp+di]  

mov arr2[bx],al     

inc bx 

inc di 

inc di 

loop l2 

mov bx,0  

mov cx,7 

mov di,0 

l3:      

mov al,arr1[bx]  

cmp al,arr2[bx]  

je equal 

jne notequal 

equal: 

inc di 

notequal:  

add bx,1 

loop l3       

cmp di,7 

je True 

jne False 

True: 

mov dx,offset strtrue 

mov ah,9 

int 21h 

mov dl,1 

.exit 

False: 

mov dx,offset strfalse 

mov ah,9 

int 21h 

mov dl,0 

.exit 

main endp          
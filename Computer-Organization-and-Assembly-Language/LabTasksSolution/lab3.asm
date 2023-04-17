.model small   

.stack 100h     

.data    

msg db "Nabeera",0    

.code              

mov ax,@data   

mov ds,ax       

Mov ax,0xb800

Mov es,ax

Mov si,0 

mov bx,offset msg

mov di,0

display:

mov al,[bx+di] 

cmp al,0 

je end ; 

mov es:[si],al 

add si,2  

inc di       



jmp display 

end:
 
.exit
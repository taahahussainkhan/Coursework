.model small




.data


.code
       mov word ptr ds:[01000h],01f00h     
       mov word ptr ds:[01002h],0a0b1h
       mov word ptr ds:[01004h],01254h
       mov word ptr ds:[01006h],034efh
       mov word ptr ds:[01008h],08700h  
       add ax,ds:[01000h]  
       add ax,ds:[01002h]
       add ax,ds:[01004h]
       add ax,ds:[01006h]
       add ax,ds:[01008h]
                          
                   mov bx,0cd1fh
                          mov ds,bx
                      mov ds:[0003h],ax
                          hlt
.exit                             
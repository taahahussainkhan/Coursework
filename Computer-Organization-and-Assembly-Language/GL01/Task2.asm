.model small



.data


.code  


   mov ax,0xA1F0
  mov ds:[02000h],ax
  
  mov bx,0x1B0F
  mov ds:[02002h,bx        
  
  add bx,ax
  
  
  mov ds:[0x5000],bx     
  
  hlt



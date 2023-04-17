.model small
  
org 0x0100
.data

multiplicand db 13
multiplier db 5
result db ?


.code 

start: mov cl, 4 ; initialize bit count to four 
       mov bl, [multiplicand] ; load multiplicand in bl 
       mov dl, [multiplier] ; load multiplier in dl 
       
checkbit: shr dl, 1 ; move right most bit in carry 
          jnc skip ; skip addition if bit is zero 
          add [result], bl ; accumulate result 
 
skip: shl bl, 1 ; shift multiplicand left 
      dec cl ; decrement bit count 
      jnz checkbit ; repeat if bits left 
        
        
.exit
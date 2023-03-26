
;INPUT IN AN ARRAY
;USING INTERRUPTS
;AND DISPLAYING IT
;USING VIDEO MEMORY 
.model small
.data
            array db 14 dup(?), $
.code
            mov ax, @data
            mov ds, ax
            
            xor ax, ax
            
            mov es, ax
            mov word ptr es:[65h*4], [My_Isr]
            mov word ptr es:[65h*4+2], cs
            
            int 65h
.exit

My_Isr:

            mov ax, 0b800h
            mov es, ax
            xor si, si
            mov cx, 14
            
            l1:
               mov ah, 1
               int 21h
               mov [array+si], al
               inc si               
            loop l1
            
            
            mov di, 160
            xor si, si
            mov ax, 0b800h
            mov es, ax
            mov cx, 14
            mov ah, 0fh
            l2:
              mov al,[array+si]
              mov es:[di], ax
              inc si
              inc di
              inc di  
            loop l2
iret
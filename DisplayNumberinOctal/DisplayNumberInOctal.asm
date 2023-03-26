.model small
.data
            Array db 4 dup(?)
            Temp  dw 0 
.code
            mov ax, @data
            mov ds, ax            
            xor ax, ax
            
            lea si, [Array]
            mov cx, 4
            l1: 
                mov ah, 1
                int 21h
                mov [si], al
                inc si             
            loop l1
            
           xor si, si
           mov bx, 1000
           mov ax, [si]
           xor ah, ah
           sub al, 30h
           mul bx
           add [Temp], ax
           
           mov bx, 100
           mov ax, [si+1]
           xor ah, ah
           sub al, 30h
           mul bx
           add [Temp], ax
           
           mov bx, 10
           mov ax, [si+2]
           xor ah, ah
           sub al, 30h
           mul bx
           add [Temp], ax
           
           mov ax, [si+3]
           xor ah, ah
           sub al, 30h
           add [Temp], ax
            
           mov bx, 8
           xor cx, cx
           mov ax, [Temp]
           l2:
               xor dx, dx
               div bx
               push dx
               inc cx
               cmp ax, 0
               jne l2               
           
           mov ax, 0b800h
           mov es, ax
           mov di, 160 
           l3:
               pop dx
               mov dh, 0fh
               add dx, 30h
               mov es:[di], dx
               inc di
               inc di
           loop l3
           
            
.exit       
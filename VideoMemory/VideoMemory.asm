.model small
.data
        array db 'Syed Najiullah'
        size dw 14
.code

        mov ax, @data
        mov ds, ax
        xor ax, ax
        jmp start:
        print:
        push bp
        mov bp, sp
        
        mov ax, 0b800h
        mov es, ax
        mov ah, 0Fh
        xor di, di
        xor si, si
        
        mov cx,[bp+4]
        mov bx,[bp+6]
        
        l1:
          lodsb
          stosw
        loop l1
        
        pop bp
        ret 4
        start:
        
        mov bx, offset [array]
        mov cx, [size]
        push bx
        push cx
        call print
.exit

;PROGRAM TO FIND THE SUM OF 2 NUMBERS USING 
;INTERRUPS 
.model small
.data
            num1 dw 8h
            num2 dw 4h
            num3 dw ?
.code
            mov ax, @data
            mov ds, ax
            xor ax, ax
            mov es, ax
            mov word ptr es:[65*4], isr65
            mov word ptr es:[65*4+2], cs
            mov si, offset num1
            mov di, offset num2
            mov bx, offset num3
            int 65
.exit
            isr65:
            mov ax, [si]
            mov cx, [di]
            add ax, cx
            mov [bx], ax
            iret
.model small
.data

            array1      dw  1h,2h,3h,4h,5h,6h,7h,8h,9h,10h
            size        dw  10
            oddnumbers  dw  0
            evennumbers dw  0
.code           
            mov ax,@data
            mov ds,ax
            jmp start:
            evenodd:
            
                push bp
                mov bp,sp
                mov cx, [4+bp]
                mov bx, [bp+6]
                l1:
                    mov dx, [bx]
                    shr dx,1
                    jc odd
                    inc evennumbers
                    jmp skip 
                    odd:
                    inc oddnumbers
                    skip:
                    add bx, 2 
                loop l1
                pop bp
                ret 4
               
           start:
            
            mov bx, offset array1
            mov cx,size
            push bx
            push cx
            call evenodd

.exit
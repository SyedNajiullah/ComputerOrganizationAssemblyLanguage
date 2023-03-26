org 100h
jmp start
    
    array dw 55h,4444h,2222h,3333h,1111h                                            ; mov si, [size]
    flag db 0                                                                         ; dec si
                                                                                      ; shl si, 1
start:                                  
      jmp code                          
      bubblesort: ; subroutine          
      push bp                           
      mov bp,sp                         
      
      push si
      push ax
      push bx
      push dx
      mov bx,[bp+6]
again:
    mov si,0                                                 
    mov byte ptr[flag], 0                                    
L1:                                                          
    mov ax, [bx+si]                                          
    cmp ax, [bx+si+2]                   ;   "STACK REVIEW"    ;
    jb noswap                           ;                     ;
    mov dx,[bx+si+2]                    ;                     ;
    mov [bx+si+2],ax                    ;  dx                 ;
    mov [bx+si],dx                      ;---------------------;                
    mov byte ptr[flag],1                ;  bx                 ;
noswap:                                 ;---------------------                     ; 
    add si, 2                           ;  ax                 ; 
    cmp si, 8                           ;---------------------;   
    jne L1                              ;  si                 ; 
    cmp byte ptr[flag],1                ;---------------------;
                                        ;  bp --------->sp    ;
    je again                            ;---------------------;
    pop dx                              ;                     ;
    pop bx                              ;  "SUBROUTINE"       ;
    pop ax                              ;                     ;
    pop si                              ;---------------------;
    pop bp                              ;  return address     ; ;bp+2
    ret 4                               ;---------------------;
      code:                  ; ret 2    ;  cx(size of array)  ; ;bp+4 }
                                        ;---------------------;       }--->Two parameters
                             ; ret 4    ;  bx(array address)  ; ;bp+6 }
                                        ;---------------------;
      mov bx, offset array
      push bx   ; ARRAY
      mov cx,5h ; SIZE
      push cx
      call bubblesort     
.exit
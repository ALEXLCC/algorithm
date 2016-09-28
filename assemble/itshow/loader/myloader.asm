;
;	loader just show a welcome message!
;

org 07c00h; segment address 07c00
	;start address is 07c00h not 00000
	mov ax,cs
	mov es,ax
	mov bp,msgstr	;es:bp  ----->msgstr
	mov cx,12	;length
	mov dh,12	;row
	mov dl,36	;col
   	mov bh,0	;page
	mov al,1	;display string 
	mov bl,0ch	;property
	mov ah,13h	;call 13h son program
	msgstr: db "hello my os!"
	int 10h
	times 510-($-$$) db 0	;repeat 0
	dw 55aah
	jmp $	;jmp to current line

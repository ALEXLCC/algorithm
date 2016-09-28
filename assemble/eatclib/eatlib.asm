;
;	call outs
;
[SECTION .data]
EatMsg: db "Eat at Joe's!",0
[SECTION .bss]
[SECTION .text]
extern puts
global main
main:
	push ebp	;build heap stack
	mov ebp,esp	;save esp
	push ebx
	push esi
	push edi
	push EatMsg
	call puts
	add esp,4	;esp--->

	pop edi
	pop esi
	pop ebx
	pop ebp
	ret

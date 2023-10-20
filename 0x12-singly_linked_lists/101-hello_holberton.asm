section .data
	format db 'Hello, Holberton',10,0

section .text
	global main
	extern printf

main:
	push rdi                ; Save registers that may be modified by printf
	mov rdi, format
	call printf
	pop rdi                 ; Restore the original value of rdi

	mov rax, 60             ; syscall: exit
	xor rdi, rdi            ; status: 0
	syscall

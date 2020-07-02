				global		ft_list_sort
				section		.text

%define			NULL		dword 0X0

; void	ft_list_sort(t_list **begin_list, int (*cmp)())
ft_list_sort:
				; begin_list == NULL ?

				cmp			rdi, 0
				je			return

				; *begin_list == NULL ?
				cmp			[rdi], NULL
				je			return

				; one element in the list ?
				mov			r8, [rdi]
				cmp			[r8 + 8], NULL
				je			return

				push		rdi
				push		rsi
				mov			rcx, r8
				mov			rdx, rsi

loop:
				; starting loop
				cmp			[rcx + 8], NULL
				je			end

				; preserving registers in stack
				push		r8
				push		rcx
				push		rdx

				; preparing the call of cmp
				mov			rdi, [rcx]
				mov			rsi, [rcx + 8]
				mov			rsi, [rsi]

				; calling cmp
				call		rdx

				; restoring registers
				pop			rdx
				pop			rcx
				pop			r8

				; if rax less or equal to 0 so we increment and return to loop
				cmp			eax, 0
				jle			increment

				; now we need to swap [rcx] and [[rcx + 8]]
				; r9 -> tmp and r10 -> [rcx + 8] and r11 -> [r10]

				mov			r10, [rcx + 8]
				mov			r11, [r10]

				mov			r9, [rcx]
				mov			[rcx], r11
				mov			[r10], r9

				; restart loop
				mov			rcx, r8
				jmp			loop

increment:
				mov			rcx, [rcx + 8]
				jmp			loop

end:
				pop			rsi
				pop			rdi
				mov			[rdi], r8
return:
				ret

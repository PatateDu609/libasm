				global		ft_list_size
				section		.text

ft_list_size:
				mov			rax, 0
				cmp			rdi, 0
				je			end
				mov			rcx, 0

loop:
				mov			rdi, [rdi + 8]
				inc			rax
				cmp			rdi, 0
				jne			loop

end:
				ret

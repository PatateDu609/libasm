			global		ft_strlen
			section		.text

ft_strlen:
			cmp			rdi, 0
			mov			rax, 0
			je			end
			mov			rax, -1

loop:		inc			rax
			cmp			BYTE [rdi + rax], 0
			jne			loop


end:		ret

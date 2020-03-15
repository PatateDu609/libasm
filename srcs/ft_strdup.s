				global		ft_strdup
				section		.text

				extern		ft_strlen
				extern		malloc
				extern		ft_strcpy

ft_strdup:
				mov rax, 0

len:
				push		rdi
				call		ft_strlen
				mov			rdi, 0
				mov			rdi, rax
				inc			rdi
				call		malloc
				pop			rdi

copy:
				push		rax
				mov			rcx, rdi
				mov			rsi, rdi
				mov			rdi, rax
				call		ft_strcpy
				pop			rax

end:
				ret

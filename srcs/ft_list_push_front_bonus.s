						global		ft_list_push_front
						section		.text

						extern		malloc

ft_list_push_front:
						push		rsi
						push		rdi
						mov			rdi, 16				; sizeof(list)
						call		malloc
						pop			rdi
						pop			rsi
						mov			[rax], rsi
						mov			rcx, [rdi]
						mov 		[rax + 8], rcx
						mov 		[rdi], rax
						ret

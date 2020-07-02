			global			ft_strcmp
			section			.text

ft_strcmp:
			mov rax, 0

loop:
			mov al, BYTE [rdi]
			mov bl, BYTE [rsi]
			cmp al, 0
			je end
			cmp bl, 0
			je end

			cmp al, bl
			jne end
			inc rdi
			inc rsi

end:
			movzx rax, al
			movzx rbx, bl
			sub rax, rbx
			ret

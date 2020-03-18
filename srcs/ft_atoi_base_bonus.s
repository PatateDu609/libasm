				global		ft_atoi_base
				section		.text

				extern		ft_strlen

ft_atoi_base:
				push		rbx
				; checking base
				push		rdi
				push		rsi

				mov			rdi, rsi
				call		ft_check_base

				pop			rsi
				pop			rdi

				cmp			eax, 0
				je			end

				; then setting base size in rdx
				push		rdi
				push		rsi

				mov			rdi, rsi
				call		ft_strlen

				pop			rsi
				pop			rdi

				mov			rdx, rax

loop_whitespaces:
				; checks if current character is whitespace or not
				push		rdi

				mov			dil, BYTE [rdi]
				call		ft_isspace

				pop			rdi

				cmp			rax, 1
				jne			sign
				inc			rdi
				jmp			loop_whitespaces

sign:
				; setting sign
				mov			rbx, 1
loop_sign:
				; if current *str is - so we negate sign else we just continue
				inc			rdi
				cmp			[rdi - 1], BYTE '-'
				je			negate
				jmp			test_loop_sign
negate:
				neg			rbx
test_loop_sign:
				cmp			[rdi - 1], BYTE '+'
				je			loop_sign
				cmp			[rdi - 1], BYTE '-'
				je			loop_sign

compute_result:
				dec			rdi
				mov			rax, 0

main_loop:
				; while (current = ft_get_value(*str, base))
				push		rax
				push		rdx
				push		rdi
				push		rsi

				mov			rdi, [rdi]
				call		ft_get_value
				mov			rcx, rax

				pop			rsi
				pop			rdi
				pop			rdx
				pop			rax

				; check if result is valid (ft_get_value returns -1 if invalid)
				cmp			rcx, 0
				jl			end

				; computing new result and incrementing str
				imul		rax, rdx
				add			rax, rcx

				inc			rdi
				jmp			main_loop

end:
				imul		rax, rbx
				pop			rbx
				ret

; int	ft_get_value(char c, char *base)
ft_get_value:
				mov			rax, 0

loop_value:
				; testing successively *rsi != 0 then *base != c
				cmp			[rsi], BYTE 0
				je			end_value
				cmp			[rsi], dil
				je			end_value

				inc			rsi
				inc			rax
				jmp			loop_value

end_value:
				cmp			[rsi], BYTE 0
				je			ret_invalid
				ret

ret_invalid:
				mov			rax, -1
				ret

; int	ft_check_base(char *base)
ft_check_base:
				; computing len of base
				push		rdi
				call		ft_strlen
				pop			rdi

				cmp			rax, 1
				jle			ret_false

loop_check:
				; *base == '\0' and then break
				cmp			[rdi], BYTE 0
				je			ret_true

				; *base <= ' '
				cmp			[rdi], BYTE ' '
				jle			ret_false

				; *base >= 127
				cmp			[rdi], BYTE 127
				jge			ret_false

				; *base == '-'
				cmp			[rdi], BYTE '-'
				je			ret_false

				; *base == '+'
				cmp			[rdi], BYTE '+'
				je			ret_false

				; ft_isspace(*base) == 1
				push		rdi
				mov			dil, [rdi]
				call		ft_isspace
				pop			rdi
				cmp			rax, 1
				je			ret_false

				; tmp = base + 1
				mov			rsi, rdi
				inc			rsi
				mov			cl, [rdi]

loop_check_unique:
				cmp			[rsi], cl
				je			ret_false
				inc			rsi

				cmp			[rsi - 1], BYTE 0
				jne			loop_check_unique

				inc			rdi
				jmp			loop_check

; int	ft_isspace(char c)
ft_isspace:
				; rdi == 32 ?
				cmp			dil, ' '
				je			ret_true

				; rdi >= 9 ?
				cmp			dil, 9
				jnge		ret_false
				; rdi <= 13 ?
				cmp			dil, 13
				jnle		ret_false

ret_true:
				mov			rax, 1
				ret
ret_false:
				mov			rax, 0
				ret

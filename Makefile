################################################################################
#                               Name of the output                             #
################################################################################
NAME				=	libasm.a

################################################################################
#                          Paths of sources and objects                        #
################################################################################
PATH_INCLUDES		=	include
PATH_SRCS			=	srcs
PATH_OBJS			=	objs

################################################################################
#                              Name of sources files                           #
################################################################################
SRCS_BASENAME		=	write		\
						read		\
						strlen		\
						strcpy		\
						strcmp		\
						strdup		\

################################################################################
#                             Commands and arguments                           #
################################################################################
RM					=	rm -f
NASM				=	nasm
AR					=	ar rcs

################################################################################
#                         DO NOT MODIFY BELOW THIS POINT                       #
################################################################################

ifeq ($(shell uname), Linux)
ASMFLAGS			=	-felf64
else
ASMFLAGS			=	-fmacho64
endif

SRCS_EXT			=	$(addprefix ft_, $(addsuffix .s, $(SRCS_BASENAME)))

SRCS				=	$(addprefix $(PATH_SRCS)/, $(SRCS_EXT))
OBJS				=	$(addprefix $(PATH_OBJS)/, $(SRCS_EXT:.s=.o))

$(PATH_OBJS)/%.o:	$(PATH_SRCS)/%.s
					$(NASM) $(ASMFLAGS) $< -o $@

$(NAME):			$(OBJS)
					$(AR) $(NAME) $(OBJS)

test:				$(NAME)
ifdef MAIN
	$(CC) mains/$(MAIN) -L. -lasm -I$(PATH_INCLUDES) -fsanitize=address -no-pie -fsanitize=leak
endif

all:				$(NAME)

clean:
					$(RM) $(OBJS)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
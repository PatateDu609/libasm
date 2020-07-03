#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libasm.h"
#include "libasm_bonus.h"

#define SIZE 10

#ifndef BONUS
#define BONUS 0
#endif

void mid_title()
{
	printf("\033[0;32m");
}

void fat_title()
{
	printf("\033[0;31m");
}

void reset()
{
	printf("\033[0m");
}

int test_read()
{
	ssize_t result;

	mid_title();
	printf("read from standard input\n");
	reset();
	printf("Type something (buffer = 32): \n");
	char str[33];
	result = ft_read(1, str, 32);
	if (result >= 0)
	{
		str[result] = 0;
		printf("You typed : |%s| -- %ld\n", str, result);
	}
	else
		perror("error");

	mid_title();
	printf("Write to a file then read from it\n");
	reset();
	int fd = open("ft_read.test.txt", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd < 0)
		perror("error");
	result = write(fd, "Trying to read some input from file...\n", 39);
	char *str2 = malloc(result + 1);
	close(fd);

	fd = open("ft_read.test.txt", O_RDONLY);
	if (fd < 0)
		perror("error");
	result = ft_read(fd, str2, result);
	if (result >= 0)
	{
		str2[result] = 0;
		printf("The function read from file : |%s| -- %ld\n", str2, result);
	}
	else
		perror("error");
	free(str2);
	close(fd);

	mid_title();
	printf("trying to read from wrong fd :\n");
	reset();
	fd = open("ft_read.test.txt", O_WRONLY);
	if (fd < 0)
		perror("error");
	result = ft_read(fd, str2, result);
	printf("result of the function : %ld\n", result);
	perror("error");
	close(fd);
}

void test_write()
{
	ssize_t result;

	mid_title();
	printf("Writing into stdout :\n");
	printf("\033[0m\n");
	result = ft_write(1, "|Hello World!", 13);
	printf("| -- %ld\n", result);

	mid_title();
	printf("Writing into custom file, then printing the content :\n");
	reset();

	int fd = open("ft_write.test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		perror("error");
	result = ft_write(fd, "Trying to write some output into file...\n", 41);
	if (result < 0)
		perror("error");
	close(fd);
	if (result >= 0)
	{
		fd = open("ft_write.test.txt", O_RDONLY);
		char *str = malloc(result + 1);
		result = read(fd, str, result);
		str[result] = 0;
		printf("File content : |%s|\n", str);
		free(str);
		close(fd);
	}

	mid_title();
	printf("Trying to write to the wrong fd\n");
	reset();

	fd = open("ft_write.test.txt", O_RDONLY);
	if (fd < 0)
		perror("error");
	else
	{
		result = ft_write(fd, "test", 4);
		printf("result = %ld\n", result);
		perror("error");
	}
}

void unit_test_strlen(char *str)
{
	if (str != NULL)
	{
		printf("strlen on \"%s\" : %ld\n", str, strlen(str));
		printf("ft_strlen on \"%s\" : %ld\n", str, ft_strlen(str));
	}
	else
		printf("strlen segfaults with NULL\n");
}

void test_strlen()
{
	mid_title();
	printf("Testing with normal string :\n");
	reset();
	unit_test_strlen("Hello world!");

	mid_title();
	printf("Testing with big string :\n");
	reset();
	unit_test_strlen("boiuhsfoihjdsfoihjdfoidshfodihfodisjhfosdijfosaijfasoifhsofanbdlofuhnaovliuhvolzuchvzouivhjpjihapofuidshjfpoauhvlovbnlaovhnolpvuihdpodijhahzol;xvkjnhlzvjnouhapofiuhjapofijhp");

	mid_title();
	printf("Testing with empty string :\n");
	reset();
	unit_test_strlen("");

	mid_title();
	printf("Testing with NULL :\n");
	reset();
	unit_test_strlen(NULL);
}

void test_strcpy()
{
	char src[] = "Hello World!";
	char dst[13];

	mid_title();
	printf("Addresses : src = %p, dst = %p\n", src, dst);
	printf("Testing to copy src to dst :\n");
	reset();

	printf("returned (%p)\n", ft_strcpy(dst, src));
	printf("dst (%p) : |%s|\n", dst, dst);
	printf("src (%p) : |%s|\n", src, src);
}

void unit_test_strcmp(const char *s1stack, const char *s2stack)
{
	char *s1 = s1stack ? strdup(s1stack) : NULL;
	char *s2 = s2stack ? strdup(s2stack) : NULL;
	mid_title();
	printf("Testing with : \"%s\"(%p), \"%s\"(%p)\n", s1, s1, s2, s2);
	reset();

	if (s1 && s2)
	{
		printf("strcmp = %d\n", strcmp(s1, s2));
		printf("ft_strcmp = %d\n", ft_strcmp(s1, s2));
	}
	else
		printf("strcmp doesn't work with NULL");
	free(s1);
	free(s2);
}

void test_strcmp()
{
	unit_test_strcmp(
					"Hello World!",
					"Hello World!"
	);

	unit_test_strcmp(
					"as",
					"aposafpaokf"
	);

	unit_test_strcmp(
					"aposafpaokf",
					"as"
	);

	unit_test_strcmp(
					"Hello World!",
					NULL
	);
}

void unit_test_strdup(char *s)
{
	mid_title();
	printf("strdup-ing \"%s\"(%p)\n", s, s);
	reset();
	char *strdupped = ft_strdup(s);
	printf("strdup-ed string : \"%s\"(%p)\n", strdupped, strdupped);
	free(strdupped);
}

void test_strdup()
{
	unit_test_strdup("henlo fren");
	char *str = "bonjour";
	unit_test_strdup(str);
	char str1[] = "heheheheheh";
	unit_test_strdup(str1);
}

void test_lists_print(t_list *list)
{
	while (list)
	{
		printf("value = %d\n", *((int *)list->data));
		list = list->next;
	}
}

void test_lists_free_fct(void *data)
{
	free(data);
}

int test_lists_cmp(void *a, void *b)
{
	return (*((int *)a) - *((int *)b));
}

void unit_test_normal_list()
{
	t_list		*list = NULL;
	t_list		*tmp;
	int			*value;
	int			values[SIZE];
	int			z;

	for (int i = 0; i < SIZE; i++)
	{
		if ((value = (int *)malloc(sizeof(int))))
		{
			*value = rand() % 100;
			values[i] = *value;
			ft_list_push_front(&list, value);
		}
	}

	mid_title();
	printf("Size of list = %d\n", ft_list_size(list));
	printf("Printing list (created with ft_list_push_front):\n");
	reset();
	test_lists_print(list);

	z = values[rand() % SIZE];
	mid_title();
	printf("\nRemoving all %d with ft_list_remove_if\n", z);
	reset();

	ft_list_remove_if(&list, &z, test_lists_cmp, test_lists_free_fct);
	test_lists_print(list);

	mid_title();
	printf("Trying to sort list... then display it...\n");
	reset();
	ft_list_sort(&list, test_lists_cmp);
	test_lists_print(list);

	printf("\n");
	mid_title();
	printf("Trying to sort without function\n");
	reset();
	ft_list_sort(&list, NULL);

	while (list)
	{
		tmp = list;
		list = list->next;
		if (tmp->data)
			test_lists_free_fct(tmp->data);
		free(tmp);
	}
}

void test_lists()
{
	srand(time(0));
	unit_test_normal_list();

	mid_title();
	printf("Trying ft_list_size on NULL\n");
	reset();
	printf("result : %d\n", ft_list_size(NULL));

	mid_title();
	printf("Trying ft_list_sort on NULL\n");
	reset();
	ft_list_sort(NULL, NULL);

	mid_title();
	printf("Trying ft_list_push_front on NULL\n");
	reset();
	ft_list_push_front(NULL, NULL);

	mid_title();
	printf("Trying to ft_list_remove_if on NULL\n");
	reset();
	ft_list_remove_if(NULL, NULL, NULL, NULL);
}

void unit_test_atoi_base(char *title, char *str, char *base)
{
	mid_title();
	printf("%s\n", title);
	reset();
	printf("str : %s in base : %s = %d\n", str, base, ft_atoi_base(str, base));
}

void tests_atoi_base()
{
	unit_test_atoi_base("Testing with normal inputs (base 10)", "42", "0123456789");
	unit_test_atoi_base("Testing with twisted inputs (base 10)", "fs", ".,safxvc4z");
	unit_test_atoi_base("Testing with normal inputs (base 5)", "431", "01234");
	unit_test_atoi_base("Testing with normal inputs (base 5)", "kch", "thick");

	unit_test_atoi_base("Testing with wrong base", "fs", ".,ssafxvc4z");
	unit_test_atoi_base("Testing with wrong number", "3fs", ".,safxvc4z");
	unit_test_atoi_base("Testing with wrong number and base", "3fs", ".s,safxvc4z");

	unit_test_atoi_base("Testing with NULL str", NULL, "0123456789");
	unit_test_atoi_base("Testing with NULL base", "42", NULL);
}

int main()
{
	fat_title();
	printf("TESTS ABOUT READ FUNCTION\n");
	reset();
	test_read();

	printf("\n-----------------------------------------------------------\n\n");
	fat_title();
	printf("TESTS ABOUT WRITE FUNCTION\n");
	reset();
	test_write();

	printf("\n-----------------------------------------------------------\n\n");
	fat_title();
	printf("TESTS ABOUT STRLEN FUNCTION\n");
	reset();
	test_strlen();

	printf("\n-----------------------------------------------------------\n\n");
	fat_title();
	printf("TESTS ABOUT STRCPY FUNCTION\n");
	reset();
	test_strcpy();

	printf("\n-----------------------------------------------------------\n\n");
	fat_title();
	printf("TESTS ABOUT STRDUP FUNCTION\n");
	reset();
	test_strdup();

	if (BONUS)
	{
		printf("\n-----------------------------------------------------------\n\n");
		printf("\n-----------------------------------------------------------\n\n");
		fat_title();
		printf("TESTING BONUSES\n\n\n");

		printf("TESTING LISTS\n");
		reset();
		test_lists();

		printf("\n-----------------------------------------------------------\n\n");
		mid_title();
		printf("TESTING FT_ATOI_BASE\n");
		reset();
		tests_atoi_base();
	}
	printf("\n-----------------------------------------------------------\n");
	printf("\t\t\t\t\tEnd of testing...\n");
	return (0);
}

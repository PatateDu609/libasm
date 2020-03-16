typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	if (!begin_list)
		return ;
	if (!*begin_list)
		return ;
	if (!(*begin_list)->next)
		return ;

	t_list *begin = *begin_list;
	t_list *current = begin;

	while (current->next)
	{
		if ((*cmp)(current->data, current->next->data) > 0)
		{
			void *temp = current->data;

			current->data = current->next->data;
			current->next->data = temp;
			current = begin;
		}
		else
			current = current->next;
	}
	*begin_list = begin;
}

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}

#include <stdio.h>
#include <string.h>
void	del(void *content)
{
	free(content);
}
int	main(void)
{
    t_list *node = malloc(sizeof(t_list));
    if (node == NULL)
	{
        printf("Memory allocation error\n");
        return 1;
    }

    node->content = strdup("Hello, World!");
    node->next = NULL;

    printf("Before deletion:\n");
    printf("Content: %s\n", (char *)node->content);

    ft_lstdelone(node, del);

    printf("After deletion:\n");
    printf("Content: %s\n", (char *)node->content);

    return 0;
}
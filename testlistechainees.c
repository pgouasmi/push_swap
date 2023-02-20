#include <stdio.h>
#include <stdlib.h>

typedef struct list_elem
{
	int		valeur;
	int		place;
	struct	list_elem *next;
}			list_elem;

list_elem**	new_stack()
{
	return (NULL);
}

list_elem* new_node(list_elem *list, char* str)
{
	list_elem *element;
		element = malloc(sizeof(*element));
		element->valeur = atoi(str);
		if (!list)
			element->next = NULL;
		else
			element->next = list;
		//printf("%d\n", element->valeur);
}

list_elem*	balance(list_elem *list, int argc, char **argv)
{
	int j;

	j = 0;
	while (++j < argc)
	{
		list = new_node(list, argv[j]);
	}
}

int	count_nodes(list_elem *list)
{
	int 	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

void	print_values(list_elem *list)
{
	while (list)
	{
		printf("%d", list->valeur);
		list = list->next;
	}
	printf("\n");
}

int main(int argc, char** argv)
{
	list_elem	*list;

	list = NULL;
	list = balance(list, argc, argv);
	print_values(list);
	printf("Nombre d'elements dans la liste : %d\n", count_nodes(list));
}
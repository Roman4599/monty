#include "monty.h"
#include <string.h>

/**
 * ft_strdup - Duplicate a string in a newly allocated memory
 * @str: the string to duplicate
 * Return: the duplicated string, NULL on malloc failure
 */
char	*ft_strdup(char *str)
{
	char	*copy;
	int		i;

	i = 0;
	copy = malloc(strlen(str) + 1);
	if (!copy)
		return (NULL);
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/**
 * free_stack - Free every node of the stack
 * @stack: the stack to free
 * Return: nothing
 */
void	free_stack(t_stack *stack)
{
	t_stack	*next;

	while (stack)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}

/**
 * free_instructions - Free every node of the list of the instructions
 * @instructions: the list of the instructions to free
 * Return: nothing
 */
void	free_instructions(t_instructions *instructions)
{
	t_instructions	*next;

	while (instructions)
	{
		next = instructions->next;
		free(instructions->op);
		free(instructions);
		instructions = next;
	}
}

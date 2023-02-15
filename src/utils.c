#include "lexer.h"

char	*ft_strndup(char const *s1, size_t n)
{
	size_t	i;
	char	*data;

	data = (char *)malloc(sizeof(char) * (n + 1));
	if (!data)
		return (0);
	i = 0;
	while (i < n)
	{
		data[i] = s1[i];
		i++;
	}
	data[i] = '\0';
	return (data);
}

void print_commands(t_list *commands)
{
    printf("    commands: \n");
    while (commands != NULL)
    {
        printf("        %s\n", (char*)commands->content);
        commands = commands->next;
    }
}
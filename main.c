#include "./libft/libft.h"
#include <stdio.h>

typedef enum e_label {
    COMMAND,
    PIPE,
} t_label;

typedef struct s_node {
    // struct s_node   *left;
    // struct s_node   *right;
    // struct s_node   *parent;
    struct s_node   *next;
    t_label         label;
    t_list          *commands;
    t_list          *filenames;
} t_node;

typedef enum e_redirect_type {
    INPUT,
    OUTPUT,
    APPEND_OUTPUT,
    HEREDOC_INPUT,
} t_redirect_type;

typedef struct s_redirection {
    t_redirect_type type;
    char            *filename;

} t_redirection;

static char	*ft_strndup(char const *s1, size_t n)
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

void extract(char *s, char *start, t_list **list)
{
    char *c;
    size_t n;

    if (s == start)
    {
        return ;
    }
    
    n = (s - start) / sizeof(char);
    c = ft_strndup(start, n);
    // printf("%s\n", c);
    ft_lstadd_back(list, ft_lstnew(c));
}

int istoken(char c)
{
    return ((c == ' ' || c == '|' || c == '<' || c == '>'));
}

//文字列を分割する
t_list *tokenizer(char *input)
{
    int     i;
    char *start;
    int     indquote;
    int     insquote;
    t_list  *list;

    list = NULL;
    
    indquote = 0;
    insquote = 0;
    start = input;
    i = 0;
    while (input[i] != '\0')
    {
        if (input[i] == '"' && !insquote)
        {
            indquote = !indquote;
        }
        if (input[i] == '\'' && !indquote)
        {
            insquote = !insquote;
        }
        if (istoken(input[i]) && !indquote && !insquote)
        {
            extract(&input[i], start, &list);
            start = &input[i+1];
            if (input[i] != ' ')
            {
                if (input[i] != '|' && input[i] == input[i+1])
                {
                    extract(&input[i+2], &input[i], &list);
                    start = &input[i+2];
                    i++;   
                }
                else
                    extract(&input[i+1], &input[i], &list);       
            }    
        }
        i++;
    }
    extract(&input[i], start, &list);
    return (list);
}
//変数inputの文字を一つ一つ構造体の変数contentsに入れる。

t_node *make_node()
{
    t_node *data;

    data = malloc(sizeof(t_node));
    if (!data)
    {
        exit(1);
    }
    data->commands = NULL;
    data->filenames = NULL;
    data->next = NULL;
    data->label = COMMAND;
    return (data);
}

t_redirection *make_redirection(t_list *now, t_list *next)
{
    t_redirection *data;

    data = malloc(sizeof(t_redirection));
    if (!data)
    {
        exit(1);
    }
    if (ft_strncmp(now->content, "<<", 2) == 0)
    {
        data->type = HEREDOC_INPUT;
    }
    else if (ft_strncmp(now->content, ">>", 2) == 0)
    {
        data->type = APPEND_OUTPUT;
    }
    else if (ft_strncmp(now->content, ">", 1) == 0)
    {
        data->type = OUTPUT;
    }
    else if (ft_strncmp(now->content, "<", 1) == 0)
    {
        data->type = INPUT;
    }
    if (next != NULL)
    {
        data->filename = next->content;
    }
    return (data);
}

t_node *lexer(t_list *tokens)
{
    t_list *next;
    t_list *now;
    t_node *node;
    t_node *head;

    now = tokens;
    //whileに入る前にノードを作る必要がある
    //リストに入ってる文字列comands filenames null
    head = make_node();
    node = head;
    while (now != NULL)
    {
        next = now->next;
        now->next = NULL;
        //nowがパイプラインだったとき新しくノードを作って元に戻る必要ある
        if (ft_strncmp((const char *)now->content, "|", 1) == 0)
        {
            node->next = make_node();
            node = node->next;
        }        
        else if (ft_strncmp((const char *)now->content, ">", 1) == 0)
        {
            ft_lstadd_back(&node->filenames, now);

        }
        else
        {
            ft_lstadd_back(&node->commands, now);
        }
        now = next;
    }
    return (head);
}

int main()
{
    t_list *list;
     
    char *input = "echo \"hello w\"'w | orld' ||  ; cat<<file|wc>>file2";
    list = tokenizer(input);
    while (list != NULL)
    {
        printf("%s\n", (char*)list->content);
        list = list->next;
    }
    
}
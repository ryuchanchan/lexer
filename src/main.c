#include "lexer.h"

void print_commands(t_list *commands)
{
    printf("    commands: \n");
    while (commands != NULL)
    {
        printf("        %s\n", (char*)commands->content);
        commands = commands->next;
    }
}

void print_filenames(t_list *filenames)
{
    t_redirection *redirection;

    printf("    filenames: \n");
    while (filenames != NULL)
    {
        redirection = (t_redirection *)filenames->content;
        printf("        type: ");
        if (redirection->type == INPUT)
            printf("INPUT");
        if (redirection->type == OUTPUT)
            printf("OUTPUT");
        if (redirection->type == APPEND_OUTPUT)
            printf("APPEND_OUTPUT");
        if (redirection->type == HEREDOC_INPUT)
            printf("HEREDOC_INPUT");
        printf("\n");

        printf("        filename: %s\n", (char *)redirection->filename);
        filenames = filenames->next;
    }
}


int main()
{
    t_list  *head;
    t_list  *list;
    t_node  *node;
    size_t  i;

    char *input = "echo \"hello w\"'w | orld' ||  ; cat<<file -l >< file2 -R|wc>>file2";
    list = tokenizer(input);
    head = list;
    printf("===== tokenize =====\n");
    while (list != NULL)
    {
        printf("%s\n", (char*)list->content);
        list = list->next;
    }
    printf("===== end tokenize =====\n");
    node = parser(head);
    printf("===== parser =====\n");
    i = 0;
    while (node != NULL)
    {
        printf("node: %zu\n", i);
        printf("    label: ");
        if (node->label == COMMAND)
            printf("COMMAND");
        if (node->label == PIPE)
            printf("PIPE");
        printf("\n");
        print_commands(node->commands);
        print_filenames(node->filenames);
        node = node->next;
        i++;
    }
    printf("===== end parser =====\n");
}
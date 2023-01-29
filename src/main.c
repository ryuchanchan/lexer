#include "lexer.h"
#include "unistd.h"
#include "fcntl.h"

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

// int make_pipe(t_list *list, int pipe_fd)
// {
//     int i;
//     int pid;

//     pid = fork()
//     i = 0;
//     while (list)
//     {
//         if (pid == 0)
//         {
//             dup(pipe_fd[1]);
//             close(pipe_fd[1]);
//         }
//         i++;
//     }
//     return NULL;
// }

int main()
{
    t_list  *head;
    t_list  *list;
    t_node  *node;
    size_t  i;

    t_pid pid;
    int status;

    int pipe_fd[2];
    extern char	**environ;
    int n;
    // char filepath[PATH_MAX + 1];
    char *argv[4];
    argv[0] = "/bin/cat/";
    argv[1] = "cat";
    argv[2] = "sample";
    argv[3] = NULL;
    execve(argv[0], argv, environ);
    // char *input = "echo \"hello w\"'w | orld' ||  ; cat<<file -l >< file2 -R|wc>>file2";
    char *input = "cat sample | grep a";
    list = tokenizer(input);
    head = list;
    i = 0;
    pid.pids = fork();
    if (pid.pids == 0)
    {
        // printf("===== tokenize =====\n");
        while (list != NULL)
        {
            argv[i+1] = (char*)list->content;
            printf("い%s\n", argv[0]);
            printf("あ%s\n", argv[i+1]);
            // execve(argv[0], argv, environ);
            if (i == 1)
            {
                exit(0);
            }
            // printf("%s\n", (char*)list->content);
            pipe(pipe_fd);
            // printf("%d", pipe_fd[0]);
            dup2(pipe_fd[0], 0);
            close(pipe_fd[0]);
            // make_pipe(list, pipe_fd);
            list = list->next;
            i++;
        }
        // printf("===== end tokenize =====\n");
        node = parser(head);
        // printf("===== parser =====\n");
        // i = 0;
        while (node != NULL)
        {
            // printf("node: %zu\n", i);
            // printf("    label: ");
            // if (node->label == COMMAND)
            //     printf("COMMAND");
            // if (node->label == PIPE)
            //     printf("PIPE");
            // printf("\n");
            // print_commands(node->commands);
            // print_filenames(node->filenames);
            node = node->next;
            // i++;
        }
    }
    else
    {
        close(pipe_fd[1]);//closeしないと処理抜けない
        pipe(pipe_fd);
        pid.pids = fork();
        if((pid.pids) == 0)
        {
            close(pipe_fd[0]);
            close(pipe_fd[1]);
        }
        n = read(pipe_fd[1], list->content, 4096);
        write(STDOUT_FILENO, list->content, n);
    }
    
    waitpid(pid.pids, &status, 0);
}
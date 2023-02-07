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

void print_filenames(t_list *filenames, int *fdout)
{
    t_redirection *redirection;

    // printf("    filenames: \n");
    while (filenames != NULL)
    {
        redirection = (t_redirection *)filenames->content;
        // printf("        type: ");
        // if (redirection->type == INPUT)
        //     printf("INPUT");
        // if (redirection->type == OUTPUT)
        //     printf("OUTPUT");
        // if (redirection->type == APPEND_OUTPUT)
        //     printf("APPEND_OUTPUT");
        // if (redirection->type == HEREDOC_INPUT)
        //     printf("HEREDOC_INPUT");
        // printf("\n");
        // printf("        filename: %s\n", (char *)redirection->filename);

        // printf("%s\n", (char *)redirection->filename);
        filenames = filenames->next;
        int fd = open((char *)redirection->filename, O_RDWR|O_CREAT|O_TRUNC, 0777);
        if (fd == -1)
        {
            perror("open");
            break ;
        }
        //fdoutの中身を変える
        close(*fdout);
        *fdout = fd;
        // dup2(fd, 1);
    }
}

char    **list_to_array(t_list *list)
{
    size_t  i;
    size_t  len;
    char    **arr;

    len = (size_t)ft_lstsize(list);
    arr = (char **)malloc(sizeof(char *) * (len + 1));
    if (!arr)
    {
        perror("list_to_array");
        exit(1);
    }
    i = 0;
    while (list != NULL)
    {
        arr[i++] = (char *)list->content;
        list = list->next;
    }
    arr[i] = NULL;
    return (arr);
}

int main()
{
    t_list  *head;
    t_list  *list;
    t_node  *node;
   // size_t  i;

    t_pid pid;
    int status;

    int pipe_fd[2];
    extern char	**environ;
    //int n;
    // char filepath[PATH_MAX + 1];
    // char *argv[4];
    // argv[0] = "/bin/cat/";
    // argv[1] = "sample";
    // argv[2] = NULL;
    // execve(argv[0], argv, environ);
    // perror(argv[0]);
    // exit(1);

    // char *input = "echo \"hello w\"'w | orld' ||  ; cat<<file -l >< file2 -R|wc>>file2";
    // char *input = "/bin/cat sample > test | /usr/bin/grep abc| /usr/bin/wc -l";
    char *input = "/bin/cat sample > test1";

    list = tokenizer(input);
    head = list;
    // i = 0;
    // pid.pids = fork();
    // if (pid.pids == 0)
    // {
    //     // printf("===== tokenize =====\n");
    //     while (list != NULL)
    //     {
    //         argv[i+1] = (char*)list->content;
    //         printf("い%s\n", argv[0]);
    //         printf("あ%s\n", argv[i+1]);
    //         // execve(argv[0], argv, environ);
    //         if (i == 1)
    //         {
    //             exit(0);
    //         }
    //         // printf("%s\n", (char*)list->content);
    //         pipe(pipe_fd);
    //         // printf("%d", pipe_fd[0]);
    //         dup2(pipe_fd[0], 0);
    //         close(pipe_fd[0]);
    //         // make_pipe(list, pipe_fd);
    //         list = list->next;
    //         i++;
    //     }
    // printf("===== end tokenize =====\n");
    node = parser(head);
    //printf("===== parser =====\n");
    // i = 0;
    /*
    (void)pipe_fd;
    while (node != NULL)
    {
        printf("=========\n");
        print_commands(node->commands);
        node = node->next;
    }
    exit(0);
    */

    int tmpin = dup(0);
    int tmpout = dup(1);
    int fdin;
    int fdout;

    fdin = dup(tmpin);
    while (node != NULL)
    {
        t_list *commands = node->commands;
        /* Todo:fdinを入力リダイレクション(< or <<)で上書きする処理 */

        dup2(fdin, 0);
        close(fdin);
        if (node->next != NULL)
        {
            pipe(pipe_fd);
            fdout = pipe_fd[1];
            fdin = pipe_fd[0];
        } else {
            fdout = dup(tmpout);
        }
        /* Todo:fdoutを出力リダイレクション(> or >>)で上書きする処理 */
        print_filenames(node->filenames, &fdout);

        // print_commands(node->commands);
        dup2(fdout, 1);
        close(fdout);
        
        char **arr = list_to_array(commands);
        pid.pids = fork();
        if (pid.pids == 0)
        {
            execve(arr[0], arr, environ);
            perror(arr[0]);
            exit(1);
        }
        free(arr);
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
    dup2(tmpin,0);
    dup2(tmpout,1);
    close(tmpin);
    close(tmpout);

    // else
    // {
    //     close(pipe_fd[1]);//closeしないと処理抜けない
    //     pipe(pipe_fd);
    //     pid.pids = fork();
    //     if((pid.pids) == 0)
    //     {
    //         close(pipe_fd[0]);
    //         close(pipe_fd[1]);
    //     }
    //     n = read(pipe_fd[1], list->content, 4096);
    //     write(STDOUT_FILENO, list->content, n);
    // }

    waitpid(pid.pids, &status, 0);
}
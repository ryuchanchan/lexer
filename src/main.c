#include "lexer.h"
#include "unistd.h"
#include "fcntl.h"
#include <readline/readline.h>
#include <stdbool.h>

void redirect_input(t_list *filenames, int *fdin)
{
    int             fd;
    t_redirection   *redirection;

    while (filenames != NULL)
    {
        redirection = (t_redirection *)filenames->content;
        if (redirection->type == INPUT)
            fd = open((char *)redirection->filename, O_RDONLY);
        else if (redirection->type == HEREDOC_INPUT)
            fd = do_heredoc(redirection->filename);
        else
        {
            filenames = filenames->next;
            continue ;
        }
        if (fd < 0)
            perror("minishell");
        else
        {
            close(*fdin);
            *fdin = fd;
        }
        filenames = filenames->next;
    }
}

void redirect_output(t_list *filenames, int *fdout)
{
    int             fd;
    t_redirection   *redirection;

    while (filenames != NULL)
    {
        redirection = (t_redirection *)filenames->content;
        if (redirection->type == OUTPUT)
        {
            fd = open((char *)redirection->filename, O_RDWR|O_CREAT|O_TRUNC, 0777);
        }
        else if (redirection->type == APPEND_OUTPUT)
            fd = open((char *)redirection->filename, O_RDWR|O_CREAT|O_APPEND, 0777);
        else
        {
            filenames = filenames->next;
            continue ;
        }
        if (fd < 0)
            perror("minishell");
        else
        {
            close(*fdout);
            *fdout = fd;
        }
        filenames = filenames->next;
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
    t_pid pid;
    int status;

    int pipe_fd[2];
    extern char	**environ;

    // char *input = "echo \"hello w\"'w | orld' ||  ; cat<<file -l >< file2 -R|wc>>file2";
    // char *input = "/bin/cat sample > test | /usr/bin/grep abc| /usr/bin/wc -l";
    // char *input = "/bin/cat sample > test1";
    // char *input = "/bin/cat sample >> test1";//この場合open()のflagをappend
    // char *input = "/bin/cat sample < test1";//読み込み専用O_RDONLY エラー処理
    char *input = "/bin/cat <<EOF >>sample_copy.txt";

    // char *input = "/bin/cat sample < test1 | /bin/cat sample > test1";//読み込み失敗してファイル書き込む


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
    // printf("fdin = %d\n", fdin);
    while (node != NULL)
    {
        t_list *commands = node->commands;
        /* Todo:fdinを入力リダイレクション(< or <<)で上書きする処理 */
        redirect_input(node->filenames, &fdin);
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
       redirect_output(node->filenames, &fdout);
        // print_commands(node->commands);
        dup2(fdout, 1);
        close(fdout);
        
        char **arr = list_to_array(commands);
        printf("before execve\n");
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
    }
    dup2(tmpin,0);
    dup2(tmpout,1);
    close(tmpin);
    close(tmpout);
    waitpid(pid.pids, &status, 0);
}
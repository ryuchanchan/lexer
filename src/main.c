#include "lexer.h"

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
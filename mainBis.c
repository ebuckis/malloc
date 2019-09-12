#include "ft_malloc.h"

int main()
{
    char *str1 = "salut";
    char *str2 = " connard";

    for (int i = 0; i < 15; i++)
        putchar(str1[i]);
    return 0;
}
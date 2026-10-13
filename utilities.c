#include <unistd.h>

int ft_strlen(char *str)
{
    int i; 
    i = 0;

    while(str[i])
    {
        i++;
    }
    return (i);
}

void    ft_putstr(char *str)
{
    if (!str)
        return; 
    write(1, str, ft_strlen(str));
}

void flush_stdin()
{
    char buffer[120];

    while (read(0, buffer, 120) == 120); //flush manual;

}

int ft_strcmp(char *s1, char *s2)
{
    while(*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return(*s1 - *s2);   
}
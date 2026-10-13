#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "game.h"

/*Princess escape :  sortir de la tour avec la cle*/

/*Prototypes*/
int ft_strlen(char *str);
void    ft_putstr(char *str);
void flush_stdin();
int ft_strcmp(char *s1, char *s2);

void ft_fgets(char *buffer, int len)
{
    int bytes_len;
    bytes_len = 0;

    bytes_len = read(0, buffer, len);

    if (bytes_len <= 0)
        return;

    if(buffer[bytes_len - 1] != '\n')
         flush_stdin(); //flush
    else 
        buffer[bytes_len - 1] = '\0';
}


int main(void)
{
    /*definir pieces*/
    t_room chambre = {"Chambre", "Chambre royale. \nLumineuse.\nA gauche Salle de Jeux\n", NULL, };

    t_princess princesse = {"", &chambre};
    
    char commandes[420];

    ft_putstr("Vous vous réveillez dans le noir. Quelle est votre nom ?\n");
    ft_fgets(princesse.nom, 42);

    ft_putstr("> Bonjour Princesse ");
    ft_putstr(princesse.nom);
    ft_putstr(". Essayez de 'regarder' autour de vous.\n"); 
    
    while(1)
    {
        /*lire des commandes*/
        ft_fgets(commandes, 420);

        if (ft_strcmp(commandes, "quitter") == 0)
        {
            ft_putstr("> On sort du jeu.\n");
            return(0);
        }
        else if (ft_strcmp(commandes, "regarder") == 0)
        {
            ft_putstr(princesse.current_room->description);
        }
    }

    return (0);
}

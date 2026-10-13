#ifndef GAME_H
#define GAME_H

typedef struct s_room
{
    char nom[42];
    char description[250];
    struct s_room *gauche;
    struct s_room *droite;
    struct s_room *haut;
    struct s_room *bas;

} t_room;

typedef struct  s_princess
{
    char nom[42];

    t_room *current_room;    
} t_princess;

#endif
#pragma once
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System/Vector2.h>
#define n 10
sfRenderWindow* window;
enum type {pink, orange, yellow, green, blue, violet};
typedef struct{
    sfTexture* texture;
    sfSprite* sprite;
    sfVector2f pos;
    enum type color;

} gem;
gem field[n][n];

typedef struct{
    sfTexture* texture;
    sfSprite* sprite;
    sfVector2f pos;
    int x, y;
}p;
p pointer;

int game_data [n][n];

int score[2];

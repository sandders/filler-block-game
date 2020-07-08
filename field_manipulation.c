#include "field_manipulation.h"
#include"game_data.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>

void first_fill(){
int tmp;
    for(int i = 0, y = 0; i<n; i++, y+=74){
        for(int j =0, x = 0; j<n; j++, x+=74){
            field[i][j].pos.x = x;
            field[i][j].pos.y = y;
            tmp = rand()%6;
            field[i][j].color = tmp;
            switch(tmp){
            case 0:
                field[i][j].texture = sfTexture_createFromFile("pink.png", NULL);
                //field[i][j].color = pink;
                break;
            case 1:
                field[i][j].texture = sfTexture_createFromFile("orange.png", NULL);
                //field[i][j].color = orange;
                break;
            case 2:
                field[i][j].texture = sfTexture_createFromFile("yellow.png", NULL);
                //field[i][j].color = yellow;
                break;
            case 3:
                field[i][j].texture = sfTexture_createFromFile("green.png", NULL);
                //field[i][j].color = green;
                break;
            case 4:
                field[i][j].texture = sfTexture_createFromFile("blue.png", NULL);
                //field[i][j].color = blue;
                break;
            case 5:
                field[i][j].texture = sfTexture_createFromFile("violet.png", NULL);
                //field[i][j].color = violet;
                break;
            }
            if (!field[i][j].texture) return 1;
            field[i][j].sprite = sfSprite_create();
            sfSprite_setTexture(field[i][j].sprite, field[i][j].texture, sfTrue);
            sfSprite_setPosition(field[i][j].sprite, field[i][j].pos);
        }
    }
    //while(field)
}

void render_field(){
    for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                sfRenderWindow_drawSprite(window, field[i][j].sprite, NULL);
            }
        }
}

void color_change(int i, int j, int color)
{
            switch(color){
            case 0:
                sfTexture_destroy(field[i][j].texture);
                field[i][j].texture = sfTexture_createFromFile("pink.png", NULL);
                field[i][j].color = pink;
                break;
            case 1:
                sfTexture_destroy(field[i][j].texture);
                field[i][j].texture = sfTexture_createFromFile("orange.png", NULL);
                field[i][j].color = orange;
                break;
            case 2:
                sfTexture_destroy(field[i][j].texture);
                field[i][j].texture = sfTexture_createFromFile("yellow.png", NULL);
                field[i][j].color = yellow;
                break;
            case 3:
                sfTexture_destroy(field[i][j].texture);
                field[i][j].texture = sfTexture_createFromFile("green.png", NULL);
                field[i][j].color = green;
                break;
                sfTexture_destroy(field[i][j].texture);
            case 4:
                sfTexture_destroy(field[i][j].texture);
                field[i][j].texture = sfTexture_createFromFile("blue.png", NULL);
                field[i][j].color = blue;
                break;
            case 5:
                sfTexture_destroy(field[i][j].texture);
                field[i][j].texture = sfTexture_createFromFile("violet.png", NULL);
                field[i][j].color = violet;
                break;
            }
            sfSprite_setTexture(field[i][j].sprite, field[i][j].texture, sfTrue);
            sfRenderWindow_drawSprite(window, field[i][j].sprite, NULL);
}


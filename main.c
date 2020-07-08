#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Keyboard.h>
#define n 10 //³ â game_data.h
#include "game_data.h"
#include "field_manipulation.h"
#include "data_manipulation.h"
int main()
{
    int cx, cy;
    srand((unsigned int)time(NULL));
    printf("\"Filler\". The purpose of the game is to paint more colored cells than a computer. \nAt the beginning of the game, the territory of the player - in the upper left corner, \nthe territory of the computer - in the lower right. \n");
    printf("You can only select cells that are located next to the existing territory. \nAfter move, the territory acquires the color of the chosen cell, and all the adjacent cells of the same color join it. \nYou can not select cells in the color of the opponent's territory.\n");
    sfVideoMode mode = {n*74-2, n*74-2, 32};

    sfColor white = {255, 255, 255, 255};
    first_fill();
    pointer.texture = sfTexture_createFromFile("selected.png", NULL);
    pointer.sprite = sfSprite_create();
    sfSprite_setTexture(pointer.sprite, pointer.texture, sfTrue);
    pointer.pos.x = pointer.x = 0;
    pointer.pos.y = pointer.y = 0;
    zero(n);
    game_data[0][0] =1;
    game_data[n-1][n-1] = 3;
    brush_p(n);
    while(color_check_p(n))brush_p(n);
    window = sfRenderWindow_create(mode, "Filler", sfClose | sfResize, NULL);
    sfEvent screen;

    while (sfRenderWindow_isOpen(window)){
        while (sfRenderWindow_pollEvent(window, &screen))
            if (screen.type == sfEvtClosed){
                sfRenderWindow_close(window);
                printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
                printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
                printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
                printf("\n\nEnd of game\n\n");
                printf("Maybe next time!\n");
            }
        sfRenderWindow_clear(window, white);
        render_field();
        if(field[1][0].color == field[0][1].color&&field[0][1].color == field[n-1][n-1].color)
        {
            sfSprite_setPosition(pointer.sprite, pointer.pos);
            sfRenderWindow_drawSprite(window, pointer.sprite, NULL);

            sfRenderWindow_display(window);
            printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("\n\nEnd of game\n\n");
            printf("You lost because of random. Try again next time!\n");
           // system("PAUSE");
            sfRenderWindow_close(window);
            return 0;
        }

        else if(continue_check(n)){
        brush_p(n);



        if(sfKeyboard_isKeyPressed(sfKeyUp)&&pointer.y>0)
           {
               pointer.pos.y-=74;
               pointer.y--;
               Sleep(200);
           }
        else if(sfKeyboard_isKeyPressed(sfKeyDown)&&pointer.y<n-1)
           {
               pointer.pos.y+=74;
               pointer.y++;
               Sleep(200);
           }
        else if(sfKeyboard_isKeyPressed(sfKeyRight)&&pointer.x<n-1)
           {
               pointer.pos.x+=74;
               pointer.x++;
               Sleep(200);
           }
        else if(sfKeyboard_isKeyPressed(sfKeyLeft)&&pointer.x>0)
           {
               pointer.pos.x-=74;
               pointer.x--;
               Sleep(200);
           }
        else if(sfKeyboard_isKeyPressed(sfKeyEnter))
           {
               if(game_data[pointer.y][pointer.x]==2&&field[pointer.y][pointer.x].color!=field[n-1][n-1].color)
               {


                    for(int i =0; i<n; i++)
                    {
                        for(int j = 0; j<n; j++)
                        {
                            if(game_data[i][j] == 1)color_change(i,j,field[pointer.y][pointer.x].color);
                            brush_p(n);
                            while(color_check_p(n))brush_p(n);

                        }
                    }
                    Sleep(500);
                    brush_c(n);
                    color_check_c(n);
                    brush_c(n);
                    if(computer_check(n)){
                    do
                    {
                        cy=rand()%n;
                        cx=rand()%n;
                    }while((game_data[cy][cx]!=4||field[cy][cx].color==field[0][0].color));
                    }
                    for(int i =0; i<n; i++)
                    {
                        for(int j = 0; j<n; j++)
                        {
                            if(game_data[i][j] == 3)color_change(i,j,field[cy][cx].color);
                            brush_c(n);
                            while(color_check_c(n))brush_c(n);
                        }
                    }
                    if(!continue_check(n))
                    {
                        sfSprite_setPosition(pointer.sprite, pointer.pos);
                        sfRenderWindow_drawSprite(window, pointer.sprite, NULL);

                        sfRenderWindow_display(window);
                        score_check(n);
                        printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
                        printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
                        printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
                        printf("\n\nEnd of game\n\n");
                        printf("Your score: %d\n", score[0]);
                        printf("Computer score: %d\n", score[1]);
                        if(score[0]>score[1]) printf("Congratulations, you won!\n");
                        else if (score[1]>score[0]) printf("You lost. Try again next time!\n");
                        else printf("It's a draw!\n");
                        //system("PAUSE");
                        sfRenderWindow_close(window);
                        return 0;
                    }

                }

            }

        sfSprite_setPosition(pointer.sprite, pointer.pos);
        sfRenderWindow_drawSprite(window, pointer.sprite, NULL);

        sfRenderWindow_display(window);
        }
        else
        {
            score_check(n);
            printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("Your score: %d\n", score[0]);
            printf("Computer score: %d\n", score[1]);
            if(score[0]>score[1]) printf("Congratulations, you won!\n");
            else if (score[1]>score[0]) printf("You lost. Try again next time!\n");
            else printf("It's a draw!\n");
            //system("PAUSE");
            sfRenderWindow_close(window);
        }
    }
    return 0;
}

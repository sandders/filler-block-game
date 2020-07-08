#include "game_data.h"
#include "data_manipulation.h"

void zero(int p){
    for (int i = 0; i<p; i++)
    {
        for(int j =0; j<p; j++)
        {
            game_data[i][j] = 0;
        }
    }
}

void brush_p(int p)
{
    for (int i = 0; i<p; i++)
    {
        for(int j = 0; j<p-1; j++)
        {
            if(game_data[i][j] == 1&&game_data[i][j+1]!=1&&game_data[i][j+1]!=3) game_data[i][j+1]=2;
        }
    }
    for (int i = 0; i<p; i++)
    {
        for(int j = p-1; j>0; j--)
        {
            if(game_data[i][j] == 1&&game_data[i][j-1]!=1&&game_data[i][j-1]!=3) game_data[i][j-1]=2;
        }
    }
    for (int j = 0; j<p; j++)
    {
        for(int i =0; i<p-1; i++)
        {
            if(game_data[i][j] == 1&&game_data[i+1][j]!=1&&game_data[i+1][j]!=3) game_data[i+1][j]=2;
        }
    }
    for (int j = 0; j<p; j++)
    {
        for(int i =p-1; i>0; i--)
        {
            if(game_data[i][j] == 1&&game_data[i-1][j]!=1&&game_data[i-1][j]!=3) game_data[i-1][j]=2;
        }
    }
}

void brush_c(int p)
{
    for (int i = 0; i<p; i++)
    {
        for(int j = 0; j<p-1; j++)
        {
            if(game_data[i][j] == 3&&game_data[i][j+1]!=3&&game_data[i][j+1]!=1) game_data[i][j+1]=4;
        }
    }
    for (int i = 0; i<p; i++)
    {
        for(int j = p-1; j>0; j--)
        {
            if(game_data[i][j] == 3&&game_data[i][j-1]!=3&&game_data[i][j-1]!=1) game_data[i][j-1]=4;
        }
    }
    for (int j = 0; j<p; j++)
    {
        for(int i =0; i<p-1; i++)
        {
            if(game_data[i][j] == 3&&game_data[i+1][j]!=3&&game_data[i+1][j]!=1) game_data[i+1][j]=4;
        }
    }
    for (int j = 0; j<p; j++)
    {
        for(int i =p-1; i>0; i--)
        {
            if(game_data[i][j] == 3&&game_data[i-1][j]!=3&&game_data[i-1][j]!=1) game_data[i-1][j]=4;
        }
    }
}


int color_check_p(int p)
{
    int counter = 0;
    for (int i = 0; i<p; i++)
    {
        for(int j = 0; j<p; j++)
        {
            if(game_data[i][j]==2&&field[i][j].color == field[0][0].color)
            {
                    game_data[i][j]=1;
                    counter++;
            }
        }
    }
    return counter;
}
int color_check_c(int p)
{
    int counter = 0;

    for (int i = 0; i<p; i++)
    {
        for(int j = 0; j<p; j++)
        {
            if(game_data[i][j]==4&&field[i][j].color == field[p-1][p-1].color)
            {
                game_data[i][j]=3;
                counter++;
            }
        }
    }
    return counter;
}


int continue_check(int p)
{
    brush_p(p);
    int counter = 0;
    for(int i = 0; i<p; i++)
    {
        for(int j = 0; j<p; j++)
        {
            if(game_data[i][j]==2||game_data[i][j]==0)
            {
                if (field[i][j].color!=field[p-1][p-1].color) counter++;
            }
        }
    }
    if(counter ==0)return 0;
    return 1;
}

void score_check(int p)
{
    score[0] = score[1] = 0;
    for(int i =0; i<p; i++)
    {
        for(int j = 0; j<p; j++)
        {
            if(game_data[i][j]==1) score[0]++;
            if(game_data[i][j]==3) score[1]++;
        }
    }
}
int computer_check(int p)
{
    brush_c(p);
    int counter = 0;
    for(int i = 0; i<p; i++)
    {
        for(int j = 0; j<p; j++)
        {
            if(game_data[i][j]==4||game_data[i][j]==0)
            {
                if (field[i][j].color!=field[0][0].color) counter++;
            }
        }
    }
    if(counter ==0)return 0;
    return 1;
}

/*
 * game.cpp
 *
 * Authors: Scoban Pham (170944430), Brianna Nguyen (180856030)
 *
 * Description: game file is home to the drawings, this includes the grid, snake, and food
 */
#include <GL/glut.h>
#include <iostream>
#include <ctime>
#include "game.hpp"

int rows = 0, columns = 0;
int snakeMovement = RIGHT;
int xFood, yFood;
int xPosn[MAX + 1] = {4, 3, 2, 1, 0, -1, -1};
int yPosn[MAX + 1] = {10, 10, 10, 10, 10, 10, 10};
int length = 5;
bool increaseLength = false;
bool food = false;
extern int score;
extern int gameStatus;

void square(int x,int y)
{
    glLoadIdentity();
    if(x==0||x==columns-1||y==0||y==rows-1)
    {
        glLineWidth(4.0);
        glColor3f(0.0,0.0,0.0);
    }
    else
    {
        glColor3f(0.0,0.0,0.0);
        glLineWidth(1.0);
    }
    glBegin(GL_LINES);
        glVertex2d(x,y); glVertex2d(x+1,y);
        glVertex2d(x+1,y); glVertex2d(x+1,y+1);
        glVertex2d(x+1,y+1); glVertex2d(x,y+1);
        glVertex2d(x,y+1); glVertex2d(x,y);
    glEnd();
}
int randomizer(int min,int max)
{
    return min + rand() % (max - min);
}

void setGrid(int x,int y){
    columns = x;
    rows = y;
}

void drawGrid(){
    for(int i =0;i<columns;i++){
        for(int j=0;j<rows;j++)
            {square(i,j);}
    }
}

void drawSnake()
{
    for(int i = length-1; i > 0 ; i--)
    {
    	xPosn[i] = xPosn[i-1];
        yPosn[i] = yPosn[i-1];
    }
    for(int i=0;i<length;i++)
    {
        glColor3f(0.0,1.0,0.0);
        if(i==0){
            glColor3f(0.0,0.5,0.0);
            switch(snakeMovement)
            {
            case UP:
            	yPosn[i]++;
                break;
            case DOWN:
            	yPosn[i]--;
                break;
            case RIGHT:
            	xPosn[i]++;
                break;
            case LEFT:
            	xPosn[i]--;
                break;
            }
            if(xPosn[i]==0||xPosn[i]==columns-1||yPosn[i]==0||yPosn[i]==rows-1)
            	gameStatus = 1;
            else if(xPosn[i]==xFood && yPosn[i]==yFood)
            {
                food=false;
                score++;
                if(length<=MAX){
                	increaseLength=true;
                }
            }
            for(int j=1;j<length;j++)
            {
                if(xPosn[j]==xPosn[0] && yPosn[j]==yPosn[0])
                	gameStatus = 1;
            }
        }
        glBegin(GL_QUADS);
            glVertex2d(xPosn[i],yPosn[i]); glVertex2d(xPosn[i]+1,yPosn[i]); glVertex2d(xPosn[i]+1,yPosn[i]+1); glVertex2d(xPosn[i],yPosn[i]+1);
        glEnd();
    }
    if(increaseLength)
    {
        length++;
        increaseLength=false;
    }
}

void drawFood()
{
    if(!food)
    {
    	xFood=randomizer(2,columns-2);
    	yFood=randomizer(2,rows-2);
        food=true;
    }
    glBegin(GL_QUADS);
    	glColor3f(1.0,0.5,0.0);
        glVertex2d(xFood,yFood); glVertex2d(xFood+1,yFood); glVertex2d(xFood+1,yFood+1); glVertex2d(xFood,yFood+1);
    glEnd();
}

void reset(){
	snakeMovement = RIGHT;
	length = 5;
	increaseLength = false;
	food = false;
	score = 0;
	int xPosn_reset[MAX + 1] = {4, 3, 2, 1, 0, -1, -1};
	int yPosn_reset[MAX + 1] = {10, 10, 10, 10, 10, 10, 10};

	for(int i = 0; i < MAX + 1; i++){
		xPosn[i] = xPosn_reset[i];
		yPosn[i] = yPosn_reset[i];
	}

}

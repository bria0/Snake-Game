/*
 * CP411 Project: Snake Game
 *
 * Authors: Scoban Pham (170944430), Brianna Nguyen (180856030)
 *
 * Description: main.cpp is the main file is a game of 2D snake that keeps track of the final score.
 *              This integrates gameStart.cpp, gameOver.cpp, and game.cpp into a executable game.
 *              The starting screen awaits user input (SPACE bar) to begin the Snake Game.
 *              Once users fail (run into a border or the snake itself), end screen will await users
 *              to restart the game using SPACE key.
 */

#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include "game.hpp"
#include "gameOver.hpp"
#include "gameStart.hpp"

#define ROWS 40.0
#define COLUMNS 40.0
GLint winWidth = 600, winHeight = 600;

int gameStatus = 0;
extern int snakeMovement;
int score=0;

using namespace std;

void init()
{
    glClearColor(0.0,0.0,0.0,0.0);
    setGrid(COLUMNS,ROWS);
}

void keyboard(unsigned char key, int x, int y){

	if (gameStatus != 2){
		switch (key){
		case 32:
			reset();
			gameStatus = 2;
		}
	}
}

void display()
{
	switch(gameStatus){
	case 0:
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f );
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		drawGameStart();
	 break;
	case 1:
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f );
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		drawGameOver();
	 break;
	case 2:
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f );
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
        drawGrid();
        drawFood();
        drawSnake();
     break;
	}
    glutSwapBuffers();

}

void winReshapeFcn(GLint newWidth, GLint newHeight) {
    glViewport(0,0,(GLfloat)newWidth,GLfloat(newHeight));
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}
void frameRefresh(int)
{
    glutPostRedisplay();
    glutTimerFunc(80,frameRefresh,0);
}
void directionSwitch(int uInput,int x,int y)
{
	if (gameStatus == 2){
	    switch(uInput)
	    {
	    case GLUT_KEY_LEFT:
	        if(snakeMovement!=RIGHT)
	        	snakeMovement=LEFT;
	        break;
	    case GLUT_KEY_RIGHT:
	        if(snakeMovement!=LEFT)
	        	snakeMovement=RIGHT;
	        break;
	    case GLUT_KEY_UP:
	        if(snakeMovement!=DOWN)
	        	snakeMovement=UP;
	        break;
	    case GLUT_KEY_DOWN:
	        if(snakeMovement!=UP)
	        	snakeMovement=DOWN;
	        break;
	    }
	}

}

int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(100,100);
	glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("SNAKE GAME");

    init();

    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutReshapeFunc(winReshapeFcn);
    glutSpecialFunc(directionSwitch);
    glutTimerFunc(100,frameRefresh,0);

    glutMainLoop();

    return 0;
}

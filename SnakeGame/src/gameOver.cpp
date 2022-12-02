/*
 * gameOver.cpp
 *
 * Authors: Scoban Pham (170944430), Brianna Nguyen (180856030)
 * Date: December 7th, 2021
 * Description: gameOver is the ending screen for Snake Game, displays final score that users
 *              achieved in the current run.
 */
#include <GL/glut.h>
#include <sstream>
#include <iostream>
#include <string>

extern int score;
using namespace std;

void drawGameOver(){
	unsigned char string[] = "GAME OVER";
	unsigned char string2[] = "Your final score is: ";
	unsigned char string3[] = "Press SPACE to play again!";
	unsigned char sc = '0' + score;

	glRasterPos2f(17, 25);
	glColor3f(1.0, 0., 0.);
	for (int i = 0; i < 9; i++) {
	    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
	}
	glRasterPos2f(13, 22);
	for (int i = 0; i < 22; i++) {
	    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string2[i]);
	}
	glRasterPos2f(25, 22);
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13, sc);

	glRasterPos2f(13, 17);
	for (int i = 0; i < 26; i++) {
	    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string3[i]);
	}
}

/*
 * gameStart.cpp
 *
 * Authors: Scoban Pham (170944430), Brianna Nguyen (180856030)
 * Date: December 7th, 2021
 *
 * Description: gameStart implements the starting screen for Snake Game displaying
 *              the title, authors, and instructions.
 */
#include <GL/glut.h>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

void drawGameStart(){
	unsigned char string[] = "SNAKE GAME";
	unsigned char string2[] = "By Brianna Nguyen and Scoban Pham";
	unsigned char string3[] = "Press SPACE to continue";

	glRasterPos2f(17, 25);
	glColor3f(0.0, 0.5, 0.0);
	for (int i = 0; i < 10; i++) {
	    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
	}
	glRasterPos2f(11, 22);
	for (int i = 0; i < 34; i++) {
	    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string2[i]);
	}
	glRasterPos2f(13, 14);
	for (int i = 0; i < 23; i++) {
	    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string3[i]);
	}

}


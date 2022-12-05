/*
 * game.hpp
 *
 * Authors: Scoban Pham (170944430), Brianna Nguyen (180856030)
 */
#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define MAX 50
#define UP 1
#define RIGHT 2
#define DOWN -1
#define LEFT -2

void square(int, int);
int randomizer(int, int);
void setGrid(int,int);
void drawGrid();
void drawFood();
void drawSnake();
void reset();

#endif // GAME_H_INCLUDED

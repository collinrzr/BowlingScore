#ifndef BowlingScores_h
#define BowlingScores_h

#include <string>

const int MAXROLLS = 21; 
const int MAXFRAMES = 10;

void setArrays(int rolls[], int frameScores[]);
void calculateScores(int rolls[], int frameScores[], int currentFrame);
void printScores(int rolls[], int frameScores[], int currentFrame);

#endif 
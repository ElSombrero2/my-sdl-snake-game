#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <SDL2/SDL.h>

#include <ctime>
#include <cstdlib>

#include "collection.h"
#define SIZE 20
#define H 20
#define W 25
#define MILLIS 60

int randomize(int);

enum Direction{UP,DOWN,LEFT,RIGHT};

class Vector{
private:
    int x,y;
public:
    Vector(int,int);
    Vector();
    int getX();
    int getY();
    void setX(int);
    void setY(int);
    void setXY(int,int);
};

class Food{
private:
    Vector* pos;
public:
    Food();
    void generate();
    void draw(SDL_Renderer*);
    int isEat(Vector);
};

class Snake{
private:
    Queue<Vector>* q;
    Direction dir;
public:    
    Snake(int);
    void draw(SDL_Renderer*);
    void grow();
    void move(SDL_Event);
    void update(Food*);
    int isDied();
};


#endif
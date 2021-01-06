#include <iostream>
#include "snake.h"

int randomize(int size){return rand()%size;}

#pragma region Vector

Vector::Vector(int x,int y){this->setXY(x,y);}

Vector::Vector(){this->setXY(0,0);}

void Vector::setXY(int x,int y)
{
    this->x=x;
    this->y=y;
}

void Vector::setX(int x){this->x=x;}

void Vector::setY(int y){this->y=y;}

int Vector::getX(){return this->x;}

int Vector::getY(){return this->y;}

#pragma endregion

#pragma region Food

Food::Food(){this->pos=new Vector(randomize(W),randomize(H));}

void Food::generate()
{
    int x=randomize(W);
    int y=randomize(H);
    this->pos->setXY(x,y);
}

void Food::draw(SDL_Renderer* ren)
{
    SDL_Rect p={pos->getX()*SIZE,pos->getY()*SIZE,SIZE-1,SIZE-1};
    SDL_SetRenderDrawColor(ren,0,0,0,255);
    SDL_RenderFillRect(ren,&p);
}

int Food::isEat(Vector v)
{
    if(this->pos->getX()==v.getX()&&this->pos->getY()==v.getY())
        return 1;
    return 0;
}

#pragma endregion

Snake::Snake(int l)
{
    if(l<1)exit(-1);
    this->q=new Queue<Vector>();
    for(int i=0;i<l;i++)this->q->push(Vector(10,10));
    this->dir=RIGHT;
}

void Snake::grow()
{
    int x=this->q->peekLast().getX();
    int y=this->q->peekLast().getY();
    this->q->push(Vector(x,y));
}

int Snake::isDied()
{
    int x=this->q->peekLast().getX();
    int y=this->q->peekLast().getY();
    Node<Vector> *tmp=this->q->getFirst();
    while(tmp!=NULL)
    {
        Vector v=tmp->value;
        if(x==v.getX()&&y==v.getY())return 1;
        tmp=tmp->next;
        if(tmp->next==NULL)break;
    }
    return 0;
}

void Snake::draw(SDL_Renderer* ren)
{
    Vector* array=this->q->toArray();
    SDL_SetRenderDrawColor(ren,255,0,0,255);
    for(int i=0;i<this->q->count();i++){
        SDL_Rect p={array[i].getX()*SIZE,array[i].getY()*SIZE,SIZE-1,SIZE-1};
        SDL_RenderFillRect(ren,&p);
    }
}

void Snake::move(SDL_Event e)
{
    if(e.type==SDL_KEYDOWN){
        switch (e.key.keysym.sym)
        {
            case SDLK_UP:{
                if(dir!=UP&&dir!=DOWN)
                dir=UP;
                break;
            }
            case SDLK_LEFT:{
                if(dir!=LEFT && dir!=RIGHT)
                dir=LEFT;
                break;
            }
            case SDLK_RIGHT:{
                if(dir!=LEFT && dir!=RIGHT)
                dir=RIGHT;
                break;
            }
            case SDLK_DOWN:{
                if(dir!=UP&&dir!=DOWN)
                dir=DOWN;
                break;
            }
        }  
    }
}

void Snake::update(Food* f)
{
    int x=this->q->peekLast().getX();
    int y=this->q->peekLast().getY();
    if(dir==UP)y--;
    if(dir==DOWN)y++;
    if(dir==LEFT)x--;
    if(dir==RIGHT)x++;
    if(f->isEat(this->q->peekLast())){
        f->generate();
        grow();
    }
    if(x<0)x=39;
    if(x>40)x=0;
    if(y<0)y=29;
    if(y>30)y=0;
    this->q->pop();
    this->q->push(Vector(x,y));
    
    // if(x<0||x>40||y<0||y>30)exit(0);
    if(isDied())exit(0);
}

#pragma region Snake

#pragma endregion
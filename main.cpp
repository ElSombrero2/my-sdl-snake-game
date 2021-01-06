#include <iostream>
#include "snake.h"

using namespace std;

void clear(SDL_Renderer *r)
{
    SDL_Rect p={0,0,800,600};
    SDL_SetRenderDrawColor(r,255,255,255,255);
    SDL_RenderFillRect(r,&p);
    
}

int main(int argc,char** argv)
{
    srand(time(0));
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window=SDL_CreateWindow("Snake",
    SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer=SDL_CreateRenderer(window,0,SDL_RENDERER_ACCELERATED);
    
    int q=0;
    Food f;
    int spend=0,now=0;
    Snake s(4);
    while(!q)
    {
        SDL_Event e;
        SDL_PollEvent(&e);
        if(e.type==SDL_QUIT)q=1;
        now=SDL_GetTicks();
        if(now-spend>MILLIS){
            s.move(e);
            clear(renderer);
            spend=now;
            s.update(&f);
            f.draw(renderer);
            s.draw(renderer);
        }else SDL_Delay(MILLIS-(now-spend));
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    return 0;
}
#include <SDL.h>
#include <stdio.h>
const int width=600;
const int height=600;
int n=1;
int main(int argc, char* args[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("saper", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Rect kwadrat[144];
    SDL_MouseButtonEvent wcisk;
    wcisk.button = SDL_BUTTON_LEFT;
    wcisk.type = SDL_MOUSEBUTTONDOWN;
    wcisk.state = SDL_PRESSED;
    while (n!=0) {
        SDL_RenderClear(renderer);




        for (int i = 0; i < 144; i++) {
            if ((i - 1) < 0) {
                kwadrat[i].x = 0;
                kwadrat[i].y = 0;
            } else if (kwadrat[i - 1].x == 550) {
                kwadrat[i].y = kwadrat[i - 1].y + 50;
                kwadrat[i].x = 0;
            } else {
                kwadrat[i].x = kwadrat[i - 1].x + 50;
                kwadrat[i].y = kwadrat[i - 1].y;
            }

            kwadrat[i].h = 50;
            kwadrat[i].w = 50;
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            SDL_RenderDrawRect(renderer, &kwadrat[i]);
            //SDL_RenderSetClipRect(renderer, &kwadrat[i]);

        }
        if(SDL_MOUSEBUTTONDOWN)
        {
            SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
            SDL_RenderPresent(renderer);
        }
        else
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
            SDL_RenderPresent(renderer);
        }

    }


    SDL_RenderPresent(renderer);
        SDL_Event klik;

    //SDL_Delay(60000);
    SDL_Quit();
    return 0;
}

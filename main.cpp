#include <SDL.h>
#include <stdio.h>
const int width=800;
const int height=800;
int n=1;
int main(int argc, char* args[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("saper", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Rect kwadrat[16];
    SDL_MouseButtonEvent wcisk;
    wcisk.button = SDL_BUTTON_LEFT;
    wcisk.type = SDL_MOUSEBUTTONDOWN;
    wcisk.state = SDL_PRESSED;
    while (SDL_MOUSEBUTTONDOWN) {
        SDL_RenderClear(renderer);




        for (int i = 0; i < 16; i++) {
            if ((i - 1) < 0) {
                kwadrat[i].x = 0;
                kwadrat[i].y = 0;
            } else if (kwadrat[i - 1].x == 600) {
                kwadrat[i].y = kwadrat[i - 1].y + 200;
                kwadrat[i].x = 0;
            } else {
                kwadrat[i].x = kwadrat[i - 1].x + 200;
                kwadrat[i].y = kwadrat[i - 1].y;
            }

            kwadrat[i].h = 200;
            kwadrat[i].w = 200;
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            SDL_RenderDrawRect(renderer, &kwadrat[i]);
            //SDL_RenderSetClipRect(renderer, &kwadrat[i]);

        }
        SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
        SDL_RenderPresent(renderer);
    }


    SDL_RenderPresent(renderer);
        SDL_Event klik;

    //SDL_Delay(60000);
    SDL_Quit();
    return 0;
}

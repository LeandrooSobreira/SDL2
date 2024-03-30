#include <SDL2/SDL.h>

/* COMPILAR
g++ .\main.cpp -I .\SDL2\x86_64-w64-mingw32\include\ -L .\SDL2\x86_64-w64-mingw32\lib\ -lmingw32 -lSDL2main -lSDL2

*/

int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window* window = NULL;
  window = SDL_CreateWindow(
      "SDL2 It's Work!",
      SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      640, 480,
      SDL_WINDOW_SHOWN
      );
  SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_SetRenderDrawColor(renderer, 9, 33, 20, 255);
  while(true){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
      if( event.type == SDL_QUIT ){
        exit(0);
      }
    }
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  //SDL_Quit();
  return 0;
}
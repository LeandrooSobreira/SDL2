#include <SDL2/SDL.h>

/* COMPILAR
g++ .\game.c -I .\SDL2\x86_64-w64-mingw32\include\ -L .\SDL2\x86_64-w64-mingw32\lib\ -lmingw32 -lSDL2main -lSDL2
*/

int main(int argc, char **argv)
{
    int moveX, moveY, speed = 5;
    SDL_Init(SDL_INIT_EVERYTHING); // Initialize all resources of SDL
    SDL_Window *window = NULL;
    window = SDL_CreateWindow(                          // Create the window
        "BETA Game Test!!!",                            // Name of the window
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, // Centralize the window
        640, 480,                                       // Size of the window
        SDL_WINDOW_SHOWN);                              // Show the window
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Rect retangulo; // Make a object
    retangulo.x = 10;
    retangulo.y = 10;
    retangulo.w = 50;
    retangulo.h = 50;

    while (true) // Loop the code
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) // Verify if the user close the game or press ESC
            {
                exit(0); // Stop the program
            }

            moveX = (event.key.keysym.sym == SDLK_d) - (event.key.keysym.sym == SDLK_a); // Use true = 1 and false = 0 to make the moveX accont
            retangulo.x += (moveX * speed);                                              // Horizontally move the object
            moveY = (event.key.keysym.sym == SDLK_s) - (event.key.keysym.sym == SDLK_w); // Use true = 1 and false = 0 to make the moveY accont
            retangulo.y += (moveY * speed);                                              // Vertically move the object
        }

        SDL_RenderClear(renderer);                            // Clear the Screen
        SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);    // Object Fill Collor
        SDL_RenderFillRect(renderer, &retangulo);             // Fill the object
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Object Draw Collor
        SDL_RenderDrawRect(renderer, &retangulo);             // Draw the object
        SDL_SetRenderDrawColor(renderer, 15, 15, 15, 255);    // Background Collor
        SDL_RenderPresent(renderer);
    }

    // Clear memory used by renderer and window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
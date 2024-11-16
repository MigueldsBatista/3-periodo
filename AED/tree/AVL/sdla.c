#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

// Função para carregar uma textura
SDL_Texture* loadTexture(const char* file, SDL_Renderer* renderer) {
    SDL_Texture* texture = IMG_LoadTexture(renderer, file);
    if (texture == NULL) {
        printf("Unable to load texture: %s\n", IMG_GetError());
    }
    return texture;
}

int main(int argc, char* argv[]) {
    // Inicialização do SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Inicialização do SDL_image
    if (IMG_Init(IMG_INIT_PNG) == 0) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        SDL_Quit();
        return 1;
    }

    // Criação da janela
    SDL_Window* window = SDL_CreateWindow("Jogo SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // Criação do renderizador
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // Carregando a textura
    SDL_Texture* characterTexture = loadTexture("/home/miguel/home/3-periodo/AED/tree/AVL/Risio-Retro-Super-Mario-64-Texture-Pack-Cover-Pic_hu4bd11443e600ef568e8a77d378d6d023_59644_350x256_fill_q75_box_smart1.jpg", renderer);
    
    // Loop principal do jogo
    int running = 1;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        // Limpar a tela
        SDL_RenderClear(renderer);
        
        // Renderizar a textura
        SDL_RenderCopy(renderer, characterTexture, NULL, NULL); // Renderiza a textura na posição (0,0)

        // Apresentar o conteúdo renderizado
        SDL_RenderPresent(renderer);
    }

    // Limpeza
    SDL_DestroyTexture(characterTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    
    return 0;
}

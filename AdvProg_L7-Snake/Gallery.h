#ifndef GALLERY_H
#define GALLERY_H

#include <vector>
#include <string>


#if defined(_WIN64) || defined(_WIN32)
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif


// DO NOT CHANGE THE FOLLOWING LINES

enum PictureID {
    PIC_CHERRY = 0, PIC_SNAKE_VERTICAL,
    PIC_SNAKE_HORIZONTAL, PIC_SNAKE_HEAD, PIC_COUNT
};

class Gallery
{
    SDL_Texture* pictures[PIC_COUNT];
    SDL_Renderer* renderer;
    SDL_Texture* loadTexture(std::string path);
public:
    Gallery(SDL_Renderer* renderer_);
    ~Gallery();

    void loadGamePictures();
    SDL_Texture* getImage(PictureID id) const { return pictures[id]; }
};

#endif // GALLERY_H

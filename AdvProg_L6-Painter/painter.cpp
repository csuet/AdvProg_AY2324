#include "painter.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

void Painter::setColor(SDL_Color color) 
{ 
    this->color = color;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

void Painter::jumpForward(int numPixel)
{
    double rad = (angle / 180.0) * M_PI;
    x += static_cast<int>(numPixel * cos(rad));
    y -= static_cast<int>(numPixel * sin(rad)); // SDL's y-axis goes downwards, so we subtract
}

void Painter::jumpBackward(int numPixel)
{
    jumpForward(-numPixel);
}

void Painter::turnLeft(double degree)
{
    angle -= degree;
    if (angle < 0) {
        angle += 360;
    }
}

void Painter::turnRight(double degree)
{
    angle += degree;
    if (angle >= 360) {
        angle -= 360;
    }
}

void Painter::randomColor()
{
    std::srand(static_cast<unsigned>(std::time(0)));
    SDL_Color randomColor;
    randomColor.r = std::rand() % 256;
    randomColor.g = std::rand() % 256;
    randomColor.b = std::rand() % 256;
    randomColor.a = 255; // Fully opaque
    setColor(randomColor);
}

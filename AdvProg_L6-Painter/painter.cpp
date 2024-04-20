#include "painter.h"

/***
    Args: color (SDL_Color): color value 
        
    Returns:
        None
***/
void Painter::setColor(SDL_Color color)
{
    // Set the color value for the Painter and set Render Draw Color
    this->color = color;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

void Painter::jumpForward(int numPixel)
{
    // Jump the painter forward
    this->x += numPixel * cos(angle / 180 * M_PI);
    this->y -= numPixel * sin(angle / 180 * M_PI);
}

void Painter::jumpBackward(int numPixel)
{
    // Jump the painter backward
    this->x -= numPixel * cos(angle / 180 * M_PI);
    this->y += numPixel * sin(angle / 180 * M_PI);
}

void Painter::turnLeft(double degree)
{
    // Rotate left the painter
    this->angle += degree;
    this->angle -= int(this->angle / 360) * 360;
}

void Painter::turnRight(double degree)
{
    // Rotate right the painter
    this->angle -= degree;
    this->angle -= int(this->angle / 360) * 360;
}

void Painter::randomColor()
{
    // Set random color
    this->color = {static_cast<Uint8>(rand() % 256), static_cast<Uint8>(rand() % 256), static_cast<Uint8>(rand() % 256), static_cast<Uint8>(rand() % 256)};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

/***
Part of code that not need to be implemented
***/
void Painter::clearWithBgColor(SDL_Color bgColor)
{
    SDL_Color curColor = color;
    setColor(bgColor);
	SDL_RenderClear(renderer);    
    setColor(curColor);
}


Painter::Painter(SDL_Window* window, SDL_Renderer *renderer)
{
    SDL_RenderGetLogicalSize(renderer, &width, &height);
    if (width == 0 && height == 0) {
        SDL_GetWindowSize(window, &width, &height);
    }
    this->renderer = renderer;
    setPosition(width/2, height/2);
    setAngle(0);
    setColor(WHITE_COLOR);
    clearWithBgColor(BLUE_COLOR);
}


void Painter::createCircle(int radius)
{
    double rad = (angle / 180) * M_PI;
    int centerX = x + (int) (cos(rad) * (double) radius);;
    int centerY = y - (int) (sin(rad) * (double) radius);;

    int dx = radius;
    int dy = 0;
    int err = 0;

    while (dx >= dy)
    {
        SDL_RenderDrawPoint(renderer, centerX + dx, centerY + dy);
        SDL_RenderDrawPoint(renderer, centerX + dy, centerY + dx);
        SDL_RenderDrawPoint(renderer, centerX - dy, centerY + dx);
        SDL_RenderDrawPoint(renderer, centerX - dx, centerY + dy);
        SDL_RenderDrawPoint(renderer, centerX - dx, centerY - dy);
        SDL_RenderDrawPoint(renderer, centerX - dy, centerY - dx);
        SDL_RenderDrawPoint(renderer, centerX + dy, centerY - dx);
        SDL_RenderDrawPoint(renderer, centerX + dx, centerY - dy);

        if (err <= 0)
        {
            dy += 1;
            err += 2*dy + 1;
        }
        if (err > 0)
        {
            dx -= 1;
            err -= 2*dx + 1;
        }
    }
}



void Painter::createParallelogram(int width, int height) {
  moveForward(width);
  turnLeft(90);
  moveForward(height);
  turnLeft(90);
  moveForward(width);
  turnLeft(90);
  moveForward(height);
}




void Painter::createSquare(int size) {
  for (int i = 0; i < 3; ++i) {
    moveForward(size);
    turnLeft(90); 
  }
}


void Painter::moveForward(int numPixel)
{
    int preX = x, preY = y;
    jumpForward(numPixel);
    SDL_RenderDrawLine(renderer, preX, preY, x, y);
}


void Painter::moveBackward(int numPixel)
{
    moveForward(-numPixel);
}


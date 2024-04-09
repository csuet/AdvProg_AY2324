#include "painter.h"

/***
    Args: color (SDL_Color): color value

    Returns:
        None
***/
void Painter::setColor(SDL_Color color)
{
    // TODO: set the color value for the Painter and set Render Draw Color
    this->color = color;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, SDL_ALPHA_OPAQUE);
}


/***
    Args: numPixel (int): number of pixel for jumping forward

    Returns:
        None
***/
void Painter::jumpForward(int numPixel)
{
    // TODO: jump the painter forward
    int dx = numPixel * cos(angle * M_PI / 180);
    int dy = numPixel * sin(angle * M_PI / 180);
    x += dx;
    y -= dy;
}


/***
    Args: numPixel (int): number of pixel for jumping backward

    Returns:
        None
***/
void Painter::jumpBackward(int numPixel)
{
    // TODO: jump the painter backward
     jumpForward(-numPixel);
}


/***
    Args: degree (double): the value of rotation angle

    Returns:
        None
***/
void Painter::turnLeft(double degree)
{
    // TODO: rotate left the painter
     angle += degree;
     if(angle>=360) angle-=360;
     else if(angle<=-360) angle+=360;
}


/***
    Args: degree (double): the value of rotation angle

    Returns:
        None
***/
void Painter::turnRight(double degree)
{
    // TODO: rotate right the painter
    turnLeft(-degree);
}

/***
    Args:
        None
    Returns:
        None
***/
void Painter::randomColor()
{
    // TODO: set random color
    srand (time(0));
    int numberRandom = rand()%10;
    if( numberRandom == 0) this->color = CYAN_COLOR;
    else if(numberRandom == 1) this->color = BLUE_COLOR;
    else if(numberRandom == 2) this->color = ORANGE_COLOR;
    else if(numberRandom == 3) this->color = YELLOW_COLOR;
    else if(numberRandom == 4) this->color = LIME_COLOR;
    else if(numberRandom == 5) this->color = PURPLE_COLOR;
    else if(numberRandom == 6) this->color = RED_COLOR;
    else if(numberRandom == 7) this->color = WHITE_COLOR;
    else if(numberRandom == 8) this->color = BLACK_COLOR;
    else if(numberRandom == 9) this->color = GREEN_COLOR;
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



void Painter::createParallelogram(int size)
{
	for (int i = 0; i < 2; ++i) {
        moveForward(size);
        turnLeft(60);
        moveForward(size);
        turnLeft(120);
    }
}



void Painter::createSquare(int size)
{
	for (int i = 0; i < 4; ++i) {
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


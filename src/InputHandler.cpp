#include "InputHandler.h"
#include <conio.h>

#define esc 27

InputHandler::InputHandler()
{
}

char InputHandler::GetInput()
{
    char input = getch();
    return input;
}
#include "InputHandler.h"
#include <conio.h>

InputHandler::InputHandler()
{
}

char InputHandler::GetInput()
{
    char input = getch();
    return input;
}
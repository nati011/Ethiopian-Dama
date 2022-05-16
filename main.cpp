#include <stdlib.h>

#include "raylib.h"
#include "physac.h"
#include <math.h>
#include <time.h>
#include "componenets.h"

//position state
bool a1_occupied = true;
bool a2_occupied = true;
bool a3_occupied = true;
bool b1_occupied = false;
bool b2_occupied = false;
bool b3_occupied = false;
bool c1_occupied = true;
bool c2_occupied = true;
bool c3_occupied = true;

bool is_over(Vector2 &magenta_one, Vector2 &magenta_two, Vector2 &magenta_three, Vector2 &blue_one, Vector2 &blue_two, Vector2 &blue_three)
{
    //set a condition to narrow down our selection
    //there can be a winner only if these position are occupied
    //if not we would save time by avoiding the execution of is_over
    //this check is being performed here and not in the is_over() function to avoid
    //function call overhead
    if( (a1 && b2 and c3) || (a3 && b2 && c1) || (b1 && b2 && b3) || (a2 && b2 && c2) )
    {
        if()
    }
}

int main()
{
    InitWindow(1000,800,"Dama");

    SetWindowState(FLAG_VSYNC_HINT);

        menu();
    CloseWindow();
}




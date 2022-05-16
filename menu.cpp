#include <stdlib.h>

#include "raylib.h"
#include "physac.h"
#include <math.h>
#include <time.h>
#define NUM_FRAMES  3
void menu()
{
    const int screenWidth = 1000;
    const int screenHeight = 800;

    Sound fxButton = LoadSound("res\\buttonfx.wav");   // Load button sound
    Texture2D button = LoadTexture("res\\play_v2.png"); // Load button texture
    Texture2D button_2 = LoadTexture("res\\multiplayer_standalone.png");
    Texture2D button_3 = LoadTexture("res\\multiplayer_network.png");


    float frameHeight = (float)button.height/NUM_FRAMES;
    float frameHeight2 = (float)button_2.height/NUM_FRAMES;
    float frameHeight3 = (float)button_3.height/NUM_FRAMES;

    Rectangle sourceRec = { 0, 0, (float)button.width, frameHeight };
    Rectangle btnBounds = { screenWidth/2.0f - button.width/2.0f, screenHeight/2.0f - button.height/NUM_FRAMES/2.0f, (float)button.width, frameHeight };

    Rectangle sourceRec_2 = { 0, 0, (float)button.width, frameHeight2 };
    Rectangle btn2Bounds = { (screenWidth/2.0f - button.width/2.0f), (screenHeight/2.0f - button.height/NUM_FRAMES/2.0f)+100, (float)button.width, frameHeight2 };

    Rectangle sourceRec_3 = { 0, 0, (float)button.width, frameHeight3 };
    Rectangle btn3Bounds = { (screenWidth/2.0f - button.width/2.0f), (screenHeight/2.0f - button.height/NUM_FRAMES/2.0f)+190, (float)button.width, frameHeight3 };

    int btnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
    int btn2state = 0;
    int btn3state = 0;

    bool btnAction = false;
    bool btn2Action = false;         // Button action should be activated
    bool btn3Action = false;

    Vector2 mousePoint = { 0.0f, 0.0f };
    SetTargetFPS(60);


    while(!WindowShouldClose())
    {
       // ClearBackground(MAGENTA);


        mousePoint = GetMousePosition();
        btnAction = false;

        // Check button state
        //button 1
        if (CheckCollisionPointRec(mousePoint, btnBounds))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
            else btnState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
        }
        else btnState = 0;
        if (btnAction)
        {
            PlaySound(fxButton);
            //play_dama_with_computer();
            break;
            // TODO: Any desired action
        }
        //button 2
        if (CheckCollisionPointRec(mousePoint, btn2Bounds))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btn2state = 2;
            else btn2state = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btn2Action = true;
        }
        else btn2state = 0;

        if (btn2Action)
        {
            PlaySound(fxButton);
            //play_dama_with_friend_standalone();
            break;
            // TODO: Any desired action
        }

        //button 3
        if (CheckCollisionPointRec(mousePoint, btn3Bounds))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btn3state = 2;
            else btn3state = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btn3Action = true;
        }
        else btn3state = 0;

          if (btn3Action)
        {
            PlaySound(fxButton);


            // TODO: Any desired action
        }


        // Calculate button frame rectangle to draw depending on button state
        sourceRec.y = btnState*frameHeight;
        sourceRec_2.y = btn2state*frameHeight2;
        sourceRec_3.y = btn3state*frameHeight3;

        BeginDrawing();
            //prepare window


                DrawText("Dama",310,70,160,BLACK);
                DrawRectangle(400,220,300,50,BLACK);
                DrawText("Version 1.0", 570,240,18,WHITE);

            //action

            ClearBackground(MAGENTA);

            DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);
            DrawTextureRec(button_2, sourceRec_2, (Vector2){ btn2Bounds.x, btn2Bounds.y }, WHITE);
            DrawTextureRec(button_3, sourceRec_3, (Vector2){ btn3Bounds.x, btn3Bounds.y }, WHITE);

            EndDrawing();
    }

    UnloadTexture(button);  // Unload button texture

    UnloadTexture(button_2);

    UnloadTexture(button_3);

    UnloadSound(fxButton);  // Unload sound

    CloseAudioDevice();     // Close audio device


}

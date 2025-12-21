#include "assets.h"
#include "ball.h"
#include "game.h"
#include "graphics.h"
#include "level.h"
#include "paddle.h"
#include "raylib.h"
int lives = maxlives;

void update()
{
    switch (game_state) {
    case menu_state:
        if (IsKeyPressed(KEY_ENTER)) {
            game_state = in_game_state;
        }
        break;
    case in_game_state:
        UpdateMusicStream(background_sound);
        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
            move_paddle(-paddle_speed, 0);
        }
        if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
            move_paddle(paddle_speed, 0);
        }
        if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
            move_paddle(0, -paddle_speed);
        }
        if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
            move_paddle(0, paddle_speed);
        }
        move_ball();
        if (!is_ball_inside_level()) {
            --lives;
            if (lives == 0) {
                game_state = lose_state;
                lives = maxlives;
                current_level_index = 0;
            } else {
                load_level();
            }
        } else if (current_level_blocks == 0) {
            load_level(1);
            PlaySound(win_sound);
        }
        if (IsKeyPressed(KEY_SPACE)) {
            game_state = paused_state;
        }
        if (IsKeyPressed(KEY_X)) {
            game_state = victory_state;
        }

        break;
    case paused_state:
        if (IsKeyPressed(KEY_SPACE)) {
            game_state = in_game_state;
        }
        break;
    case victory_state:
        if (IsKeyPressed(KEY_ENTER)) {
            game_state = menu_state;
            current_level_index = -1;
        }
        break;
    case lose_state:
        if (IsKeyPressed(KEY_BACKSPACE)) {
            game_state = menu_state;
            current_level_index = 0;
        }
        break;
}
}

void draw()
{
    switch (game_state) {
    case menu_state:
        draw_menu();
        break;
    case in_game_state:
        draw_level();
        draw_paddle();
        draw_ball();
        draw_ui();
        break;
    case paused_state:
        draw_pause_menu();
        break;
    case victory_state:
        draw_victory_menu();
        break;
    case lose_state:
        draw_lose_menu();
        break;
    }
}


int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(1920, 1080, "Breakout");
    SetTargetFPS(60);

    load_fonts();
    load_textures();
    load_level();
    load_sounds();

    PlayMusicStream(background_sound);
    while (!WindowShouldClose()) {
        BeginDrawing();
        draw();
        update();

        EndDrawing();
    }
    CloseWindow();

    unload_sounds();
    unload_level();
    unload_textures();
    unload_fonts();

    return 0;
}

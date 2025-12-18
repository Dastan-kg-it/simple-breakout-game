#include "assets.h"

#include "raylib.h"

void load_fonts()
{
    menu_font = LoadFontEx("data/fonts/ARCADECLASSIC.TTF", 256, nullptr, 0);
}

void unload_fonts()
{
    UnloadFont(menu_font);
}

void load_textures()
{
    background_texture = LoadTexture("data/images/background.png");
    background3_texture = LoadTexture("data/images/background3.png");
    background2_texture = LoadTexture("data/images/background2.png");
    background4_texture = LoadTexture("data/images/background4.png");
    background5_texture = LoadTexture("data/images/background5.png");
    background6_texture = LoadTexture("data/images/background6.png");
    background7_texture = LoadTexture("data/images/background7.png");
    background8_texture = LoadTexture("data/images/background8.png");


    wall_texture = LoadTexture("data/images/wall.png");
    wall1_texture = LoadTexture("data/images/wall1.png");
    void_texture = LoadTexture("data/images/void.png");
    block_texture = LoadTexture("data/images/block.png");
    block1_texture = LoadTexture("data/images/block1.png");
    block2_texture = LoadTexture("data/images/block2.png");
    block3_texture = LoadTexture("data/images/block3.png");
    block4_texture = LoadTexture("data/images/block4.png");
    block5_texture = LoadTexture("data/images/block5.png");
    paddle_texture = LoadTexture("data/images/paddle.png");
    ball_sprite = load_sprite("data/images/ball/ball", ".png", 8, true, 10);
}

void unload_textures()
{
    UnloadTexture(background_texture);
    UnloadTexture(background3_texture);
    UnloadTexture(background2_texture);
    UnloadTexture(background4_texture);
    UnloadTexture(background5_texture);
    UnloadTexture(background6_texture);
    UnloadTexture(background7_texture);
    UnloadTexture(background8_texture);

    UnloadTexture(wall_texture);
    UnloadTexture(wall1_texture);
    UnloadTexture(void_texture);
    UnloadTexture(block_texture);
    UnloadTexture(block1_texture);
    UnloadTexture(block2_texture);
    UnloadTexture(block3_texture);
    UnloadTexture(block4_texture);
    UnloadTexture(block5_texture);
    UnloadTexture(paddle_texture);
    unload_sprite(ball_sprite);
}

void load_sounds()
{
    InitAudioDevice();
    win_sound = LoadSound("data/sounds/win.wav");
    lose_sound = LoadSound("data/sounds/lose.wav");
}

void unload_sounds()
{
    UnloadSound(win_sound);
    UnloadSound(lose_sound);
    CloseAudioDevice();
}

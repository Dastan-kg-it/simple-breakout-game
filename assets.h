#ifndef ASSETS_H
#define ASSETS_H

#include "raylib.h"

#include "sprite.h"

inline Font menu_font;

inline Texture2D background3_texture;
inline Texture2D background4_texture;
inline Texture2D background5_texture;
inline Texture2D background_texture;
inline Texture2D background2_texture;
inline Texture2D background6_texture;
inline Texture2D background7_texture;
inline Texture2D background8_texture;


inline Texture2D wall_texture;
inline Texture2D wall1_texture;
inline Texture2D void_texture;
inline Texture2D paddle_texture;
inline Texture2D block_texture;
inline Texture2D block1_texture;
inline Texture2D block2_texture;
inline Texture2D block3_texture;
inline Texture2D block4_texture;
inline Texture2D block5_texture;
inline Texture2D block6_texture;

inline Texture2D life_texture;



inline sprite ball_sprite;

inline Sound win_sound;
inline Sound lose_sound;
inline Sound food_sound;
inline Sound stone_sound;
inline Sound hit_sound;



inline Music background_sound;

void load_fonts();
void unload_fonts();

void load_textures();
void unload_textures();

void load_sounds();
void unload_sounds();

#endif // ASSETS_H

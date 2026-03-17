#include "texture.h"

void Texture_init(Texture *texture) {
  texture->texture = NULL;
  texture->width = 0;
  texture->height = 0;
  texture->x = 0;
  texture->y = 0;

}
// bool Texture_init_andLoadFromRenderedText(
//     Texture *texture, SDL_Renderer *renderer, TTF_Font *gFont, SDL_FRect loc,
//     const char *textureText, unsigned int textSize, SDL_Color textColor) {
//   // Free any pre-existing texture
//   Texture_free(texture);
//   texture->texture = NULL;
//   texture->width = 0;
//   texture->height = 0;
//   texture->loc = loc;


//   SDL_Surface *textSurface =
//       TTF_RenderText_Solid(gFont, textureText, textSize, textColor);
//   if (textSurface == NULL) {
//     SDL_Log("Unable to render text surface! SDL_ttf Error: %s\n",
//             SDL_GetError());
//   } else {
//     texture->texture = SDL_CreateTextureFromSurface(renderer, textSurface);
//     if (texture->texture == NULL) {
//       SDL_Log("Unable to create texture from rendered text! SDL Error: %s\n",
//               SDL_GetError());
//     } else {
//       texture->width = textSurface->w;
//       texture->height = textSurface->h;
//     }

//     SDL_DestroySurface(textSurface);
//   }

//   return (texture->texture != NULL);
// }
// Free the Texture resources
void Texture_free(Texture *texture) {
  if (texture->texture != NULL) {
    SDL_DestroyTexture(texture->texture);
    texture->texture = NULL;
    texture->width = 0;
    texture->height = 0;
    texture->x = 0;
    texture->y = 0;
  }
}

// Load texture from file
bool Texture_loadFromFile(Texture *texture, SDL_Renderer *renderer,
                          const char *path) {
  // Free any pre-existing texture
  Texture_free(texture);

  SDL_Texture *newTexture = IMG_LoadTexture(renderer, path);
  if (newTexture == NULL) {
    SDL_Log("Unable to create texture from %s! SDL Error: %s\n", path,
            SDL_GetError());
  } else {
    float width, height;
    SDL_GetTextureSize(newTexture, &width, &height);
    texture->width = width;
    texture->height = height;
  }

  texture->texture = newTexture;
  return (texture->texture != NULL);
}

// Load texture from rendered text
// bool Texture_loadFromRenderedText(Texture *texture, SDL_Renderer *renderer,
//                                   TTF_Font *gFont, const char *textureText,
//                                   unsigned int textSize, SDL_Color textColor) {
//   // Free any pre-existing texture
//   Texture_free(texture);

//   SDL_Surface *textSurface =
//       TTF_RenderText_Solid(gFont, textureText, textSize, textColor);
//   if (textSurface == NULL) {
//     SDL_Log("Unable to render text surface! SDL_ttf Error: %s\n",
//             SDL_GetError());
//   } else {
//     texture->texture = SDL_CreateTextureFromSurface(renderer, textSurface);
//     if (texture->texture == NULL) {
//       SDL_Log("Unable to create texture from rendered text! SDL Error: %s\n",
//               SDL_GetError());
//     } else {
//       texture->width = textSurface->w;
//       texture->height = textSurface->h;
//     }

//     SDL_DestroySurface(textSurface);
//   }

//   return (texture->texture != NULL);
// }

// Set color modulation
void Texture_setColor(Texture *texture, Uint8 red, Uint8 green, Uint8 blue) {
  SDL_SetTextureColorMod(texture->texture, red, green, blue);
}

// Set blending mode
void Texture_setBlendMode(Texture *texture, SDL_BlendMode blending) {
  SDL_SetTextureBlendMode(texture->texture, blending);
}

// Set alpha modulation
void Texture_setAlpha(Texture *texture, Uint8 alpha) {
  SDL_SetTextureAlphaMod(texture->texture, alpha);
}

// Render texture
void Texture_render(Texture *texture, SDL_Renderer *renderer, SDL_FRect *clip,
                    SDL_FRect *pos, double angle, SDL_FPoint *center,
                    SDL_FlipMode flip) {
  if (pos == NULL)
    SDL_RenderTextureRotated(renderer, texture->texture, clip, &(SDL_FRect){texture->x, texture->y, texture->width, texture->height},
                             angle, center, flip);
  else
    SDL_RenderTextureRotated(renderer, texture->texture, clip, pos, angle,
                             center, flip);
}

void Texture_render_with_camera(Texture *texture, SDL_Renderer *renderer, Camera* cam, SDL_FRect *clip,
                    SDL_FRect *pos, double angle, SDL_FPoint *center,
                    SDL_FlipMode flip) {
    if (pos == NULL){
      if(check_collision_FRect(&(FRect){cam->x,cam->y,cam->w,cam->h}, &(FRect){texture->x,texture->y,texture->width,texture->height})){
        printf("Texture in frame. Rendering \n");
        SDL_RenderTextureRotated(renderer, texture->texture, clip, &(SDL_FRect){texture->x-cam->x, texture->y-cam->y, texture->width, texture->height},
                             angle, center, flip);
      }
    }
    else{
      if(check_collision_FRect(&(FRect){cam->x,cam->y,cam->w,cam->h}, &(FRect){pos->x,pos->y,pos->w,pos->h})){
        printf("Texture in frame. Rendering \n");
        SDL_RenderTextureRotated(renderer, texture->texture, clip, &(SDL_FRect){pos->x-cam->x,pos->y-cam->y,pos->w,pos->h}, angle,
                             center, flip);
      }
  }
}
// Get texture width
int Texture_getWidth(Texture *texture) { return texture->width; }

// Get texture height
int Texture_getHeight(Texture *texture) { return texture->height; }

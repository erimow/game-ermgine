#include "../Core/engine.h"
#include <stdlib.h>
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

// typedef enum ScenesEnum { MAINMENU, GAME } ScenesEnum;
//Store enum in context
typedef struct Scene{
   // void (*loadAssets)(Engine *engine);
   void (*start)(Engine *engine);
   void (*update)(Engine *engine);
   void (*handleEvents)(Engine *engine, SDL_Event *e);
   void (*render)(Engine *engine);
   void (*stop)(void);
   bool isSceneLoaded;
}Scene;

typedef struct SceneManager{
   Scene* scenes;
   uint8_t numScenes;
   uint16_t currentScene;
   //ScenesEnum currentScene;
}SceneManager;

void SceneManager_init(SceneManager* sm, int numScenes);
void SceneManager_deinit(SceneManager *sm);
void SceneManager_addScene(SceneManager* sm,uint16_t scene,void (*start)(Engine *engine), void (*update)(Engine *engine), void (*handleEvents)(Engine *engine, SDL_Event *e), void (*render)(Engine *engine), void (*stop)(void));
// void SceneManager_loadScene(SceneManager* sm, uint16_t scene, Engine *engine);
void SceneManager_switchScene(SceneManager *sm, uint16_t scene, Engine *engine);
void SceneManager_switchSceneAndUnload(SceneManager *sm, uint16_t scene, Engine *engine);

// bool SceneManager_isSceneAssetsLoaded(SceneManager *sm, uint16_t scene);

void SceneManager_currentScene_Start(SceneManager *sm, Engine *engine);
void SceneManager_currentScene_Update(SceneManager *sm, Engine *engine);
void SceneManager_currentScene_Stop(SceneManager *sm, Engine *engine);
void SceneManager_currentScene_HandleEvents(SceneManager *sm, Engine *engine, SDL_Event *e);
void SceneManager_currentScene_Render(SceneManager *sm, Engine *engine);

#endif

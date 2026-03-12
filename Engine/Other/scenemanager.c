#include "scenemanager.h"

void SceneManager_init(SceneManager* sm, int numScenes){
    sm->scenes = malloc(sizeof(Scene)*numScenes);
    sm->numScenes = numScenes;
    for (int i = 0; i<numScenes; i++){
        sm->scenes[i].isSceneLoaded=false;
        // sm->scenes[i].loadAssets = NULL;
        sm->scenes[i].start = NULL;
        sm->scenes[i].update = NULL;
        sm->scenes[i].handleEvents = NULL;
        sm->scenes[i].render = NULL;
        sm->scenes[i].stop = NULL;
        sm->currentScene = 0;
    }
}
void SceneManager_deinit(SceneManager *sm){
    free(sm->scenes);
}
void SceneManager_addScene(SceneManager* sm,uint16_t scene,void (*start)(Engine *engine), void (*update)(Engine *engine), void (*handleEvents)(Engine *engine, SDL_Event *e),void (*render)(Engine *engine), void (*stop)(void)){
    sm->scenes[scene].start=start;
    sm->scenes[scene].update=update;
    sm->scenes[scene].handleEvents=handleEvents;
    sm->scenes[scene].render=render;
    sm->scenes[scene].stop=stop;
}
// void SceneManager_loadScene(SceneManager* sm, uint16_t scene, void *ctx){
    // sm->currentScene = scene;
    // if(!sm->scenes[scene].isSceneLoaded){
        // sm->scenes[scene].loadAssets(ctx);
        // sm->scenes[scene].isSceneLoaded=true;
    // }
// }
void SceneManager_switchScene(SceneManager *sm, uint16_t scene, Engine *engine){
   sm->currentScene = scene; //then loads assets if needed and runs start function
    if(!sm->scenes[scene].isSceneLoaded){
        // sm->scenes[scene].loadAssets(ctx);
        sm->scenes[scene].isSceneLoaded=true;
    }
   sm->scenes[sm->currentScene].start(engine);
}
void SceneManager_switchSceneAndUnload(SceneManager *sm, uint16_t scene, Engine *engine){
     sm->scenes[sm->currentScene].stop();
    sm->scenes[sm->currentScene].isSceneLoaded = false; //unloads previous scene

   sm->currentScene = scene; //then loads assets if needed and runs start function
    if(!sm->scenes[scene].isSceneLoaded){
        // sm->scenes[scene].loadAssets(ctx);
        sm->scenes[scene].isSceneLoaded=true;
    }
   sm->scenes[sm->currentScene].start(engine);

}



// bool SceneManager_isSceneAssetsLoaded(SceneManager *sm, uint16_t scene){
//     return sm->scenes[scene].isSceneLoaded;
// }


void SceneManager_currentScene_Start(SceneManager *sm, Engine *engine){
    sm->scenes[sm->currentScene].start(engine);
}
void SceneManager_currentScene_Update(SceneManager *sm, Engine *engine){
    sm->scenes[sm->currentScene].update(engine);
}
void SceneManager_currentScene_Stop(SceneManager *sm, Engine *engine){
    sm->scenes[sm->currentScene].stop();
}
void SceneManager_currentScene_HandleEvents(SceneManager *sm, Engine *engine, SDL_Event *e){
    sm->scenes[sm->currentScene].handleEvents(engine, e);
}
void SceneManager_currentScene_Render(SceneManager *sm, Engine *engine){
    sm->scenes[sm->currentScene].render(engine);
}
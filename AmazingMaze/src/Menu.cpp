//
// Created by roberto on 12/20/20.
//
/// Esta es una pantalla de menu nada mas tendra un solo boton por el momento
//

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_surface.h>

class Menu {

public:
    SDL_Window* wind= NULL;
    SDL_Surface* btn_start= NULL;
    SDL_Surface* btn_start_bright=NULL;
    SDL_Renderer* ren=NULL;
    SDL_Texture* btn_startText=NULL;
    SDL_Texture* btn_startbrightText=NULL;
    SDL_Event* event_handler=NULL;
    Uint32 render_flags= SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    Uint32 FlgfSc= SDL_WINDOW_FULLSCREEN;
    int SCREEN_WIDTH=1920;
    int SCREEN_HEIGHT=1080;
    const char* file1= "/home/roberto/Documents/CLionProjects/AmazingMaze/src/res/start.bmp";
    const char* file2= "/home/roberto/Documents/CLionProjects/AmazingMaze/src/res/startBright.bmp";
    
    
    //Constructor de la clase
    Menu (){
        //Vamos a inicializar todos los objetos para poder pintar
        //NOS MARCABA UN ERROR POR QUE YA HABIAMOS INICIADO EL VIDEO EN OTRO LADO
        //if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) >0){
            //Generamos la ventana el render y todos nuestros elementos para jugar
        wind = SDL_CreateWindow("Menu",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1920,1080,0);
        ren = SDL_CreateRenderer(wind,-1,render_flags);
            if(!ren){
                printf("Error al generar Render\n %s",SDL_GetError());
            }
            else {
                btn_start= SDL_LoadBMP(file1);
                btn_start_bright=SDL_LoadBMP(file2);
            }
        //}
        //else{
           //printf("Error al iniciar el video SDL class Menu \n %s",SDL_GetError());
           //printf("a \n a\n a\n %s",SDL_GetError());
        //}
        
    }
    
public: void show(){
       
       //Mostramos la ventana limpia (en negro) de nuestro menu
        SDL_SetWindowFullscreen(wind,SDL_WINDOW_FULLSCREEN);
        SDL_RenderClear(ren);
        SDL_RenderPresent(ren);
        SDL_Delay(2000);
        
      //Aqui mostramos nuestro menu con los botones y todo1
      
    
    }
    
}; //Fin de la clase Menu



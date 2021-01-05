//All this file does is a splash screen to show a image coming from down to top
//and also that image will containg the name of our game "Crazy Maze"

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_image.h>

class SplashScreen {

private:
    SDL_Window* window= NULL;
    SDL_Surface* surface= NULL;
    SDL_Renderer* rend=NULL;
    SDL_Texture* text=NULL;
    SDL_Event* event_handler=NULL;
    SDL_Rect rec;
    Uint32 render_flags= SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    Uint32 FlgfSc= SDL_WINDOW_FULLSCREEN;
    int SCREEN_WIDTH=0;
    int SCREEN_HEIGHT=0;
    int SCROLL_SPEED=300;
//    char* img = "/src/res/image.png";

public:    SplashScreen() {
         // ALL the next code its only inicializa jaja
        init();
    }

public: void Animation () {
        //Los valores de SCREEN altura y ancho los estamos seteando a la mala en la funcion init
        float moveY=SCREEN_HEIGHT;
        SDL_SetWindowFullscreen(window,FlgfSc);
        SDL_Delay(250);
        //Sin este delay se ve fea la transicion de fullscreen y cuando pinta la imagen
        //Y a veces como el fullscr hace un clear entonces no nos pinta la imagen sin el delay

        //Ponemos nuestro sprite hasta abajo de la ventana ( que es del size de la textura)
        //rec.x=rec.w;
        rec.y=rec.h+(rec.h*0.25);
        //SDL_RenderCopy(rend,text,NULL,NULL);
        SDL_RenderClear(rend);
        SDL_RenderPresent(rend);
        SDL_Delay(1000);
        
       //LA ANIMACION TERMINA CUANDO RECTANGULO LLEGUE HASTA ARRIBA DE HECHO ES MAS ALLA DE ARRIBA
       //*
        while (rec.y >= 0){
            printf("los valres de rec.y %i \n y de rec.h  %i \n y de SCREENHEIGHT %i \n",rec.y,rec.h,SCREEN_HEIGHT);
            //Limpiamos la pantalla
            SDL_RenderClear(rend);
            
            rec.y=(int)moveY;
            SDL_RenderCopy(rend,text,NULL,&rec);
            SDL_RenderPresent(rend);
            //ESTAS LINEAS SON MUY importantes por que ponemos la velocidad de movimiento asi como ponemos 60 cuadros porS
            moveY-=(float) SCROLL_SPEED /60;
            SDL_Delay(1000/60);
        }//*/
        SDL_DestroyTexture(text);
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(window);
        SDL_Quit();
   }

//esta funcion es llamada por el constructor y nada mas lo que hace es iniciar las variables y all SDL vars etc
private: void init (){

        //Inicializamos el video y el audio
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
            printf("ERROR en class splash screen, when initializing SDL lib /n");
        }
        else printf("VIDEO Y AUDIO INICIADOS CON EXITO \n");

        //Generamos la ventana y la pintamos en la pantalla
        window = SDL_CreateWindow("SplashScreen",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1920,1080,0);

        //Generamos un Render asociado a la ventana
        rend= SDL_CreateRenderer(window,-1,render_flags);
        if (!rend) printf("Error al generar el render:\n %s",SDL_GetError());
        else  (printf ("Render generado\n\n"));

        //Generamos un surface con la imagen (la imagen es cargada a memoria normal)
        surface = SDL_LoadBMP("/home/roberto/Documents/CLionProjects/AmazingMaze/src/res/image.bmp");
        if (!surface){
            printf("Error sucedio algo %s \n", SDL_GetError()); }else (printf ("surface generated: \n\n"));
        //Generamos una textura a partir de la memoria normal (cargamos nuestra imagen a meomria de video)
        text = SDL_CreateTextureFromSurface(rend,surface);
        printf("texture generated: \n");
/*
 * ESTE CODIGO DE ARRIBA YA
 *   ESTA PROBADO
 *    FUNCIONA BIEN AL MOMENTO
 *     DE INICIALIZAR NADA MAS HAY QUE PROBAR EL DE ABAJO
 */
       //Hacemos un rec negro del tamano de nuestra texture, para hacer la animacion
        //ESTO ES UNA PORQUERIA NADA MAS LO ESTAMOS PONIENDO PARA VER COMO SE COMPORTA
        SDL_GetWindowMaximumSize(window,&SCREEN_WIDTH,&SCREEN_HEIGHT);
        SCREEN_HEIGHT=1081;
        SCREEN_WIDTH=1921;
       //
       //
       //
        printf("Cuando se tomo el valor de ScreenHEIGH fue: %i \n Y WIDTH %i \n", SCREEN_HEIGHT,SCREEN_WIDTH);
       //OJO QUE LA TEXTURA en este punto tiene la imagen cargada y esa imagen tenia de MEDIDAS 908x531
       //ESO NOS GENERO EL ERROR DE LA DIFERENCIA EN medidas de nuestro texture con nuestro REC con nuestra pantalla
        SDL_QueryTexture(text,NULL,NULL,&rec.w,&rec.h);
        printf("Cuando se tomo el valor de rec.W: %i\n rec.H: %i \n", rec.w,rec.h);
        
    }
};



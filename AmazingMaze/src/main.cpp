//
//
// Programa nada mas por que si
// reated by roberto on 11/29/20.
//

#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_render.h>
#include "SplashScreen.cpp"
#include "Menu.cpp"


int main () {
//Esto nada mas lo hicimos por chingar sacamos como 100 ventanas asi como antes hacian los "virus" jajaja
//Aprendimos algo bueno de este experimento que cada que se saca una instancia de un objeto se llama al constructor
//En el caso de los arreglos como aqui al momento de reservar la memoria para los 10 ejecuta 10 veces el constructor
//Osea que no es necesario hacer un ciclo para sacar 1000000 ventanas solo instanciamos 1000000 y ya se ejecuta 1000000 el constructor
//SplashScreen objetos[4];

//Por ahora solo vamos a invocar nuestro splash y despues el menu, esta logica de juego debe ir en la clase GameLogic
    SplashScreen splashObj;
    splashObj.Animation();
//Aqui mandamos a llamar al menu
    //Menu menu;
    //menu.show();
    
    
}

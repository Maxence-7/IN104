/* Maxence Leguéry & Sam Gadoin */

#include <stdio.h>
#include <stdlib.h>

#include "interface/clavier.h"
#include "interface/convert_frequence.h"
#include "interface/audio.h"
#include "analyse/getNotes.h"

#define fichierTampon "notes.dat"

int main(int argc, char *argv[]) {
    //bonjour test
    //catapulte
    SDL_Color noir = {0, 0, 0, 0};

    /*if(argc<2) {
        printf("Merci de saisir un fichier audio");
        return 0;
    }*/
    char* audioname = argv[1];
    audioname="audios/gamme_mono.wav";
    //audioname="audios/Laputa.wav";
    //audioname="audios/vivaldi_spring_mono.wav";
    //audioname = strcat("audios/",audioname);

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    int r = initSDL(&window, &renderer);
    
    if(r==1) {
        printf("Erreur lors de l'initialisation de la librairie SDL");
        goto Quit;
    }

    //Dessin du clavier de piano; il y a 52 touches blanches
    SDL_Rect *touches = malloc(88 * sizeof(SDL_Rect));
    touches = initKeyboard(renderer, noir, touches);

    writeNotesInFile(audioname,fichierTampon);

    playMusic(renderer, touches, fichierTampon, audioname);

    remove(fichierTampon);

Quit:
    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();
    free(touches);
    return 0;
}

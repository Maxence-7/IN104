/* Maxence Leguéry & Sam Gadoin */

#include <stdio.h>
#include <stdlib.h>

#include "interface/accueil.h"
#include "interface/clavier.h"
#include "interface/convert_frequence.h"
#include "interface/audio.h"
#include "analyse/getNotes.h"

#define fichierTampon "notes.dat"

int main(int argc, char *argv[]) {
    if(0 != SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return 1;
    }

    char* audioname = malloc(sizeof(char*));

    audioname=initAccueil();

    printf("%s",audioname);

    char* audiopath = malloc(sizeof(char*));
    audiopath="audios/";
    
    char * final_audio_name = (char *) malloc(1 + strlen(audioname)+ strlen(audiopath) );
    strcpy(final_audio_name, audiopath);
    strcat(final_audio_name, audioname);

    printf(":= %s \n", final_audio_name);

    SDL_Color noir = {0, 0, 0, 0};

    /*if(argc<2) {
        printf("Merci de saisir un fichier audio");
        return 0;
    }*/
   // char* audioname = argv[1];

    
    //audioname="audios/gamme_mono.wav";
    //audioname="audios/Laputa.wav";
    //audioname="audios/vivaldi_spring_mono.wav";

   // printf("coucou");
   // strcat(audiopath, audioname);

    audioname=final_audio_name;

    printf("bulbizarre : %s\n", audioname);


    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;



    int r = initSDLClavier(&window, &renderer);
    
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

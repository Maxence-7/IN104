Projet IN104 en C : transcription de notes de piano

# Utilisation

## Installation dépendences

| Librairies |
| ---------- |
| GSL        |
| SDL2       |
| SDL2 - TTF |

* Linux : 
```
$ sudo apt install libgsl-dev
$ sudo apt install libsdl2-dev
$ sudo apt install libsdl2-ttf-dev
```

## Compilation et exécution

```
$ chmod +x ./compilation.sh
$ ./compilation.sh
```

# Documentation

* [SDL2](https://www.libsdl.org/download-2.0.php) Version 2.0.14
* [SDL2-TTF](https://packages.debian.org/fr/sid/libsdl2-ttf-dev) Version 2.0.15
* [GSL](https://www.gnu.org/software/gsl/) Version 2.6

# Contributeurs

* Sam Gadoin
* Maxence Leguéry

# Bug connus

* Retard de l'affichage des notes
* Le 1er fichier de la liste d'audio provoque un "segmentation fault"
# Projet de Gestion d'Ouvrages Vidéo

## Description
Ce projet implémente une application de gestion d'ouvrages vidéo,livre,journal 
comprenant des vidéos,livres,journaux internes et externes, avec des fonctionnalités telles que l'affichage, 
l'emprunt, la mise à jour, etc.

## Structure du Projet
- bibliotheque.h : Définition de la classe bibliotheque.
- ouvrage.h : Définition de la classe de base ouvrage.
- video.h : Définition de la classe video.
- livre.h : Définition de la classe livre.
- Periodique.h : Définition de la classe Periodique.
- videoExterne.h : Implémentation de la classe videoExterne dérivée de video.
- livreExterne.h : Implémentation de la classe livreExterne dérivée de livre.
- PeriodiqueExterne.h : Implémentation de la classe PeriodiqueExterne dérivée de Periodique.
- myapp.cpp : Fichier principal avec la fonction main et l'utilisation des classes.

## justification de certaine methodes et attribues et fonctions ajouter 

attribue :
    -type : pour donne a chaque object un type car dans le main j'ai eu besoin d'affiche le type de louvrage

fonctions :  
    -updateField : pour mieu organiser le code et eviter la repetition du meme code 
                   puisque c'est le meme pour 6 class elle permet de demander a l'utlisateur
                   une valeur string a enter et elle enregistre cette valeur dans l'address memoire
                   passer dans le deuxieme argument (passage par refference
    -UpdateEmpreint : pour la meme motivation de updateField cette fois elle permet de modifier ou de 
                      supprimer l'empriente

dans la class ouvrage j'ai eu recoure au methodes virtuelles pour acceder au meme methode des class deriver

# Projet Jeu vidéo S3 : CE QU'IL RESTE A FAIRE

## =Scrolling ecran :
	° Gestion bordure camera 
	° Centré sur le personnage 

## Collision et rebond surface-surface :
	° gestion rebond 

## Point de Regénération et de Sauvegarde :
	° gestion ficher externe sauvegarde 
	° gestion recupération pv 

## Combat :
### Boucle Attaque : 
	° Boucle Snake
		- sprite corps et tete
		- tableau de corps : updat de position en bloc par bloc 
		- collectable 
		- obstacle : mort INSTANTANNEE
	° Boucle Pong
		- trampoline de pong
		- obstacle : rebond ball (code billard)
		- Perte : depassement d'une bordure -> basse
	° Boucle Casse-Brique
		- trampoline de pong 
		- obstacle : rebond ball + destruction bloc 
		- Perte : depassement d'une bordure -> basse 
### Boucle Esquive :
	° Boucle Fuis les lignes 
		- deplacement ligne par ligne 
		- Degat, collision avec les sprites des attaques perso
	° Boucle Pac man
		- niveau pac man : mur invisible 
		- gestion IA fantome : bloc de changement de position 
		- collision et rebond mur
		- mort du parsonnages 
	° Boucle Cube prison
		- Degat, collision avec les sprites des attaques perso
### Boucle Discution :
	° Interface de choix de la discussion 
		-
	° Impact 

### Boucle Fuir :
	° Interface carte 
		- aleatoire en fonction de la difficulter de l'ennemi
	° Condition EPARGNER
    
## Ennemi :
### Sprite : 
	° Sprite ennemi
	° 4 Sprite pour chaque attaque 
	° 3 Sprite perso pour le pac man
### Paterne :
	° Paterne personnalisé pour chaque jeu

## Map 
### Mur 
		° gestion collision mur invisible
### Objet 
		° gestion collision avec objet
		° Pouvoir passer derriere un objet
## Enigme
		° Bibliotheque

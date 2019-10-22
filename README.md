# Projet Jeu vidéo S3 : CE QU'IL RESTE A FAIRE

## Scrolling ecran :
<ol>
	<li><b>Gestion bordure camera</b></li>
	<li><b>Centré sur le personnage </b></li>
</ol>

## Collision et rebond surface-surface :
<ol>
	<li><b>Gestion rebond </b></li>
</ol>

## Point de Regénération et de Sauvegarde :
<ol>
	<li><b>Gestion ficher externe sauvegarde </b></li>
	<li><b>Gestion recupération pv </b></li>
</ol>

## Combat :
### Boucle Attaque : 
<ol>
	<li><b>Boucle Snake :</b></li>
	<ol>
		<li><b>Sprite : </b>Corps et tete</li>
		<li><b>Tableau de corps : </b>Update de position en bloc par bloc</li>
		<li><b>Collectable</b></li>
		<li><b>Obstacle : </b>Mort instantannée</li>
	</ol>
	<li><b>Boucle Pong :</b></li>
	<ol>
		<li><b>Trampoline de pong</b></li>
		<li><b>Obstacle : </b>Rebond balle</li>
		<li><b>Defaite : </b>Depassement de bordure basse</li>
	</ol>
	<li><b>Boucle Casse-brique</b></li>
	<ol>
		<li><b>Trampoline de pong</b></li>
		<li><b>Obtacle : </b> Rebond balle + Destruction bloc</li>
		<li><b>Defaite : </b>Depassement de bordure basse</li>
	</ol>
</ol>

### Boucle Esquive :
<ol>
	<li><b>Boucle Fuis les lignes :</b></li>
	<ol>
		<li><b>Deplacement : </b>Ligne par ligne</li>
		<li><b>Collision avec les sprites ennemis : </b>Subie des dégats</li>
	</ol>
	<li><b>Boucle Pac-Man </b></li>
	<ol>
		<li><b>Niveau Pac-Man : </b>Mur invisible</li>
		<li><b>Gestion IA : </b> Bloc de changement de direction</li>
		<li><b>Collision : </b>Rebond contre les murs</li>
		<li><b>Touché par un ennemi : </b>Subie des dégats </li>
	</ol>
	<li><b>Boucle Cube Prison</b></li>
	<ol>
		<li><b>Collision aavec les Sprites ennemis : </b> Subie des dégats</li>
	</ol>
</ol>

### Boucle Discution :
<ol>
	<li><b>Interface : </b>3 choix de la discussion </li>
	<li><b>Affichage de la discussion </b></li>
	<li><b>Impact </b></li>
</ol>

### Boucle Fuir :
<ol>
	<li><b>Interface : </b>Carte retourner</li>
	<ol>
		<li><b>Nombre de cartes : </b>En fonction de la difficulté de l'ennemi</li>
		<li><b>Position carte valide aléatoire </b></li>
	</ol>
	<li><b>Condition EPARGNER</b></li>
</ol>
    
## Ennemi :
### Sprite : 
<ol>
	<li><b>Sprite</b></li>
	<ol>
		<li><b>De base : </b>Sprite de l'ennemi du menu combat</li>
		<li><b>4 Sprites : </b>Pour chaque attaque</li>
		<li><b>3 Sprites: </b>Pour les 3 monstres du pac man</li>
	</ol>
</ol>

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

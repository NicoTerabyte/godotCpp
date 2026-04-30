# Questo è lo script per il tuo personaggio giocatore.
extends CharacterBody2D

# La velocità di movimento del personaggio in pixel al secondo.
@export var speed = 250.0

func _physics_process(delta):
	# Ottieni il vettore di input. Questo ti dice in quale direzione il giocatore vuole muoversi.
	# "ui_horizontal" e "ui_vertical" sono mappature di input predefinite in Godot
	# che corrispondono ai tasti freccia e agli stick del gamepad.
	var direction = Input.get_vector("ui_left", "ui_right", "ui_up", "ui_down")

	# Imposta la velocità basandoti sulla direzione e sulla velocità definita.
	# Se la direzione è (0,0) (nessun input), la velocità sarà zero.
	velocity = direction * speed

	# Questa è la funzione principale che muove il personaggio.
	# Gestisce le collisioni con altri corpi fisici.
	move_and_slide()

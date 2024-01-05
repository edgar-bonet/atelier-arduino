## Atelier Arduino – Programmation efficace

![](img/Arduino_uno_r3.jpg)  
<small>Arduino Uno R3 – © Maker Media GmbH – CC BY-SA 4.0</small>

Edgar Bonet

CCSTI Grenoble – 2024-01-06

---

## Présentation

<img src="img/avatar.jpeg" style="float: right">
* Edgar Bonet
  * physicien, spécialisé dans le magnétisme
  * libriste de longue date
  * contributeur fréquent à [Arduino Stackexchange][ase]
  * [contributeur occasionnel][pr] à l'écosystème Arduino
* [Laboratoire Ouvert Grenoblois][log]
  * hackerspace grenoblois
  * partage de connaissances et savoir-faire
* [La Casemate][ccsti]
  * premier CCSTI créé en France
  * expositions, rencontres, ateliers, FabLab...

[ase]: https://arduino.stackexchange.com/
[pr]: https://github.com/pulls?q=author%3Aedgar-bonet+is%3Apr+is%3Amerged+org%3Aadafruit+org%3Aarduino+org%3Aarduino-libraries
[log]: https://www.logre.eu/
[ccsti]: https://lacasemate.fr/

Note: Faire tour de table pour se présenter.  
Dire : attentes, expérience en programmation Arduino, évènementielle,
machines à états.

---

## Programmation non bloquante – Motivation

But : gérer plusieurs tâches en parallèle, sans qu'elles se bloquent
mutuellement.

![Arduino Stack Exchange](img/arduino-se.png) Recherche « blocking
is:answer » → 1 217 résultats

> Many of the programming questions on the Arduino forum can be answered
> with one simple response: Implement a "Finite State Machine."
> — Majenko

Note: Les questions ne sont pas posées en termes de parallélisme.

--

### Stratégies pour gérer des tâches parallèles

1. Un processus/thread par tâche
  * optimal pour tâches lourdes sur un processeur multi-cœur
  * nécessite un OS (ordonnanceur)
  * coût en mémoire (une pile par thread)
2. Gérer des évènements successif dans un thread unique
  * optimal quand la gestion d'un évènement est légère
  * faible coût en mémoire et CPU
  * approche populaire pour le Web (Nginx, Node.js...)

Note: On demande à un Arduino des tâches simples (< 1 ms).  
Il passe le plus clair de son temps à attendre.

---

## Blink without Delay

Fichier → Exemples → 02.Digital → BlinkWithoutDelay

```arduino
int etat_LED = LOW;

unsigned long temps_dernier_changement = 0;  // quand a-t-on changé d'état pour la dernière fois ?

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  unsigned long maintenant = millis();  // l'heure actuelle

  if (maintenant - temps_dernier_changement >= 400) {  // il est temps de changer d'état
    temps_dernier_changement = maintenant;

    if (etat_LED == LOW) {  // calculer le nouvel état
      etat_LED = HIGH;
    } else {
      etat_LED = LOW;
    }

    digitalWrite(13, etat_LED);  // appliquer cet état
  }
}
```

---

## Automates finis

<div style="float: right">
![](img/montre-1.png)
</div>

Ma montre

d'après le mode d'emploi

--

La même montre,  
d'après mes essais.

![](img/montre-2.png)

Note: Les ingénieurs qui l'ont conçue on probablement dessiné un schéma
semblable à celui-ci.

---

## Exercice : feu tricolore

![](img/feu_tricolore.png)

Note: Comment ajouter un bouton d'appel piétons ?

--

![](img/feu_tricolore-2.png)

Note: Problème : et si un gamin facétieux appuie sur le bouton à chaque
fois que le feu passe au vert ?

--

![](img/feu_tricolore-3.png)

Note: Problème : si un piéton appelle dans l'état VERT, l'appel n'est
pas pris en compte.

--

![](img/feu_tricolore-4.png)

## Atelier Arduino

![](img/Arduino_uno_r3.jpg)  
<small>Arduino Uno R3 – © Maker Media GmbH – CC BY-SA 4.0</small>

Edgar Bonet

CCSTI Grenoble – 2023-03-30

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
Dire : attentes, expérience en électronique, programmation, C/C++

---

## Arduino : Matériel

![](img/Arduino-serial.jpg)  
<small>Arduino Serial (2005) – © Nicholas Zambetti – CC BY-SA 3.0</small>

* depuis 2005 : cartes classiques AVR, 8 bits
* cartes plus puissantes à architecture ARM 32 bits
* clones et contrefaçons
* cartes tierces plus ou moins compatibles

Note: Open Source Hardware.

--

### Utilisations

Une carte Arduino peut être :
* intégrée définitivement à un projet
* servir uniquement de plateforme de prototypage ([exemple][])

[exemple]: https://www.phi.kit.edu/jobs_1452.php

Note: Il y a des petites cartes adaptées à l'intégration sur PCB.

---

## Arduino : Logiciel

<img src="img/ide.png" style="float: right">
* côté hôte : outils de développement
  * IDE (versions 1.8 et 2.0)
  * arduino-cli

* côté cible : bibliothèques
  * Arduino core
  * bibliothèques Arduino
  * bibliothèques tierces

![](img/arduino-libs.png)

Note: Aussi : Arduino Web Editor

Open Source Software.

---

## Arduino : Communauté

* partage (blogs, instructables)  
  ![](img/arduino-blog.png)
  ![](img/hackaday.png)
  ![](img/adafruit.png)
  ![](img/instructables.png)
  ![](img/logo-log.png)
  ...

* entre-aide (forum, stackexchange)  
  ![](img/arduino-forum.png)
  ![](img/arduino-se.png)
  ...

* IRL  
  ![](img/casemate.png)
  ...

---

## Téléchargement de l'IDE

![](img/arduino-dl.png)

---

## Prise en main de l'IDE

* configurer :  
  Fichier → Préférences → Avertissement du compilateur :
  « Plus » ou « Tout »  
  ![](img/prefs.png)

* charger un programme :  
  Fichier → Exemples → 01.Basics → Blink

* téléverser :  
  Bouton
  <img src="img/upload-button.png" style="margin: 0 5px; border: 0">

---

## Faire clignoter la LED

**Exemple fourni**:

```arduino
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // configurer la broche 13 en sortie
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // allumer
  delay(1000);                      // attendre
  digitalWrite(LED_BUILTIN, LOW);   // éteindre
  delay(1000);                      // attendre
}
```

Note: Expliquer le code.

**Exercices**:
* changer les commentaires et les durées
* rythme : noire, noire, demi-pause (blanche)

---

## Bases de C++

Voir pense-bête.

* langage complexe, on se limite à un sous-ensemble simple
* syntaxe très stricte
* l'indentation aide à voir la structure du code

Référence du langage et des bibliothèques standard :
https://www.arduino.cc/reference/en/

Note: Sensible à la case.

Inventer de la syntaxe ne marche pas.

Ctrl-T pour indenter.

---

## Schéma générique d'un projet Arduino

![](img/schema-generique-1.png)

* des organes d'entrée (capteurs)
* un Arduino pour faire le traitement des données
* des organes de sortie (actionneurs)

--

![](img/schema-generique-2.png)

* optionnellement, communication avec un ordinateur

```arduino
// Dans setup() :
Serial.begin(9600);

Serial.println(message ou variable ou expression);
```

---

## Bases d'électronique

![](img/resistance.png)

U = R i  
i = U / R

Note: Analogie hydraulique :
* source, résistance
* i, V (référence arbitraire), U

Fils équipotentiels (R ≈ 0).

--

### Pont diviseur de tension

![](img/pont.png)

Uₛ = R₁/(R₁+R₂) × Uₑ

Note: voir cas dégénérés
* R₂ = 0 ou ∞
* R₁ = 0 ou ∞
* (R₁ et R₂) = 0 ou ∞

--

### Entrées de l'Arduino

![](img/entrees.png)

```arduino
// Dans setup() :
pinMode(numero_de_broche, INPUT);

int valeur_analogique = analogRead(numero_de_broche);
float U = valeur_analogique / 1024.0 * 5.0;  // en volts

int valeur_logique = digitalRead(numero_de_broche);
```

Note: Importance du « .0 ».

Limites en tension.

--

### Sorties de l'Arduino

![](img/sorties.png)

```arduino
// Dans setup() :
pinMode(numero_de_broche, OUTPUT);

digitalWrite(numero_de_broche, LOW);   // LOW = 0
digitalWrite(numero_de_broche, HIGH);  // LOW = 1

analogWrite(numero_de_broche, valeur);  // valeur = 0 à 255
```

Note: Limites en courant.

---

## Recettes

### Capteur résistif

![](img/ldr.png)

Tension mesurée : U = R/(R+R₀) × (5 V)

```arduino
int lecture = analogRead(numero_de_broche);
float R = lecture / (1024.0 - lecture) * R0;
```

Note: i = 0

Si on inverse R et R₀:  
R = (1024.0 - lecture) / lecture * R0

Choix de R₀.

--

### Potentiomètre

![](img/potard.png)

Tension mesurée : U = x ⋅ (5 V)

```arduino
float x = analogRead(numero_de_broche) / 1024.0;  // entre 0 et 1
```

--

### Bouton

![](img/button.png)

```arduino
if (digitalRead(numero_de_broche) == HIGH) {
    // Le bouton est pressé
}

if (digitalRead(numero_de_broche) == LOW) {
    // Le bouton est pressé
}
```

Note: Choix de R.

Noms : pull-up, pull-down.

Dans le kit : pull-down.

Debounce.

--

### Bouton avec pull-up interne

![](img/internal-pu.png)

```arduino
// Dans setup() :
pinMode(numero_de_broche, INPUT_PULLUP);

if (digitalRead(numero_de_broche) == LOW) {
    // Le bouton est pressé
}
```

--

### LED

![](img/led.png)

```arduino
digitalWrite(numero_de_broche, HIGH);  // allume la LED
digitalWrite(numero_de_broche, LOW);   // éteint la LED
```

Note: Aussi PWM.

--

### Moteur, relais...

![](img/motor.png)

```arduino
digitalWrite(numero_de_broche, HIGH);  // moteur allumé
digitalWrite(numero_de_broche, LOW);   // moteur éteint
```

Note: et électrovanne, actionneur linéaire...

Potentiellement Vcc ≠ +5V, masse commune.

Aussi PWM, MOSFET, pont en H.

--

### Servo de modélisme

![](img/servo.png)

```arduino
// Au tout début :
#include <Servo.h>
Servo servo;

// Dans setup() :
servo.attach(numero_de_broche);

servo.write(angle);  // en degrés, entre 0 et 180
```

Note: Vcc peut être +5V si **petit** servo.

Voir exemples fournis avec l'IDE Arduino.

---

## Exercices

1 entrée et 1 sortie

---

## Programmation non bloquante

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

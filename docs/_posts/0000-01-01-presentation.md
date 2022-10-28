## Atelier Arduino

![](img/Arduino_uno_r3.jpg)  
<small>Arduino Uno R3 – © Maker Media GmbH – CC BY-SA 4.0</small>

Edgar Bonet

CCSTI Grenoble – 2022-11-03

---

## Présentation

<img src="img/avatar.jpeg" style="float: right">
* Edgar Bonet
  * physicien, spécialisé dans le magnétisme
  * libriste de longue date
  * contributeur majeur à [Arduino Stackexchange][ase]
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

---

## Arduino : Logiciel

<img src="img/ide.png" style="float: right">
* côté hôte : outils de développement
  * IDE
  * arduino-cli

* côté cible : bibliothèques
  * Arduino core
  * bibliothèques Arduino
  * bibliothèques tierces

![](img/arduino-libs.png)

Note: Aussi : Arduino Web Editor

---

## Arduino : Communauté

* partage (blogs, instructables)  
  ![](img/arduino-blog.png)
  ![](img/hackaday.png)
  ![](img/adafruit.png)
  ![](img/instructables.png)
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

**Exercice** : modifier le rythme :
deux flashs, courte pause, deux flashs, courte pause...

Note: rythme : noire, noire, demi-pause (blanche)

---

## Bases de C++

fiche résumé

---

## Schéma générique d'un projet Arduino
entrées (capteurs), décision (logique), sorties (actionneurs)
+ communications avec l'hôte

---

## Bases d'électronique

analogie hydraulique

entrée = circuit ouvert, sortie connexion à GND ou Vcc

---

## Pont diviseur de tension

cas dégénérés (R = 0 ou ∞, court-circuit, entrée flottante)

---

## Recettes

potentiomètre, LDR ou thermistance

bouton (avec ou sans debounce)

LED (avec ou sans PWM)

sortie fort courant (transistor)

charge inductive (transistor + diode roue libre)

moteur (PWM)

---

## Exercices

1 entrée et 1 sortie

---

## Programmation non bloquante

---

## Blink without Delay

Fichier → Exemples → 02.Digital → BlinkWithoutDelay

---

## Automates finis

<div style="float: right">
![](img/montre-1.png)
</div>

Ma montre

d'après le mode d'emploi

--

![](img/montre-2.png)

---

## Exercice : feu tricolore

![](img/feu_tricolore.png)

--

![](img/feu_tricolore-2.png)

--

![](img/feu_tricolore-3.png)

--

![](img/feu_tricolore-4.png)

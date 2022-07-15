## Atelier Arduino

Edgar Bonet

CCSTI Grenoble – 2022-07-28

---

## Présentation

moi (physicien, contributeur Open Source), le LOG, la Casemate

(tour de table de présentations : attentes, expéricene en
électronique, programmation, C/C++)

(Arduino = matériel + logiciel + communauté)

---

## Arduino : Matériel

évolution vers Uno, cartes + puissantes, clones et compatibles

---

## Arduino : Logiciel

hôte (IDE, cli, cloud), cible (core, bibl. Arduino et tierces)

---

## Arduino : Communauté

partage (blogs, instructables), entre-aide (forum, stackexchange)
IRL ?


---

## Prise en main de l'IDE

téléchargement (juste montré)

Fichier → Préférences → Avertissement du compilateur :
« Plus » ou « Tout ».

Fichier → Exemples → 01.Basics → Blink

Bouton « Téléverser » (→)

---

## Exercice : clignoter la LED

rythme : noire, noire, demi-pause (blanche)

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

entrée = circuit ouvert, sortie connection à GND ou Vcc

---

## Pont diviseur de tension

cas dégénérés (R = 0 ou ∞, court-circuit, entrée flottante)

---

## Recettes

potard, LDR ou thermistance

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

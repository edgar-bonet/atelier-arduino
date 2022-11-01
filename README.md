# Atelier d'initiation à l'Arduino

Ce dépôt contient les sources des documents que j'ai préparés pour un
atelier d'initiation Arduino. Cet atelier est prévu pour le 3 novembre
2022, au [CCSTI Grenoble « La Casemate »][casemate].

## Contenu

* [docs](docs) : sources Markdown du [support de présentation][slides]
* [cpp-cheatsheet](cpp-cheatsheet) : sources LaTeX du pense-bête
  Arduino/C++
* [examples](examples) : code source de deux programmes d'exemple
  * blink-without-delay
  * feu-tricolore

Le support de présentation est basé sur [jekyll-reveal.js][], lui même
basé sur [reveal.js][]. Tous les fichiers du répertoire docs
appartiennent au projet jekyll-reveal.js, à l'exception des
sous-répertoires :

* docs/reveal.js : sources de reveal.js
* docs/\_posts et docs/img : le contenu spécifique à cette présentation.

## Licences

* ce dépôt : © 2022 Edgar Bonet, CC-BY-SA-4.0
* jekyll-reveal.js : © 2013 Dennis Ploeger, BSD-2-Clause
* reveal.js : © 2011–2022 Hakim El Hattab, MIT

[casemate]: https://lacasemate.fr/
[slides]: https://edgar-bonet.github.io/atelier-arduino/
[jekyll-reveal.js]: https://github.com/dploeger/jekyll-revealjs
[reveal.js]: https://github.com/hakimel/reveal.js

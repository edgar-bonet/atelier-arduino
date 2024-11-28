# Atelier d'initiation à l'Arduino

Ce dépôt contient les sources des documents que j'ai préparés pour des
ateliers d'initiation Arduino au [CCSTI Grenoble « La
Casemate »][casemate]. Ces ateliers ont lieu depuis novembre 2022. Ils
se déclinent en trois niveaux de difficulté croissante.

## Contenu

* [docs](docs) : sources Markdown des [supports de présentation][slides]
* [cpp-cheatsheet](cpp-cheatsheet) : sources LaTeX du pense-bête
  Arduino/C++
* [examples](examples) : code source des programmes d'exemple

Les supports de présentation sont basés sur [jekyll-reveal.js][], lui
même basé sur [reveal.js][]. Tous les fichiers du répertoire docs
appartiennent au projet jekyll-reveal.js, à l'exception des
sous-répertoires :

* docs/\_slides/reveal.js : sources de reveal.js
* docs/\_slides : le contenu spécifique à ces présentations
* docs/index.html : page listant les présentations.

## Licences

* ce dépôt : © 2022–2024 Edgar Bonet, CC-BY-SA-4.0
* jekyll-reveal.js : © 2013 Dennis Ploeger, BSD-2-Clause
* reveal.js : © 2011–2022 Hakim El Hattab, MIT

[casemate]: https://lacasemate.fr/
[slides]: https://edgar-bonet.github.io/atelier-arduino/
[jekyll-reveal.js]: https://github.com/dploeger/jekyll-revealjs
[reveal.js]: https://github.com/hakimel/reveal.js

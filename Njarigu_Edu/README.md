# 🌍 NJARIGU - La Révolution Éducative Africaine

## Vision
**Njarigu** (qui signifie "Savoir/Lumière" dans plusieurs langues africaines) est une plateforme éducative intelligente, interactive et gratuite conçue pour transformer l'éducation en Afrique et dans le monde.

### Mission
Rendre l'éducation africaine riche, moderne, rapide et accessible dès le plus jeune âge, en intégrant :
- Les disciplines académiques classiques (Maths, Français, Sciences)
- La culture africaine et les religions
- La robotique et l'informatique
- Les arts (musique, danse, cinéma, architecture)
- La médecine de base et la biologie
- La créativité et l'innovation

## Architecture Technique

### Stack Technologique (100% Gratuit & Open Source)
- **Cœur :** C++17/20 (Logique métier, IA locale, moteur de jeu)
- **Interface Web :** HTML5 + CSS3 + JavaScript (pour l'affichage)
- **Compilation Web :** WebAssembly (Wasm) via Emscripten
- **Base de données :** SQLite (local, hors-ligne)
- **Graphismes :** SDL2 / Canvas API
- **Hébergement :** GitHub Pages (gratuit)

### Fonctionnalités Clés
1. **Mode Hors-Ligne :** Fonctionne sans connexion après premier chargement
2. **Multi-joueurs Local :** Défis en duel, trio ou équipe sur même écran
3. **IA Adaptative :** Ajuste la difficulté selon les performances
4. **Progression par Âge :** De la maternelle à la terminale
5. **Pédagogie Ludique :** Apprentissage par le jeu avec graphismes attrayants
6. **Contenu Riche :** 15+ disciplines avec niveaux progressifs

## Structure du Projet

```
Njarigu_Edu/
├── src/                    # Code source C++
│   ├── main.cpp           # Point d'entrée
│   ├── engine/            # Moteur de jeu
│   ├── ai/                # Intelligence adaptative
│   ├── curriculum/        # Gestion des cours
│   └── multiplayer/       # Mode multi-joueurs
├── include/               # Fichiers d'en-tête
├── assets/                # Ressources graphiques et audio
├── data/                  # Bases de données et contenus
│   ├── curriculum/        # Cours par discipline et niveau
│   ├── users/             # Profils élèves
│   └── progress/          # Suivi de progression
├── web/                   # Interface web (HTML/CSS/JS)
└── build/                 # Fichiers compilés
```

## Disciplines Incluses

### Niveau Fondamental (Maternelle - CM2)
- 📚 Français (lecture, écriture, conjugaison)
- 🔢 Mathématiques (calcul, géométrie ludique)
- 🌍 Découverte du monde (culture africaine)
- 🎨 Arts créatifs (dessin, musique, danse)
- 🤖 Initiation robotique

### Niveau Moyen (6ème - 3ème)
- 📖 Littérature et grammaire avancée
- 📐 Mathématiques appliquées
- 🔬 Sciences (biologie, physique, chimie)
- 💻 Informatique de base
- 🏛️ Architecture et construction
- 🎭 Cinéma et arts dramatiques

### Niveau Secondaire (Seconde - Terminale)
- 🧮 Mathématiques supérieures
- 🧪 Sciences approfondies
- 🏥 Médecine de base
- ⚙️ Robotique avancée
- 🌐 Culture générale africaine et mondiale
- 💡 Innovation et entrepreneuriat

## Système de Progression

### Mécanique de Jeu
1. **Phase d'Apprentissage :** Leçons interactives avec graphismes animés
2. **Phase de Pratique :** Exercices guidés avec feedback immédiat
3. **Phase de Défi :** Duels contre l'IA ou autres joueurs
4. **Phase de Création :** Projets pratiques pour appliquer les connaissances

### Niveaux de Compétence
- 🌱 Débutant (Découverte)
- 🌿 Apprenti (Compréhension)
- 🌳 Compétent (Application)
- 🦅 Expert (Maîtrise)
- 🌟 Génie (Innovation)

## Installation et Développement

### Prérequis
- Windows 10/11 (Core i5, 6GB RAM minimum)
- Connection internet (1Mbps suffisant)
- Navigateur moderne (Chrome, Firefox, Edge)

### Étapes d'Installation
1. Installer [Visual Studio Code](https://code.visualstudio.com/)
2. Installer [Emscripten SDK](https://emscripten.org/)
3. Cloner le dépôt
4. Compiler avec `emcc`
5. Ouvrir dans le navigateur

## Contribution

Ce projet est ouvert à tous les éducateurs, développeurs et passionnés qui souhaitent améliorer l'éducation en Afrique.

### Comment Aider ?
- 📝 Fournir du contenu pédagogique
- 🎨 Créer des illustrations et animations
- 💻 Développer de nouvelles fonctionnalités
- 🧪 Tester et rapporter des bugs
- 📢 Partager le projet

## License

Projet Open Source - License MIT

---

**"L'éducation est l'arme la plus puissante pour changer le monde." - Nelson Mandela**

Rejoignons-nous pour construire l'avenir de l'Afrique, un enfant à la fois.

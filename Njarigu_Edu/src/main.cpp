#include "engine.h"
#include <iostream>
#include <algorithm>
#include <cmath>

namespace Njarigu {

Engine::Engine() 
    : currentState(GameState::MENU)
    , difficultyMultiplier(1.0f)
    , consecutiveSuccess(0)
    , consecutiveFailures(0) {
}

Engine::~Engine() {
    shutdown();
}

bool Engine::initialize() {
    std::cout << "🌍 Initialisation de NJARIGU - La Révolution Éducative Africaine" << std::endl;
    std::cout << "==================================================================" << std::endl;
    
    // Charger les leçons et défis
    loadLessons();
    loadChallenges();
    
    std::cout << "✓ Moteur initialisé avec succès!" << std::endl;
    std::cout << "✓ " << availableLessons.size() << " leçons chargées" << std::endl;
    std::cout << "✓ " << availableChallenges.size() << " défis disponibles" << std::endl;
    
    return true;
}

void Engine::shutdown() {
    std::cout << "Sauvegarde de la progression..." << std::endl;
    saveProgress();
    players.clear();
    availableLessons.clear();
    availableChallenges.clear();
}

void Engine::addPlayer(const Player& player) {
    players.push_back(player);
    std::cout << "👤 Joueur ajouté: " << player.name << std::endl;
}

void Engine::removePlayer(int index) {
    if (index >= 0 && index < static_cast<int>(players.size())) {
        std::cout << "👤 Joueur retiré: " << players[index].name << std::endl;
        players.erase(players.begin() + index);
    }
}

std::vector<Player>& Engine::getPlayers() {
    return players;
}

GameState Engine::getState() const {
    return currentState;
}

void Engine::setState(GameState state) {
    GameState previous = currentState;
    currentState = state;
    
    std::string stateNames[] = {
        "MENU", "LEARNING", "PRACTICE", "CHALLENGE", 
        "CREATION", "PAUSE", "GAME_OVER"
    };
    
    std::cout << "🔄 État changé: " << stateNames[static_cast<int>(previous)] 
              << " -> " << stateNames[static_cast<int>(state)] << std::endl;
}

void Engine::loadLessons() {
    std::cout << "📚 Chargement des leçons..." << std::endl;
    
    // Exemple de leçons pour différentes disciplines et niveaux
    // Ces données seront remplacées par ton contenu pédagogique complet
    
    // Mathématiques - Maternelle
    Lesson math1;
    math1.id = "MATH_MAT_001";
    math1.title = "Découvrir les nombres de 1 à 10";
    math1.discipline = Discipline::MATHEMATIQUES;
    math1.requiredLevel = SchoolLevel::MATERNELLE;
    math1.content = "Apprenons à compter avec des objets colorés!";
    math1.objectives = {"Reconnaître les chiffres", "Compter jusqu'à 10", "Associer nombre et quantité"};
    math1.durationMinutes = 15;
    availableLessons.push_back(math1);
    
    // Français - CP/CE1
    Lesson fr1;
    fr1.id = "FR_CP_001";
    fr1.title = "Les voyelles magiques";
    fr1.discipline = Discipline::FRANCAIS;
    fr1.requiredLevel = SchoolLevel::CP_CE1;
    fr1.content = "Découvre les voyelles A, E, I, O, U, Y";
    fr1.objectives = {"Identifier les voyelles", "Prononcer correctement", "Écrire les voyelles"};
    fr1.durationMinutes = 20;
    availableLessons.push_back(fr1);
    
    // Culture Africaine - Tous niveaux
    Lesson cult1;
    cult1.id = "CULT_GEN_001";
    cult1.title = "Les grands empires africains";
    cult1.discipline = Discipline::CULTURE_AFRICAINE;
    cult1.requiredLevel = SchoolLevel::CM2;
    cult1.content = "Voyage à travers l'histoire du Mali, du Ghana et du Songhaï";
    cult1.objectives = {"Connaître les empires précoloniaux", "Comprendre leur organisation", "Apprécier l'héritage culturel"};
    cult1.durationMinutes = 30;
    availableLessons.push_back(cult1);
    
    // Robotique - Collège
    Lesson rob1;
    rob1.id = "ROBO_COL_001";
    rob1.title = "Introduction à la robotique";
    rob1.discipline = Discipline::ROBOTIQUE;
    rob1.requiredLevel = SchoolLevel::SIXIEME_CINQUIEME;
    rob1.content = "Qu'est-ce qu'un robot? Comment fonctionne-t-il?";
    rob1.objectives = {"Comprendre les bases de la robotique", "Identifier les composants", "Créer un premier programme simple"};
    rob1.durationMinutes = 45;
    availableLessons.push_back(rob1);
    
    std::cout << "✓ " << availableLessons.size() << " leçons chargées" << std::endl;
}

void Engine::loadChallenges() {
    std::cout << "⚔️ Chargement des défis..." << std::endl;
    
    // Défi Mathématiques - Duel
    Challenge mathChallenge;
    mathChallenge.id = "MATH_DUEL_001";
    mathChallenge.title = "Guerre des Calculs Rapides";
    mathChallenge.discipline = Discipline::MATHEMATIQUES;
    mathChallenge.difficulty = 3;
    mathChallenge.timeLimit = 60;
    mathChallenge.playersCount = 2;
    mathChallenge.description = "Affronte ton adversaire dans un duel de calcul mental!";
    mathChallenge.rewardCoins = 50;
    availableChallenges.push_back(mathChallenge);
    
    // Défi Français - Solo
    Challenge frChallenge;
    frChallenge.id = "FR_SOLO_001";
    frChallenge.title = "La Chasse aux Mots";
    frChallenge.discipline = Discipline::FRANCAIS;
    frChallenge.difficulty = 2;
    frChallenge.timeLimit = 90;
    frChallenge.playersCount = 1;
    frChallenge.description = "Trouve tous les mots cachés dans le temps imparti!";
    frChallenge.rewardCoins = 30;
    availableChallenges.push_back(frChallenge);
    
    // Défi Culture - Équipe
    Challenge cultChallenge;
    cultChallenge.id = "CULT_TEAM_001";
    cultChallenge.title = "Quiz des Civilisations Africaines";
    cultChallenge.discipline = Discipline::CULTURE_AFRICAINE;
    cultChallenge.difficulty = 5;
    cultChallenge.timeLimit = 120;
    cultChallenge.playersCount = 3;
    cultChallenge.description = "En équipe, répondez aux questions sur l'histoire africaine!";
    cultChallenge.rewardCoins = 100;
    availableChallenges.push_back(cultChallenge);
    
    std::cout << "✓ " << availableChallenges.size() << " défis chargés" << std::endl;
}

Lesson* Engine::getLessonById(const std::string& id) {
    for (auto& lesson : availableLessons) {
        if (lesson.id == id) {
            return &lesson;
        }
    }
    return nullptr;
}

std::vector<Lesson> Engine::getLessonsForLevel(SchoolLevel level) {
    std::vector<Lesson> result;
    for (const auto& lesson : availableLessons) {
        if (lesson.requiredLevel == level) {
            result.push_back(lesson);
        }
    }
    return result;
}

Challenge* Engine::getChallengeById(const std::string& id) {
    for (auto& challenge : availableChallenges) {
        if (challenge.id == id) {
            return &challenge;
        }
    }
    return nullptr;
}

std::vector<Challenge> Engine::getChallengesForDiscipline(Discipline disc) {
    std::vector<Challenge> result;
    for (const auto& challenge : availableChallenges) {
        if (challenge.discipline == disc) {
            result.push_back(challenge);
        }
    }
    return result;
}

// Système intelligent d'adaptation de la difficulté
void Engine::analyzePerformance(bool success, int difficulty) {
    if (success) {
        consecutiveSuccess++;
        consecutiveFailures = 0;
        
        // Augmenter progressivement la difficulté si succès consécutifs
        if (consecutiveSuccess >= 3) {
            difficultyMultiplier += 0.1f;
            consecutiveSuccess = 0;
            std::cout << "📈 Niveau augmenté! Difficulté: x" << difficultyMultiplier << std::endl;
        }
    } else {
        consecutiveFailures++;
        consecutiveSuccess = 0;
        
        // Réduire la difficulté si échecs consécutifs
        if (consecutiveFailures >= 2) {
            difficultyMultiplier = std::max(0.5f, difficultyMultiplier - 0.15f);
            consecutiveFailures = 0;
            std::cout << "📉 Niveau ajusté à la baisse. Difficulté: x" << difficultyMultiplier << std::endl;
        }
    }
}

float Engine::getAdaptiveDifficulty() {
    return difficultyMultiplier;
}

void Engine::resetAdaptiveSystem() {
    difficultyMultiplier = 1.0f;
    consecutiveSuccess = 0;
    consecutiveFailures = 0;
    std::cout << "🔄 Système d'adaptation réinitialisé" << std::endl;
}

bool Engine::saveProgress() {
    // Simulation de sauvegarde (sera implémentée avec SQLite plus tard)
    std::cout << "💾 Progression sauvegardée pour " << players.size() << " joueur(s)" << std::endl;
    return true;
}

bool Engine::loadProgress() {
    // Simulation de chargement
    std::cout << "📂 Chargement de la progression précédente..." << std::endl;
    return true;
}

void Engine::run() {
    std::cout << "\n🎮 Démarrage de la boucle de jeu NJARIGU" << std::endl;
    std::cout << "========================================" << std::endl;
    
    // Boucle principale simplifiée pour la console
    bool running = true;
    
    while (running && currentState != GameState::GAME_OVER) {
        update(0.016f); // ~60 FPS
        render();
        
        // Condition de sortie pour la démo
        if (currentState == GameState::MENU) {
            std::cout << "\n--- MENU PRINCIPAL ---" << std::endl;
            std::cout << "1. Commencer une leçon" << std::endl;
            std::cout << "2. Relever un défi" << std::endl;
            std::cout << "3. Voir la progression" << std::endl;
            std::cout << "4. Quitter" << std::endl;
            std::cout << "Choix: ";
            
            int choice;
            std::cin >> choice;
            
            switch (choice) {
                case 1:
                    setState(GameState::LEARNING);
                    break;
                case 2:
                    setState(GameState::CHALLENGE);
                    break;
                case 3:
                    std::cout << "\n📊 PROGRESSION DES JOUEURS:" << std::endl;
                    for (const auto& player : players) {
                        std::cout << "  - " << player.name << ": " << player.score << " points, " 
                                  << player.coins << " pièces" << std::endl;
                    }
                    break;
                case 4:
                    running = false;
                    break;
                default:
                    std::cout << "Choix invalide!" << std::endl;
            }
        } else if (currentState == GameState::LEARNING) {
            std::cout << "\n📚 MODE APPRENTISSAGE" << std::endl;
            std::cout << "Leçons disponibles:" << std::endl;
            for (size_t i = 0; i < availableLessons.size(); i++) {
                std::cout << "  " << (i+1) << ". " << availableLessons[i].title << std::endl;
            }
            std::cout << "0. Retour au menu" << std::endl;
            std::cout << "Choix: ";
            
            int choice;
            std::cin >> choice;
            
            if (choice > 0 && choice <= static_cast<int>(availableLessons.size())) {
                std::cout << "\n🎯 Leçon sélectionnée: " << availableLessons[choice-1].title << std::endl;
                std::cout << "Objectifs: ";
                for (const auto& obj : availableLessons[choice-1].objectives) {
                    std::cout << "\n     • " << obj;
                }
                std::cout << "\n\n[Dans la version complète, cette leçon serait interactive avec graphismes!]" << std::endl;
                
                // Simuler la complétion
                std::cout << "\nAppuyez sur Entrée pour compléter la leçon..." << std::endl;
                std::cin.ignore();
                std::cin.get();
                
                // Ajouter des points
                if (!players.empty()) {
                    players[0].score += 100;
                    players[0].coins += 20;
                    std::cout << "✓ Leçon terminée! +100 points, +20 pièces" << std::endl;
                    
                    // Analyser la performance (simulée)
                    analyzePerformance(true, 1);
                }
            }
            
            setState(GameState::MENU);
        } else if (currentState == GameState::CHALLENGE) {
            std::cout << "\n⚔️ MODE DÉFI" << std::endl;
            std::cout << "Défis disponibles:" << std::endl;
            for (size_t i = 0; i < availableChallenges.size(); i++) {
                std::cout << "  " << (i+1) << ". " << availableChallenges[i].title 
                          << " (" << availableChallenges[i].playersCount << " joueurs, "
                          << availableChallenges[i].timeLimit << "s)" << std::endl;
            }
            std::cout << "0. Retour au menu" << std::endl;
            std::cout << "Choix: ";
            
            int choice;
            std::cin >> choice;
            
            if (choice > 0 && choice <= static_cast<int>(availableChallenges.size())) {
                Challenge& chal = availableChallenges[choice-1];
                std::cout << "\n🎮 DÉFI: " << chal.title << std::endl;
                std::cout << "Description: " << chal.description << std::endl;
                std::cout << "Récompense: " << chal.rewardCoins << " pièces" << std::endl;
                
                std::cout << "\n[Dans la version complète, ce défi serait un jeu interactif multijoueur!]" << std::endl;
                
                // Simuler la complétion
                std::cout << "\nAppuyez sur Entrée pour commencer le défi..." << std::endl;
                std::cin.ignore();
                std::cin.get();
                
                // Ajouter des récompenses
                if (!players.empty()) {
                    players[0].score += chal.rewardCoins * 2;
                    players[0].coins += chal.rewardCoins;
                    std::cout << "✓ Défi terminé! +" << (chal.rewardCoins * 2) << " points, +" 
                              << chal.rewardCoins << " pièces" << std::endl;
                    
                    analyzePerformance(true, chal.difficulty);
                }
            }
            
            setState(GameState::MENU);
        }
    }
}

void Engine::update(float deltaTime) {
    // Logique de mise à jour du jeu
    // Sera implémentée avec le moteur graphique
}

void Engine::render() {
    // Rendu graphique
    // Sera implémenté avec SDL2/Canvas pour la version web
}

} // namespace Njarigu

// Point d'entrée principal
int main() {
    Njarigu::Engine engine;
    
    if (!engine.initialize()) {
        std::cerr << "Erreur d'initialisation!" << std::endl;
        return 1;
    }
    
    // Créer un joueur de démonstration
    Njarigu::Player player1;
    player1.name = "Élève Héros";
    player1.age = 8;
    player1.level = Njarigu::SchoolLevel::CP_CE1;
    engine.addPlayer(player1);
    
    // Lancer l'application
    engine.run();
    
    engine.shutdown();
    
    std::cout << "\n🌟 Merci d'avoir utilisé NJARIGU!" << std::endl;
    std::cout << "Ensemble, construisons l'avenir de l'éducation africaine!" << std::endl;
    
    return 0;
}

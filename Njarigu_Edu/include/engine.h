#ifndef NJARIGU_ENGINE_H
#define NJARIGU_ENGINE_H

#include <string>
#include <vector>
#include <memory>

namespace Njarigu {

// États du jeu
enum class GameState {
    MENU,
    LEARNING,
    PRACTICE,
    CHALLENGE,
    CREATION,
    PAUSE,
    GAME_OVER
};

// Disciplines disponibles
enum class Discipline {
    FRANCAIS,
    MATHEMATIQUES,
    SCIENCES,
    BIOLOGIE,
    ROBOTIQUE,
    INFORMATIQUE,
    ARTS,
    MUSIQUE,
    DANSE,
    CINEMA,
    ARCHITECTURE,
    MEDECINE,
    CULTURE_AFRICAINE,
    RELIGION,
    CREATIVITE
};

// Niveaux scolaires
enum class SchoolLevel {
    MATERNELLE,
    CP_CE1,
    CE2_CM1,
    CM2,
    SIXIEME_CINQUIEME,
    QUATRIEME_TROISIEME,
    SECONDE,
    PREMIERE,
    TERMINALE
};

// Niveaux de compétence
enum class SkillLevel {
    DEBUTANT,    // 🌱
    APPRENTI,    // 🌿
    COMPETENT,   // 🌳
    EXPERT,      // 🦅
    GENIE        // 🌟
};

// Structure pour un joueur
struct Player {
    std::string name;
    int age;
    SchoolLevel level;
    std::vector<SkillLevel> skills;
    int score;
    int coins; // Monnaie virtuelle
    std::vector<std::string> unlockedDisciplines;
    
    Player() : age(0), level(SchoolLevel::MATERNELLE), score(0), coins(0) {}
};

// Structure pour une leçon
struct Lesson {
    std::string id;
    std::string title;
    Discipline discipline;
    SchoolLevel requiredLevel;
    std::string content;
    std::vector<std::string> objectives;
    int durationMinutes;
    bool isCompleted;
    
    Lesson() : requiredLevel(SchoolLevel::MATERNELLE), durationMinutes(10), isCompleted(false) {}
};

// Structure pour un défi
struct Challenge {
    std::string id;
    std::string title;
    Discipline discipline;
    int difficulty; // 1-10
    int timeLimit; // en secondes
    int playersCount; // 1 = solo, 2+ = multijoueur
    std::string description;
    int rewardCoins;
    
    Challenge() : difficulty(1), timeLimit(60), playersCount(1), rewardCoins(10) {}
};

// Moteur principal de l'application
class Engine {
private:
    GameState currentState;
    std::vector<Player> players;
    std::vector<Lesson> availableLessons;
    std::vector<Challenge> availableChallenges;
    
    // IA adaptative
    float difficultyMultiplier;
    int consecutiveSuccess;
    int consecutiveFailures;
    
public:
    Engine();
    ~Engine();
    
    // Initialisation
    bool initialize();
    void shutdown();
    
    // Gestion des joueurs
    void addPlayer(const Player& player);
    void removePlayer(int index);
    std::vector<Player>& getPlayers();
    
    // Gestion des états
    GameState getState() const;
    void setState(GameState state);
    
    // Gestion des leçons
    void loadLessons();
    Lesson* getLessonById(const std::string& id);
    std::vector<Lesson> getLessonsForLevel(SchoolLevel level);
    
    // Gestion des défis
    void loadChallenges();
    Challenge* getChallengeById(const std::string& id);
    std::vector<Challenge> getChallengesForDiscipline(Discipline disc);
    
    // Système intelligent d'adaptation
    void analyzePerformance(bool success, int difficulty);
    float getAdaptiveDifficulty();
    void resetAdaptiveSystem();
    
    // Boucle de jeu principale
    void run();
    void update(float deltaTime);
    void render();
    
    // Sauvegarde et chargement
    bool saveProgress();
    bool loadProgress();
};

} // namespace Njarigu

#endif // NJARIGU_ENGINE_H


#ifndef DYNAMIC_RIVALRIES_SYSTEM_H
#define DYNAMIC_RIVALRIES_SYSTEM_H

#include <string>
#include <vector>
#include <map>

class Team;
class Game;
class Player;

// Class definition for Game
class Game {
private:
    int gameID;
    std::string date;
    std::vector<Team*> teams;
    std::map<Team*, int> score;
    std::string outcome;

public:
    Game(int id, const std::string& date, const std::vector<Team*>& teams);
    std::string calculateOutcome();
    void updateRivalryMeter();
};

// Class definition for Team
class Team {
private:
    int teamID;
    std::string name;
    std::vector<Player*> players;
    int rivalryScore;

public:
    Team(int id, const std::string& name);
    void addRivalryScore(int score);
    std::vector<Game*> viewRivalryHistory() const;
};

// Class definition for Player
class Player {
private:
    int playerID;
    std::string name;
    std::string position;
    std::map<std::string, int> stats;

public:
    Player(int id, const std::string& name, const std::string& position);
    void addPerformance(const std::map<std::string, int>& performance);
    std::map<std::string, int> getPlayerStats() const;
};

// Class definition for RivalryMeter
class RivalryMeter {
private:
    int meterID;
    Team* team1;
    Team* team2;
    int score;
    std::string status;

public:
    RivalryMeter(int id, Team* t1, Team* t2);
    void incrementScore(int points);
    void resetScore();
    std::string checkRivalryStatus() const;
};

// Class definition for RivalryHistory
class RivalryHistory {
private:
    int historyID;
    Team* team1;
    Team* team2;
    std::vector<Game*> games;

public:
    RivalryHistory(int id, Team* t1, Team* t2);
    void addGameRecord(Game* game);
    std::vector<Game*> getRivalryHistory() const;
};

// Class definition for Leaderboard
class Leaderboard {
private:
    std::vector<Team*> teams;
    std::map<Team*, int> rankings;

public:
    void updateRankings();
    void displayLeaderboard() const;
};

// Class definition for Season
class Season {
private:
    int seasonID;
    std::vector<Team*> teams;
    std::vector<Game*> schedule;
    std::vector<RivalryMeter*> rivalries;

public:
    Season(int id);
    void generateSchedule();
    void calculateRivalryImpacts();
};

// Class definition for RewardSystem
class RewardSystem {
private:
    std::map<Team*, int> rewards;
    std::vector<int> milestones;

public:
    void assignReward(Team* team);
    bool checkMilestoneAchieved(Team* team) const;
};

// Class definition for StatsTracker
class StatsTracker {
private:
    std::map<Team*, std::map<std::string, int>> teamStats;
    std::map<Player*, std::map<std::string, int>> playerStats;
    std::map<RivalryMeter*, int> rivalryStats;

public:
    void updateStats(void* entity);
    std::map<std::string, int> getStats(void* entity) const;
};

#endif // DYNAMIC_RIVALRIES_SYSTEM_H

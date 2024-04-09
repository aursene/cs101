#pragma once
#include <string>
#include <vector>

class character
{
public:
  character();
  ~character();
  int rollOneStat();
  void allocateStats();
  void displayStats();
  void rollStats();
  void selectEquip();
  void addEquip(std::string);
  std::string getEquipment();
  void selectClass();
  std::string getClass();
  void calculateStats();
  void getToHit();
  std::string getModifiers();
  int rollCheck(int);
  int rollToHit();
  void takeDamage(int);
  void finalStats();
  std::vector<int> modifiers{1, 1, 1, 1, 1, 1};


  std::vector<std::string> equipment{};

  int encountersSeen{0};


private:
  std::string name{"Nameless"};
  std::string chClass{"Commoner"};
  int maxHp{5};
  int hp{5};
  int ac{10};
  int toHit{0};

  std::vector<int> statSpread{};

  // order for stats goes Strength, Dexterity, Consitution, Intelligence, Wisdom, Charisma
  std::vector<int> stats{20, 20, 20, 20, 20, 20};
};

#pragma once
#include <string>
#include <vector>

class character
{
public:
  character();
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
  std::string getModifiers();
  int rollCheck(int);
  std::vector<int> modifiers{1, 1, 1, 1, 1, 1};

private:
  std::string chClass{"Commoner"};
  int maxHp{5};
  int hp{5};
  int ac{10};

  std::vector<std::string> equipment{};
  std::vector<int> statSpread{};

  // order for stats goes Strength, Dexterity, Consitution, Intelligence, Wisdom, Charisma
  std::vector<int> stats{1, 1, 1, 1, 1, 1};
  int str{1};
  int dex{1};
  int con{1};
  int intl{1};
  int wis{1};
  int cha{1};
};

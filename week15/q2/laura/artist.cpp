/*
  Laura Reyes 4/29/2024

  W15 Inheritance & Research

  Q1 Base Class

  creating a base class with 4 attributes with a full constructor

*/


#include "artist.h"
#include <iostream>
#include <string>

using namespace std;

class singer : public Artist
{
public:
  string mostPopularSong{};

  singer(string fname, string lname, int cAge, string cGenre, string cPopularSong)
  {
    Firstname = fname;
    Lastname = lname;
    Age = cAge;
    Genre = cGenre;
    mostPopularSong = cPopularSong;
  }
};

int main()
{
  Artist artistInfo{"Solána Imani", "Rowe", 34, "RnB/Soul"};

  artistInfo.display(); // display default
  cout << endl;

  // modifying the attributes
  artistInfo.Firstname = "Barrington DeVaughn";
  artistInfo.Lastname = " Hendricks";
  artistInfo.Age = 34;
  artistInfo.Genre = "experimental hip-hop";

  artistInfo.display(); // displaying modifactions
  cout << endl;

  // modifying them again
  artistInfo.Firstname = "Louis Kevin ";
  artistInfo.Lastname = "Celestin";
  artistInfo.Age = 31;
  artistInfo.Genre = "house/R&B";

  artistInfo.display(); // displaying modifications one last time
  cout << endl;

  cout << endl;
  singer dominic{"Dominic", "Fike", 28, "alternative/indie", "3 Nights"};

  cout << "Here's the derived class!";
  dominic.display();
  cout << endl;

  return 0;
}

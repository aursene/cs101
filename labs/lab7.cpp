/*
 Writen by Braxton Beckman on 2/15/23
 Week 4 Lab: Tic Tac Toe (Playable)
 Using functions and cin>> to display and input to a TTT board
 */


#include <cmath> //allows basic math operations
#include <fstream>
#include <iomanip>  //interpret setw()
#include <iostream> //interpret cout<<

using namespace std;

void title();              // declares function title()
string display(char[]);    // declares function display()
void choose(char[], char); // prompts the player for a choice, then updates the board with that choice
string getWinTime();
string logWin(char[]);
bool win(char[]);

bool replay{true};

// this will only flop between 0 and 1, indicating whether someone has won or not
int winStatus{0};

// this sets the charracter array that we will edit to place the Xs and Os

// initiates main function
int main()
{
  title();
  while (replay)
  {
    char box[9]{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    {
      int counter{};
      while (!win(box))
      {
        cout << display(box) << endl;
        if (counter % 2 == 0)
        {
          choose(box, 'X');
        }
        else
        {
          choose(box, 'O');
        }
        counter++;
        cout << "\033c";
      }
      ofstream writeWin;
      writeWin.open("./winlog.txt", ios::app);
      writeWin << getWinTime() << "\n//////////////////////////////\n"
               << logWin(box) << endl
               << display(box) << endl
               << endl;
      writeWin.close();
    }
    cout << display(box) << endl;

    char tmp{};
    cout << "\nWould you like to play again (Y to continue)? ";
    cin >> tmp;
    (tolower(tmp) == 'y') ? (replay = true) : (replay = false);
  }

  ifstream TTTResults;
  TTTResults.open("./winlog.txt", ios::in);
  cout << "\033c"
       << "Let's take a look at the results!\n";
  string buffer;
  while (!TTTResults.eof())
  {
    TTTResults >> buffer;
    cout << buffer << endl;
  }
  return 0; // ends program
}


void title()
{
  // displays title information
  cout << "Written by Braxton Beckman on 4/11/24\nWeek 4 Lab Tic-Tac-To Project\nMade using functions and arrays to "
          "allow the selection of squares and the ability to check for a win\n\n";
}


string display(char boxD[])
{
  string display{};
  cout << "\n";
  // Displays TTT Board

  display += "  ";
  display += boxD[0];
  display += "  |  ";
  display += boxD[1];
  display += "  |  ";
  display += boxD[2];
  display += "\n ---------------";
  display += "\n  ";
  display += boxD[3];
  display += "  |  ";
  display += boxD[4];
  display += "  |  ";
  display += boxD[5];
  display += "\n ---------------";
  display += "\n  ";
  display += boxD[6];
  display += "  |  ";
  display += boxD[7];
  display += "  |  ";
  display += boxD[8];

  return display;
}

/*void chooseX()
{
  int selection{}; // stores the users choice of box they'd like ot play

start:
  cout << "\n(X) Please select which square you'd like to play: ";
  cin >> selection;

  // checks it the box selected has already been played, and will prompt again until a fresh box is chosen
  if (box[selection - 1] == 'X' || box[selection - 1] == 'O')
  {
    cout << "Please select another square" << endl;
    goto start;
  }
  else
    box[selection - 1] = 'X';
}*/

void choose(char boxC[], char symbol)
{
  int selection{};

  while (true)
  {
    cout << "\n(" << symbol << ") Please select which square you'd like to play: ";
    cin >> selection;

    if (boxC[selection - 1] == 'X' || boxC[selection - 1] == 'O')
    {
      cout << "Please select another square" << endl;
      continue;
    }
    else
    {
      boxC[selection - 1] = symbol;
      break;
    }
  }
}

// A brute force approach to checking the win status, it checks for any rows, columns or diagonals that contain three of
// the same char
bool win(char box[])
{
  if ((box[0] == box[1]) && (box[0] == box[2]))
  {
    // winStatus = 1;
    if (box[0] == 'O')
      cout << "O has won! (Row 1)" << endl;
    else
      cout << "X has won! (Row 1)" << endl;
    return true;
  }
  else if ((box[3] == box[4]) && (box[3] == box[5]))
  {
    // winStatus = 1;
    if (box[3] == 'O')
      cout << "O has won! (Row 2)" << endl;
    else
      cout << "X has won! (Row 2)" << endl;
    return true;
  }
  else if ((box[6] == box[7]) && (box[6] == box[8]))
  {
    // winStatus = 1;
    if (box[6] == 'O')
      cout << "O has won! (Row 3)" << endl;
    else
      cout << "X has won! (Row 3)" << endl;
    return true;
  }
  else if ((box[0] == box[3]) && (box[0] == box[6]))
  {
    // winStatus = 1;
    if (box[0] == 'O')
      cout << "O has won! (Column 1)" << endl;
    else
      cout << "X has won! (Column 1)" << endl;
    return true;
  }
  else if ((box[1] == box[4]) && (box[0] == box[7]))
  {
    // winStatus = 1;
    if (box[1] == 'O')
      cout << "O has won! (Column 2)" << endl;
    else
      cout << "X has won! (Column 2)" << endl;
    return true;
  }
  else if ((box[2] == box[5]) && (box[2] == box[8]))
  {
    // winStatus = 1;
    if (box[2] == 'O')
      cout << "O has won! (Column 3)" << endl;
    else
      cout << "X has won! (Column 3)" << endl;
    return true;
  }
  else if ((box[0] == box[4]) && (box[0] == box[8]))
  {
    // winStatus = 1;
    if (box[0] == 'O')
      cout << "O has won! (Left-to-right Diagonal)" << endl;
    else
      cout << "X has won! (Left-to-right Diagonal)" << endl;
    return true;
  }
  else if ((box[2] == box[4]) && (box[2] == box[6]))
  {
    // winStatus = 1;
    if (box[2] == 'O')
      cout << "O has won! (Right-to-left Diagonal)" << endl;
    else
      cout << "X has won! (Right-to-left Diagonal)" << endl;
    return true;
  }
  else
  {
    return false;
  }
}


string logWin(char box[])
{
  if ((box[0] == box[1]) && (box[0] == box[2]))
  {
    if (box[0] == 'O')
      return "O has won! (Row 1)";
    else
      return "X has won! (Row 1)";
  }
  else if ((box[3] == box[4]) && (box[3] == box[5]))
  {
    if (box[3] == 'O')
      return "O has won! (Row 2)";
    else
      return "X has won! (Row 2)";
  }
  else if ((box[6] == box[7]) && (box[6] == box[8]))
  {
    if (box[6] == 'O')
      return "O has won! (Row 3)";
    else
      return "X has won! (Row 3)";
  }
  else if ((box[0] == box[3]) && (box[0] == box[6]))
  {
    if (box[0] == 'O')
      return "O has won! (Column 1)";
    else
      return "X has won! (Column 1)";
  }
  else if ((box[1] == box[4]) && (box[0] == box[7]))
  {
    if (box[1] == 'O')
      return "O has won! (Column 2)";
    else
      return "X has won! (Column 2)";
  }
  else if ((box[2] == box[5]) && (box[2] == box[8]))
  {
    if (box[2] == 'O')
      return "O has won! (Column 3)";
    else
      return "X has won! (Column 3)";
  }
  else if ((box[0] == box[4]) && (box[0] == box[8]))
  {
    if (box[0] == 'O')
      return "O has won! (Left-to-right Diagonal)";
    else
      return "X has won! (Left-to-right Diagonal)";
  }
  else if ((box[2] == box[4]) && (box[2] == box[6]))
  {
    if (box[2] == 'O')
      return "O has won! (Right-to-left Diagonal)";
    else
      return "X has won! (Right-to-left Diagonal)";
  }
  else
    return "Error - why is the win function being called?";
}

string getWinTime()
{
  char buffer[80];

  time_t currentTime{time(0)};
  struct tm *timeinfo = localtime(&currentTime);

  strftime(buffer, sizeof(buffer), "%B %d, %Y; %H:%M:%S", timeinfo);

  return buffer;
}

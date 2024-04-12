/*
 Writen by Braxton Beckman on 2/15/23
 Week 4 Lab: Tic Tac Toe (Playable)
 Using functions and cin>> to display and input to a TTT board
 */


#include <cmath>    //allows basic math operations
#include <iomanip>  //interpret setw()
#include <iostream> //interpret cout<<

using namespace std;

void title();             // declares function title()
void display(char box[]); // declares function display()
void choose(char);        // prompts the player for a choice, then updates the board with that choice
void chooseX();
bool win();

bool replay;

// this will only flop between 0 and 1, indicating whether someone has won or not
int winStatus{0};

// this sets the charracter array that we will edit to place the Xs and Os
char box[9]{'1', '2', '3', '4', '5', '6', '7', '8', '9'};

// initiates main function
int main()
{
  while (replay)
  {
    title();
    {
      int counter{};
      while (!win())
      {
        display(box);
        if (counter % 2 == 0)
        {
          choose('X');
        }
        else
        {
          choose('O');
        }
        counter++;
      }
    }
    display(box);
  }
  return 0; // ends program
}


void title()
{
  // displays title information
  cout << "Written by Braxton Beckman on 4/11/24\nWeek 4 Lab Tic-Tac-To Project\nMade using functions and arrays to "
          "allow the selection of squares and the ability to check for a win\n\n";
}


void display(char box[])
{
  cout << "\n";
  // Displays TTT Board
  cout << setw(5) << box[0] << setw(3) << "|" << setw(3) << box[1] << setw(3) << "|" << setw(3) << box[2] << endl;
  cout << setw(3) << " "
       << "----|-----|-----\n";
  cout << setw(5) << box[3] << setw(3) << "|" << setw(3) << box[4] << setw(3) << "|" << setw(3) << box[5] << endl;
  cout << setw(3) << " "
       << "----|-----|-----\n";
  cout << setw(5) << box[6] << setw(3) << "|" << setw(3) << box[7] << setw(3) << "|" << setw(3) << box[8] << endl
       << endl;
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

// identical to chooseX(), but for the player playing Os
void choose(char symbol)
{
  int selection{};

  while (true)
  {
    cout << "\n(O) Please select which square you'd like to play: ";
    cin >> selection;

    if (box[selection - 1] == 'X' || box[selection - 1] == 'O')
    {
      cout << "Please select another square" << endl;
      continue;
    }
    else
    {
      box[selection - 1] = symbol;
      break;
    }
  }
}

// A brute force approach to checking the win status, it checks for any rows, columns or diagonals that contain three of
// the same char
bool win()
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

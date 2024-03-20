#include "w10.h" // loads all of the functions we have defined here so we can use them

// honestly the coolest main function i've written yet, the entire file is only ~11 locs (including the comments)
// and no headers! or any need for namespace! this feels like quite a bit of a milestone and it's cool to see
int main()
{
  person Mary; // the declaration of an object from our brand spanking new class, "person". "Mary" now contains a
               // position in space (two integers), and the ability to call the constructor function (which it does on
               // creation) and the display function

  Mary.display(); // the afformentioned display function, it will display the two integers Mary has (which is currently
                  // a position on a plane)

  return 0; // it felt too small without it
}

#include <iostream>

#include "2dScenery.h"
#include "3dcube.h"

using namespace std;


int main(int argc, char** argv)
{
  bool bExitRequested = false;

  do
  {
    cout << "What to do?" << endl;
    cout << "  1 ... Static 2D scenery (16.12.2004) (course 4)" << endl;
    cout << "  2 ... Rotatable 3D RGB cube (31.01.2005) (course 5)" << endl;
    cout << "  q ... QUIT" << endl;
    cout << "> ";

    char cInput = 0;
    cin >> cInput;

    switch (cInput)
    {
      case '1':
      {
        run2dScenery(argc, argv);
        cout << endl << endl;
        break;
      }

      case '2':
        run3dCube(argc, argv);
        cout << endl << endl;
        break;

      case 'q':
        bExitRequested = true;
        break;
      }
  } 
  while (bExitRequested == false);

  return 0;
}

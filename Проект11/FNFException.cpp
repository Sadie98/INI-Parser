#include "FNFException.h"
#include <iostream>

using namespace std;

FileNotFoundException::FileNotFoundException(string message)
{
	cout << message << endl;

}

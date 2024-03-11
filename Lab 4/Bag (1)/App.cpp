#include "Bag.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
	testAll();
	cout << "Short tests over" << endl;
	testAllExtended();
	cout << "All test over" << endl;
}
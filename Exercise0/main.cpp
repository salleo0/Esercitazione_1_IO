#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>
#include <numbers>
#include <sstream>
using namespace std;

int main()
{
	int a = -1;
	unsigned int b = 2;
	bool c = true;		/*false*/
	double d = 3.4f;	/* con 'f' gli dico che è un float */
	string str = "Hello";
	char e = 'A';
	
	cout << sizeof(int) << endl;
	cout << pow(2,-31) << " " << pow(2,31)-1 << endl;
	cout << numeric_limits<int>::min() << " " << numeric_limits<int>::max() << endl;	/* numeric_limits dato il tipo mi restituisce il minimo o 
																						il massimo, in base a cosa chiedo, del tipo di oggetto che
																						chiedo tra parentesi tonde */
	cout << setprecision(16) << scientific;		/* stampa con 16 cifre significative */
	cout << numbers::pi << endl;
	
	int a1 = a+3;
	int a2 = a+d;	/* trasforma a in double, fa l'operazione e poi trasforma il risultato in int */
	string s1 = str + to_string(d);
	cout << "a1 = " << a1 << endl;
	cout << "a2 = " << a2 << endl;
	cout << "s1 = " << s1 << endl;	
	
    return 0;
}

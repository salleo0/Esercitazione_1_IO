#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	int num;
	int sum_of_squares = 0;
	cout << "How many numbers do you want to read from the file? ";
	cin >> num;
	string filename = "data.txt";
	ifstream ifs(filename);
	
	if (!ifs.is_open()){
		cerr << "Error: could not open the file\n";
		return 1;
	}
	
	string line;
	getline(ifs, line); /* discard header line */
	int num_in_line;
	int i = 1;
	while (!ifs.eof() && i<=num) {
		ifs >> num_in_line;
		sum_of_squares += num_in_line*num_in_line;
		i++;
	}
	cout << "Sum of the first " << num << " numbers squared: " << sum_of_squares << endl;
	
    return 0;
}

#include <iostream>
#include <fstream>
#include <sstream>
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
		cout << "Error: could not open the file\n";
		return 1;
	}
	
	string line;
	getline(filename, line); 		/* discard header line */
	int num_in_line;
	
	for (int i = 1; i<=num; i++){
		getline(filename, line);
		if (line != "\n") {
			getline(filename, num_in_line);
			sum_of_squares += num_in_line*num_in_line;
	}
	
	cout << "Sum of the first " << num << "numbers squared: " << sum_of_squares;
	
    return 0;
}

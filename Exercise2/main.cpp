#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;

int countlines_infile(string filename) {
	ifstream ifs(filename);
	if (ifs.fail()) {
		cerr << "Unable to open file" << endl;
		return 1;
	}
	
	int num_lines = 0;
	string line;
	while (getline(ifs,line)){
		++num_lines;
	}
	
	return num_lines;
}

int main() {
	string ifilename = "data.txt";
	ifstream ifs(ifilename);
	if (ifs.fail()) {
		cerr << "Unable to open file" << endl;
		return 1;
	}
	
	int num_lines = countlines_infile(ifilename);
	cout << num_lines << endl;
	
    return 0;
}

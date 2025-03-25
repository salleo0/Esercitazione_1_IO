#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

/* 	define a function that maps a point in the iinterval [input_start, input_end] 
	to a point in the interval [output_start, output_end] */
	
void changing_interval(const float input_start, const float input_end, const float output_start, const float output_end, float& n) {
	double slope = 1.0 * (output_end - output_start) / (input_end - input_start);
	n = output_start + 1.0 * slope * (n - input_start);
}

int main() {
	
	/* input file */
	string ifilename = "data.txt";
	ifstream ifs(ifilename);
	if (ifs.fail()) {
		cerr << "Unable to open file" << endl;
		return 1;
	}
	
	/* output file */
	string ofilename = "results.txt";
	ofstream ofs(ofilename);
	if ( ofs.fail() ) {
		cerr << "Unable to open file" << endl;
		return 1;
	}
	
	float number;
	float sum = 0;
	float mean;
	int i = 1;
	
	ofs << "# N mean" << endl;
	
	while (ifs >> number) {
		changing_interval(1,5,-1,2,number);
		sum += number;
		mean = 1.0*sum/i;
		ofs << scientific << setprecision(16) << mean << endl;
		i++;
	}

    return 0;
}

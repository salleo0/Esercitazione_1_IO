#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

void changing_interval(const float input_start, const float input_end, const float output_start, const float output_end, float& n) {
	double slope = 1.0 * (output_end - output_start) / (input_end - input_start);
	n = output_start + slope * (n - input_start);
}

int main() {
	string ifilename = "data.txt";
	ifstream ifs(ifilename);
	if (ifs.fail()) {
		cerr << "Unable to open file" << endl;
		return 1;
	}
	
	/* count how many lines in data.txt */
	int num_lines = 0;
	string line;
	while (getline(ifs,line)){
		++num_lines;
	}

	/* vector with data from data.txt */
	vector<float> numbers(num_lines);
	ifs.clear();
	ifs.seekg(0, ios::beg);
	for (int i = 0; i < num_lines; i++){
		ifs >> numbers[i];
		changing_interval(1,5,-1,2,numbers[i]);
	}
	
	/* calculate the mean values */
	vector<float> mean(num_lines);
	for (int i = 0; i < num_lines; i++){
		float sum = 0;
		for (int j = 0; j <= i; j++) {
			sum += numbers[j];
		}
		mean[i] = 1.0*sum/(i+1);
	}
	
	/* printing the results in an output file */
	string ofilename = "results.txt";
	ofstream ofs(ofilename);
	
	if ( ofs.fail() ) {
		cerr << "Unable to open file" << endl;
		return 1;
	}
	ofs << "# " << num_lines << " mean" << endl;
	for (int i = 0; i <= num_lines; ++i){
		ofs << scientific << setprecision(16) << mean[i] << endl;
	}

    return 0;
}

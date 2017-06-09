#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

std::vector<std::string> split(std::string str, std::string pattern)
{
	std::string::size_type pos;
	std::vector<std::string> result;
	str += pattern;
	int size = str.size();

	for (int i = 0; i<size; i++)
	{
		pos = str.find(pattern, i);
		if (pos<size)
		{
			std::string s = str.substr(i, pos - i);
			result.push_back(s);
			i = pos + pattern.size() - 1;
		}
	}
	return result;
}

using Sample = std::vector<double>;

std::vector<Sample> read_sv(const char* filename,std::string delimeter) {
	std::ifstream fin(filename);
	if (!fin.is_open()) {
		std::cerr << "Error: Cannot open file " << filename << std::endl;
		exit(-1);
	}
	int num_samples, dim;

    // File header
	fin >> num_samples >> dim;

    // Data entry begins
	std::string line;
	std::vector<Sample> dataset;
	while (std::getline(fin, line)) {
		std::vector<std::string> tokens = split(line, delimeter);
		Sample sample(dim);
		std::transform(tokens.begin(), tokens.end(), sample.begin(), [](std::string str) {return atof(str.c_str()); });
		dataset.push_back(sample);
	}
	fin.close();
	return dataset;
}
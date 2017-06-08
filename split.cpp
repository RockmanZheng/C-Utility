#include <vector>
#include <string>

//×Ö·û´®·Ö¸îº¯Êý
std::vector<std::string> split(std::string str, std::string delimeter)
{
	std::string::size_type pos;
	std::vector<std::string> result;
	str += delimeter;//À©Õ¹×Ö·û´®ÒÔ·½±ã²Ù×÷
	int size = str.size();

	for (int i = 0; i<size; i++)
	{
		pos = str.find(delimeter, i);
		if (pos<size)
		{
			std::string s = str.substr(i, pos - i);
			result.push_back(s);
			i = pos + delimeter.size() - 1;
		}
	}
	return result;
}
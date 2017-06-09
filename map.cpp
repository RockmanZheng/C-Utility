#include <string>
#include <algorithm>
#include <stdlib.h>
// Use std::transform

std::vector<int> list(10);
std::vector<std::string> result(list.size());



std::transform(list.begin(),list,end(),result.begin(),std::string);
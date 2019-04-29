#include <algorithm>
#include <sstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>


using std::vector;
using std::string;


static bool compare_strings(std::string const& a, std::string const& b)
{
	auto it_a = std::begin(a);
	auto it_b = std::begin(b);
	for(;it_b != std::end(b); ++it_a,++it_b){
		if(*it_a > *it_b)
		 	return true;
		else if (*it_a < *it_b)
		 	return false;
	}
	return *it_a > *(--it_b);
}


/*
int myCompare(string X, string Y) 
{ 
//	first append Y at the end of X 
		string XY = X.append(Y); 

	// then append X at the end of Y 
	string YX = Y.append(X); 

	// Now see which of the two formed numbers is greater 
	return XY.compare(YX) > 0 ? 1: 0; 
} 

*/
string largest_number(vector<string> a) {
  //write your code here
	std::sort(std::begin(a),std::end(a), [&](std::string const& a, std::string const& b ){
			if(a.size()==b.size())
		 		return a > b;
			else if(a.size() > b.size())
				return compare_strings(a,b);
			
			return !compare_strings(b,a);
			});

//	std::sort(std::begin(a),std::end(a),myCompare);
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}

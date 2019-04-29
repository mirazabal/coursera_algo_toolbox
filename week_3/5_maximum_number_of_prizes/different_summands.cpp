#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;

	uint64_t i = 1;
	while(n > 2*i){
		summands.emplace_back(i);
		n = n - i;
		++i;	
	}
	summands.emplace_back(n);
	//write your code here
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}

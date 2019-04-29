#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

template<typename ForwardIt, typename T>
ForwardIt mib_lower_bound(ForwardIt first, ForwardIt last, T val)
{
	auto count = std::distance(first,last);
  decltype(count) steps;
	ForwardIt it;
	while(count>0){
		steps = count/2;
		it = first;
		std::advance(it,steps);
		if(*it < val){
			first = std::next(it);	
			count = count - (steps + 1);
		}else{
			count = steps;
		}	
	}
	return first;
}

int binary_search(const vector<int> &a, int x) {
//  int left = 0, right = (int)a.size(); 
	auto it = mib_lower_bound(std::begin(a), std::end(a),x);
	if(it == std::end(a))
	 	return -1;

	return *it == x ? std::distance(std::begin(a),it) : -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    //std::cout << linear_search(a, b[i]) << ' ';
    std::cout << binary_search(a, b[i]) << ' ';
  }
	return 0;
}

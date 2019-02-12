#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

struct Objects
{
	int values;
	int weigths;
	Objects(int val = 0, int wei = 0) : values{val}, weigths{wei}
	{
	
	}
};

double get_optimal_value(int capacity, vector<Objects>& obj) {

  double value = 0.0;

	std::sort(std::begin(obj), std::end(obj), [](auto const& a, auto const &b )
			{
				return double(a.values)/double(a.weigths) > double(b.values)/double(b.weigths); 
			});
	
	auto it = std::begin(obj);
	while(capacity != 0 && it != std::end(obj)){
		if(it->weigths <= capacity){
			value += it->values;
			capacity -= it->weigths;
		} else {
			value += capacity * (double(it->values)/double (it->weigths));	
			capacity = 0;	
		}
		it = std::next(it);
	}

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
	vector<Objects> obj(n);
  for (int i = 0; i < n; i++) {
		int val, weig;
    std::cin >> val >> weig;
		obj.emplace_back(Objects(val,weig));
  }

  double optimal_value = get_optimal_value( capacity, obj);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}

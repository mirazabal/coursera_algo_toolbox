#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

template<typename T>
std::pair<T,T> findTwoBiggest(std::vector<T> const& vec)
{
	T first = vec[0];
	T second = vec[1];
	if(second > first) 
		std::swap(first,second);

	for(auto it = std::begin(vec) + 2; it != std::end(vec); ++it){
		if(*it > first){
			std::swap(first,second);
			first = *it;
		} else if(*it > second){
			second = *it;
		}
	}
	return std::make_pair(first,second);
}

int64_t MaxPairwiseProduct(std::vector<int64_t> const& vec)
{
	auto pair =  findTwoBiggest(vec);
	return pair.first * pair.second;
}

int main()
{
	int64_t n{0};
  std::cin >> n;
	std::vector<int64_t> numbers(n);
	for (int i = 0; i < n; ++i) {
	 std::cin >> numbers[i];
	}

	int64_t result = MaxPairwiseProduct(numbers);
  std::cout << result << "\n";
  return 0;
}

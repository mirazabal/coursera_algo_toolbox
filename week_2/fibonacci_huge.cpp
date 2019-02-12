#include <iostream>
#include <vector>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

uint32_t pisano(uint32_t mod)
{
	uint32_t result{1};
	uint32_t prev{1};
	uint32_t curr{1};
	while(prev != 0 || curr != 1){
		uint32_t temp = (prev + curr) % mod;
		prev = curr;
		curr = temp;
		result += 1;
	}

	return result;
}

int fibonacci_fast_mod(int n, uint32_t mod) {
    // write your code here

		if(n <= 1)
			return n;
		
		std::vector<int> arrVal(n+1);
		arrVal[0] = 0;
		arrVal[1] = 1;

		for(uint64_t i = 2; i < n+1; ++i){
			arrVal[i] = (arrVal[i-1] + arrVal[i-2]) % mod;
		}
		return arrVal[n];
}



long long get_fibonacci_last(uint64_t n, uint64_t m)
{
	auto period = pisano(m);
//	std::cout << period << '\n';
	return (fibonacci_fast_mod( n % period, m ))%m;	
}


int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_last(n, m) << '\n';
}

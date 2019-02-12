#include <iostream>
#include <vector>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int fibonacci_fast_last_digit(int n) {
    // write your code here

		if(n <= 1)
			return n;
		
		std::vector<int> arrVal(n+1);
		arrVal[0] = 0;
		arrVal[1] = 1;

		for(uint64_t i = 2; i < n+1; ++i){
			arrVal[i] = (arrVal[i-1] + arrVal[i-2])%10;
		}
		return arrVal[n];
}

int main() {
    int n;
    std::cin >> n;
    int c = fibonacci_fast_last_digit(n);
    std::cout << c << '\n';
    }

#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n) 
{
	if (n <= 1)
		return n;

	n = (n+2)%60;
	int fib[n+1];
	
	fib[0]=0;
	fib[1]=1;
	
	for(int i = 2; i<=n;i++){
		fib[i] = (fib[i-1] + fib[i-2])%10;
	}
	if(fib[n] == 0){
		return 9;
	}
	return (fib[n]%10-1);
}


long long get_fibonacci_partial_sum(long long from, long long to) {

	auto first = fibonacci_sum_fast(from);
	auto second = fibonacci_sum_fast(to);
//	std::cout << "first = " << first;
//	std::cout << "second = " << second;

	return second > first ? second - first : second + 10 - first;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}

#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

/*
int fibonacci_sum_fast(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
				current = current % 10;
        sum += current;
//				sum= sum % 10;
    }
		return sum % 10;

    //return sum % 10;
}
*/

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


int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
//    std::cout << fibonacci_sum_naive(n);
}

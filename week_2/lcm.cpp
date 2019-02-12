#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}



int64_t gcd_fast(int64_t a, int64_t b)
{
	if(b == 0)
	 	return a;
	return gcd_fast(b,a%b);
}

int64_t lcm_fast(int64_t a, int64_t b)
{
	auto gcd_func = [](int64_t a, int64_t b) -> int64_t {
		if(a > b)
			return gcd_fast(a,b);

		return gcd_fast(b,a);
		};
	
	return (a/gcd_func(a,b) ) * b;
}


int main() {
  int a, b;
  std::cin >> a >> b;
//  std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;
	
  return 0;
}

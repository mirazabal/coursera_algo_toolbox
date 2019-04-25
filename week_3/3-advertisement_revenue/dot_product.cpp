#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<long long> a, vector<long long> b)
{
  // write your code here
  std::sort(std::begin(a),std::end(a),std::greater<long long>());
  std::sort(std::begin(b),std::end(b),std::greater<long long>());

  std::transform(std::begin(a), std::end(a), std::begin(b), std::begin(a), std::multiplies<long long>());
  return std::accumulate(std::begin(a),std::end(a),0l);
}

int main() {
  size_t n;
  std::cin >> n;
  vector<long long> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}

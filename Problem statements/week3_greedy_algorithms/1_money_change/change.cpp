#include <iostream>


template<typename T>
T get_change_temp(T&& val)
{
	

};


int get_change(int m) {
	int numberCoins{0};
	while(m >= 10){
		m-=10;
		++numberCoins;
	}
	while(m >= 5){
		m-=5;
		++numberCoins;
	}
	while(m >= 1){
		m-=1;
		++numberCoins;
	}
	return numberCoins;
  //write your code here
//  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

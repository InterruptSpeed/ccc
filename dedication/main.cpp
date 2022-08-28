#include <algorithm>
#include <iostream>
#include <string>

int main() {
  auto i{ 0x01B99644 };				// index of the dedication permutation 
  std::string x{ " DFaeeillnor" };		// a permutation of the dedication
  while (i--) {					// loop until arriving at the index
    std::next_permutation(x.begin(), x.end());  // generate the next permutation
  }
  std::cout << x << std::endl;			// output the dedication "For Danielle"
}

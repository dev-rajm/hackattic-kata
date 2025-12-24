#include <iostream>
#include <string>

int decimal(std::string &s) {
  long long ans = 0;
  for(char ch:s) {
    ans <<= 1;

    if(ch == '#') {
      ans |= 1;
    }
  }
  return ans;
}

int main(int argc, char* argv[]) {
  std::string input;
  
  while(std::getline(std::cin, input)) {
    std::cout << decimal(input) << "\n";
  }

  return 0;
}

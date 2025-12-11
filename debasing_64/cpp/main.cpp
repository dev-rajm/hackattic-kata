#include <iostream>
#include <string>

std::string toText(const std::string base64) {
  int n = base64.size();
  std::string utf8 = "";

  int i, j, k = 0;
  int num = 0;
  int count_bits = 0;

  for(i=0; i<n; i+=4) {
    num=0, count_bits=0;
    for(j=0; j<4; j++) {
      if(base64[i+j] != '=') {
        num = num << 6;
        count_bits += 6;
      }

      if(base64[i+j] >= 'A' && base64[i+j] <= 'Z') {
        num |= base64[i+j] - 'A';
      }
      else if(base64[i+j] >= 'a' && base64[i+j] <= 'z') {
        num |= base64[i+j] - 'a' + 26;
      }
      else if(base64[i+j] >= '0' && base64[i+j] <= '9') {
        num |= base64[i+j] - '0' + 52;
      }
      else if(base64[i+j] == '+') {
        num |= 62;
      } 
      else if(base64[i+j] == '/') {
        num |= 63;
      }
      else {
        num = num >> 2;
        count_bits -= 2;
      }

      while(count_bits != 0) {
        count_bits -= 8;
        utf8.push_back((num >> count_bits) & 255);
      }
    }
  }

  return utf8;
}

int main(int argc, char *argv[]) {
  std::string input;

  while (std::getline(std::cin, input)) {
    std::cout << toText(input) << "\n";
  }

  return 0;
}

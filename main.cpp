#include <iostream>

int main(int argc, const char* argv[]){
  if(argc!=2){
    std::cout << "One input parameter expected." << std::endl;
  }
  std::cout << argv[1] << std::endl;
  return 0;
}



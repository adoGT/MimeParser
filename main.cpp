#include <iostream>
#include <fstream>
#include <exception>
#include "parserCore/parser.h"
#include "parserCore/parserException.h"

int main(int argc, const char* argv[]){
  if(argc==2) {
    std::cout << argv[1] << std::endl;
  }
  MimeParser parser;
  try{
    std::ifstream myfile("in.txt");
    if (myfile.is_open())
    {
      parser.parseInput(myfile);
      myfile.close();
    }

    parser.printTree(std::cout);
  }
  catch (ParserException& e) {
    std::cout << e.what() << std::endl;
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}

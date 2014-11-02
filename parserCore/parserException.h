#include <exception>

class ParserException : public std::exception {
public:
  ParserException(){}
  const char* what() const throw() {return "Something is wrong!";}
};

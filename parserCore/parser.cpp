#include "parser.h"
#include "parserException.h"
#include <ostream>
#include <stdexcept>

void MimeParser::parseLine(std::string &line) {
  if(line.length()==0)
    return;
  throw new ParserException();
}

void MimeParser::printTree(std::ostream &stream) {
  if(!stream.good())
    throw new std::invalid_argument("MimeParser::printTree passed stream has error state bit set!");
  throw new ParserException();
}

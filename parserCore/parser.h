#include <string>
#include "mimeTree.h"

class MimeParser {
    MimeTree mimeTree;

  public:
    void parseLine(std::string &line);

    void printTree(std::ostream &stream);
};

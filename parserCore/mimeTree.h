#include <list>

class MimeTree {
  std::list<MimeTree> tree;
  bool node;
  
public:
  MimeTree();
  MimeTree(bool isNode);

  bool isNode();
  void addNode();
};

#include "mimeTree.h"
#include "parserException.h"

MimeTree::MimeTree() {
  m_parent = NULL;
}

MimeTree::MimeTree(std::string content, std::string type) {
  m_parent = NULL;
  setContent(content);
  setType(type);
}

MimeTree::MimeTree(MimeTree *parent, std::string content, std::string type) {
  setParent(parent);
  setContent(content);
  setType(type);
}

MimeTree::~MimeTree() {
  for(int i=0; i<numberOfNodes(); ++i)
    delete getChildAt(i);
}

MimeTree* MimeTree::addChild() {
  MimeTree *newNode = new MimeTree();
  newNode->setParent(this);
  addChild(newNode);
  return newNode;
}

MimeTree* MimeTree::addChild(std::string content, std::string type) {
  MimeTree *newNode = new MimeTree(this, content, type);
  addChild(newNode);
  return newNode;
}

void MimeTree::addChild(MimeTree *node) {
  m_tree.push_back(node);
}

MimeTree* MimeTree::getChildAt(int i) {
  if(i<0 || i>numberOfNodes()-1)
    throw ParserException("Node index out of bounds!");
  return m_tree[i];
}

void MimeTree::printTree(std::ostream &stream) {
  printTree(stream, 0);
}

void MimeTree::printTree(std::ostream &stream, int depth) {
  printPadding(stream, depth);
  stream << m_type << std::endl;
  printPadding(stream, depth);
  stream << m_content << std::endl;
  for(int i=0; i<numberOfNodes(); ++i)
    getChildAt(i)->printTree(stream, depth+1);
}

void MimeTree::printPadding(std::ostream &stream, int depth) {
  for(int i = 0; i < depth; ++i) {
    stream << "  ";
  }
}

void MimeTree::setParent(MimeTree* parent) {
   m_parent = parent;
}

MimeTree* MimeTree::getParent() {
  return m_parent;
}

std::string MimeTree::getContent() {
  return m_content;
}

std::string MimeTree::getType() {
  return m_type;
}

void MimeTree::setContent(std::string content) {
  m_content = content;
}

int MimeTree::numberOfNodes() {
  return m_tree.size();
}

void MimeTree::setType(std::string type) {
  m_type = type;
}

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
  using std::string;

#include <gmock/gmock.h>
  using ::testing::Eq;
#include <gtest/gtest.h>
  using ::testing::Test;

#include "../parserException.h"
#include "../parser.h"

#define THIS_DIR "C:/muni/secureCoding/MimeParser/parserCore/test"

namespace testing
{
    class ParserTest : public Test
    {
    protected:
        ParserTest(){}
        ~ParserTest(){}

        virtual void SetUp(){}
        virtual void TearDown(){}
    };

void testPars(int from, int to)
{
      MimeParser parser;
      for(int i=from; i<=to; ++i) {
        std::ostringstream stringStream;
        stringStream << THIS_DIR << "/good/m" << std::setfill('0') << std::setw(4) << i << ".txt";
        std::string filePath = stringStream.str();
        std::cout << "###############################" << std::endl
          << filePath << std::endl << "###############################" << std::endl;
        std::ifstream myfile(filePath.c_str());
        if(myfile.is_open())
        {
          parser.parseInput(myfile);
          parser.printTree(std::cout);
          myfile.close();
        } else
        {
          std::cout << "Failed to open file:" << filePath << "." << std::endl;
          FAIL();
        }
      }

}

    TEST(good, GoodOne)
    {
      testPars(1,18);
    }

    TEST(good, GoodTwo)
    {
      testPars(1001,1016);
    }

    TEST(good, GoodThree)
    {
      testPars(2001, 2016);
    }
 
    TEST(good, GoodFour)
    {
      testPars(3001, 3004);
    }
}

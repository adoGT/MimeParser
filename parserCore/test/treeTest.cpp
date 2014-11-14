#include <string>
  using std::string;

#include "../mimeTree.h"

#include <gmock/gmock.h>
  using ::testing::Eq;
#include <gtest/gtest.h>
  using ::testing::Test;


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

    TEST(EmptyTreeCreate, TreeTest)
    {
      MimeTree tree; 
      EXPECT_EQ(tree.numberOfNodes(), 0);
    }
   
    TEST(OneNodeTree, TreeTest)
    {
      MimeTree tree(NULL, "One", "Single");
      tree.addChild("Two", "Single");     
      EXPECT_EQ(tree.numberOfNodes(), 1);
      EXPECT_EQ(tree.getChildAt(0)->numberOfNodes(), 0);
      EXPECT_EQ(tree.getChildAt(0)->getParent()->numberOfNodes(), 1);
    }
}

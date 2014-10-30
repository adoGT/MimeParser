#include <string>
  using std::string;

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

    TEST_F(ParserTest, test_framework)
    {
        EXPECT_THAT(0, Eq(size_t(0)));
    }
}

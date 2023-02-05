#include <gtest/gtest.h>
#include <builder.hpp>
namespace BuilderDP
{
    class BuilderFixture : public ::testing::Test
    {
    public:
        BuilderDP::ConcreteBuilder1 *builder;
        ~BuilderFixture() { delete builder; }
    };

    TEST_F(BuilderFixture, GivenSimpleConstruction_CheckForOnePart)
    {

        builder = new BuilderDP::ConcreteBuilder1;
        BuilderDP::Director dir(builder);

        dir.make(BuilderType::simple);

        Product1 *product1 = builder->getResult();

        auto parts = product1->getParts();

        std::vector<std::string> ground_truth{"StepA"};

        for (auto part : ground_truth)
        {

            EXPECT_TRUE(std::find(parts.begin(), parts.end(), part) != parts.end());
        }
    }

    TEST_F(BuilderFixture, GivenComplexConstruction_CheckForMultipleParts)
    {

        builder = new BuilderDP::ConcreteBuilder1;
        BuilderDP::Director dir(builder);

        dir.make(BuilderType::complex);

        Product1 *product1 = builder->getResult();

        auto parts = product1->getParts();

        std::vector<std::string> ground_truth{"StepA", "StepB", "StepC"};

        for (auto part : ground_truth)
        {
            EXPECT_TRUE(std::find(parts.begin(), parts.end(), part) != parts.end());
        }
    }
}
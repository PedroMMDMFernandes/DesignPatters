#include "strategy.hpp"
#include <algorithm>

namespace StrategyDP
{
    Strategy::~Strategy()
    {
    }

    Context::Context(Strategy *strategy)
    {
    }

    Context::~Context()
    {
    }

    void Context::SetStrategy(Strategy *strategy)
    {
        this->strategy = strategy;
    }

    void Context::ExecuteStrategy()
    {
        std::cout << "Operation: " << this->strategy->Execute(std::vector<std::string>{"c", "a", "e", "b", "d"})<<"\n";
    }

    ConcreteStrategyA::ConcreteStrategyA(/* args */)
    {
    }

    ConcreteStrategyA::~ConcreteStrategyA()
    {
    }

    std::string ConcreteStrategyA::Execute(const std::vector<std::string> &data)
    {
        std::string str;

        for (auto dt : data)
        {
            str += dt;
        }

        std::sort(std::begin(str), std::end(str));

        return str;
    }

    ConcreteStrategyB::ConcreteStrategyB(/* args */)
    {
    }

    ConcreteStrategyB::~ConcreteStrategyB()
    {
    }

    std::string ConcreteStrategyB::Execute(const std::vector<std::string> &data)
    {
        std::string str;

        for (auto dt : data)
        {
            str += dt;
        }

        std::sort(std::begin(str), std::end(str));

        for (uint8_t i = 0; i < str.size() / 2; i++)
        {
            /* code */
            std::swap(str[i], str[str.size() - i - 1]);
        }

        return str;
    }

    void Execute()
    {
        Context context;
        ConcreteStrategyA conStrA;
        ConcreteStrategyB conStrB;

        context.SetStrategy(&conStrA);

        context.ExecuteStrategy();

        context.SetStrategy(&conStrB);

        context.ExecuteStrategy();
    }

}

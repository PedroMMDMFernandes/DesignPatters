#ifndef STRATEGY_HPP
#define STRATEGY_HPP

#include <iostream>
#include <vector>

namespace StrategyDP
{
    class Strategy
    {
    private:
        /* data */
    public:
        virtual ~Strategy();
        virtual std::string Execute(const std::vector<std::string> &data) = 0;
    };

    class Context
    {
    private:
        /* data */
        Strategy *strategy;

    public:
        Context(Strategy *strategy = nullptr);
        ~Context();

        void SetStrategy(Strategy *strategy);

        void ExecuteStrategy();
    };

    class ConcreteStrategyA : public Strategy
    {
    private:
        /* data */
    public:
        ConcreteStrategyA(/* args */);
        ~ConcreteStrategyA();

        std::string Execute(const std::vector<std::string> &data) override;
    };


    class ConcreteStrategyB : public Strategy
    {
    private:
        /* data */
    public:
        ConcreteStrategyB(/* args */);
        ~ConcreteStrategyB();

        std::string Execute(const std::vector<std::string> &data) override;
    };

    void Execute();

}

#endif
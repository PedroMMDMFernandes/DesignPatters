#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>
#include <memory>

namespace StateDP
{
    class Context;

    class State
    {
    protected:
        /* data */
        Context *context;

    public:
        State(/* args */);
        virtual ~State();

        void SetContext(Context *context)
        {
            this->context = context;
        }

        virtual void Request1() = 0;
        virtual void Request2() = 0;
    };

    class ConcreteStateA : public State
    {
    private:
    public:
        ConcreteStateA(/* args */);
        ~ConcreteStateA();

        void Request1() override;
        void Request2() override;
    };

    class ConcreteStateB : public State
    {
    private:
        /* data */
    public:
        ConcreteStateB(/* args */);
        ~ConcreteStateB();

        void Request1() override;
        void Request2() override;
    };

    class Context
    {
    private:
        /* data */
        State *state;

    public:
        Context(State &state);
        ~Context();

        void TransitionTo(State* state);

        void Request1();

        void Request2();
    };

    void Execute();

}

#endif
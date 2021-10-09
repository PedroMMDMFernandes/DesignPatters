#include "state.hpp"

namespace StateDP
{

    State::State(/* args */)
    {
    }

    State::~State()
    {
    }

    ConcreteStateA::ConcreteStateA(/* args */)
    {
    }

    ConcreteStateA::~ConcreteStateA()
    {
    }

    void ConcreteStateA::Request1()
    {
        std::cout << "ConcreteStateA request 1\n";
        std::cout << "ConcreteStateA wants to change the state of the context.\n";

        this->context->TransitionTo(new ConcreteStateB);
    }

    void ConcreteStateA::Request2()
    {
        std::cout << "ConcreteStateA request 2\n";
    }

    ConcreteStateB::ConcreteStateB(/* args */)
    {
    }

    ConcreteStateB::~ConcreteStateB()
    {
    }

    void ConcreteStateB::Request1()
    {
        std::cout << "ConcreteStateB request 1\n";
    }

    void ConcreteStateB::Request2()
    {
        std::cout << "ConcreteStateB request 2\n";
        std::cout << "ConcreteStateB wants to change to context's state\n";
        this->context->TransitionTo(new ConcreteStateA);
    }

    Context::Context(State &state)
    :state(nullptr)
    {
        this->TransitionTo(&state);
    }

    Context::~Context()
    {
    }

    void Context::TransitionTo(State *state)
    {
        std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";

        if (this->state != nullptr)
        {
            //delete this->state;
        }

        this->state = state;
        this->state->SetContext(this);
    }

    void Context::Request1()
    {
        state->Request1();
    }

    void Context::Request2()
    {
        state->Request2();
    }

    void Execute()
    {
        ConcreteStateA state;

        Context context(state);

        context.Request1();
        context.Request2();
    }

}
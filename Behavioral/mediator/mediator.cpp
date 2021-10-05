#include "mediator.hpp"

namespace MediatorDP
{
    BaseComponent::BaseComponent(Mediator *mediator)
        : mediator(mediator)
    {
    }

    BaseComponent::~BaseComponent()
    {
    }

    void BaseComponent::SetMediator(Mediator *mediator)
    {
        this->mediator = mediator;
    }

    ComponentA::ComponentA()
    {
    }

    ComponentA::~ComponentA()
    {
    }

    void ComponentA::DoSomething1()
    {
        std::cout << "Component A does 1.\n";
        this->mediator->Notify(this, "1");
    }

    void ComponentA::DoSomething2()
    {
        std::cout << "Component A does 2.\n";
        this->mediator->Notify(this, "2");
    }

    ComponentB::ComponentB()
    {
    }

    ComponentB::~ComponentB()
    {
    }

    void ComponentB::DoSomething3()
    {
        std::cout << "Component B does 3.\n";
        this->mediator->Notify(this, "3");
    }

    void ComponentB::DoSomething4()
    {
        std::cout << "Component B does 4.\n";
        this->mediator->Notify(this, "4");
    }

    ConcreteMediator::ConcreteMediator(ComponentA *cptA, ComponentB *cptB)
        : cptA(cptA), cptB(cptB)
    {
        cptA->SetMediator(this);
        cptB->SetMediator(this);
    }

    ConcreteMediator::~ConcreteMediator()
    {
    }

    void ConcreteMediator::Notify(BaseComponent *baseComp, std::string event) const
    {

        if (event == "1")
        {
            std::cout << "Mediator reacts on 1 and triggers following operations:\n";
            cptB->DoSomething3();
        }
        else if (event == "4")
        {
            std::cout << "Mediator reacts on 4 and triggers following operations:\n";
            cptA->DoSomething2();
            cptB->DoSomething3();
        }
    }

    void Execute()
    {
        ComponentA cptA;
        ComponentB cptB;

        ConcreteMediator conMed(&cptA, &cptB);

        std::cout<<"Client triggers operation 1\n";
        cptA.DoSomething1();

        std::cout<<"Client triggers operation 2\n";
        cptB.DoSomething4();
    }
}

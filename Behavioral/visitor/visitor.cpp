#include "visitor.hpp"

namespace VisitorDP
{
    Visitor::~Visitor()
    {
    }

    ConcreteVisitor::ConcreteVisitor(/* args */)
    {
    }

    ConcreteVisitor::~ConcreteVisitor()
    {
    }

    ConcreteElement1::ConcreteElement1(/* args */)
    {
    }

    ConcreteElement1::~ConcreteElement1()
    {
    }

    void ConcreteElement1::accept(Visitor *visitor)
    {
        visitor->visitConcreteElement1(this);
    }

    void ConcreteElement1::SpecialOperation1()
    {
        std::cout << "Special Opeeation in 1\n";
    }

    ConcreteElement2::ConcreteElement2(/* args */)
    {
    }

    ConcreteElement2::~ConcreteElement2()
    {
    }

    void ConcreteElement2::accept(Visitor *visitor)
    {
        visitor->visitConcreteElement2(this);
    }

    void ConcreteElement2::SpecialOperation2()
    {
        std::cout << "Special Opeeation in 2\n";
    }

    void ConcreteVisitor::visitConcreteElement1(ConcreteElement1 *conEl1)
    {
        conEl1->SpecialOperation1();
    }

    void ConcreteVisitor::visitConcreteElement2(ConcreteElement2 *conEl2)
    {
        conEl2->SpecialOperation2();
    }

    void Execute()
    {
        ConcreteVisitor conVisit;
        Element *conEl1 = new ConcreteElement1;
        Element *conEl2 = new ConcreteElement2;

        conEl1->accept(new ConcreteVisitor);
        conEl2->accept(new ConcreteVisitor);
    }
}

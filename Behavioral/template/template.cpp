#include "template.hpp"

namespace TemplateDP
{
    AbstractClass::AbstractClass(/* args */)
    {
    }

    AbstractClass::~AbstractClass()
    {
    }

    void AbstractClass::TemplateMethod() const
    {
        this->Baseoperation1();
        this->RequiredOperations1();
        this->Baseoperation2();
        this->Hook1();
        this->RequiredOperations2();
        this->Hook2();
    }

    void AbstractClass::Baseoperation1() const
    {
        std::cout << "Base Operations 1\n";
    }

    void AbstractClass::Baseoperation2() const
    {
        std::cout << "Base Operations 2\n";
    }

    void AbstractClass::Baseoperation3() const
    {
        std::cout << "Base Operations 3\n";
    }

    ConcreteClass1::ConcreteClass1(/* args */)
    {
    }

    ConcreteClass1::~ConcreteClass1()
    {
    }

    void ConcreteClass1::RequiredOperations1() const
    {
        std::cout << "ConcreteClass1 says: Implemented Operation1\n";
    }
    void ConcreteClass1::RequiredOperations2() const
    {
        std::cout << "ConcreteClass1 says: Implemented Operation2\n";
    }

    ConcreteClass2::ConcreteClass2(/* args */)
    {
    }

    ConcreteClass2::~ConcreteClass2()
    {
    }

    void ConcreteClass2::RequiredOperations1() const
    {
        std::cout << "ConcreteClass2 says: Implemented Operation1\n";
    }
    void ConcreteClass2::RequiredOperations2() const
    {
        std::cout << "ConcreteClass2 says: Implemented Operation2\n";
    }

    void ConcreteClass2::Hook1() const
    {
        std::cout << "ConcreteClass2 says: Overridden Hook1\n";
    }

    void Execute()
    {
        AbstractClass *concreteClass1 = new ConcreteClass1();
        concreteClass1->TemplateMethod();

        std::cout << "\n";

        AbstractClass *concreteClass2 = new ConcreteClass2();
        concreteClass2->TemplateMethod();

        std::cout << "\n";

        concreteClass1->TemplateMethod();

        delete concreteClass1;
        delete concreteClass2;
    }
}

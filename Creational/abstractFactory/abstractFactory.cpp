#include "abstractFactory.hpp"

namespace AbstractFactoryDP
{
    AbstractProductA::AbstractProductA()
    {
    }
    
    AbstractProductA::~AbstractProductA()
    {    
    }

    AbstractProductB::AbstractProductB()
    {
    }
    
    AbstractProductB::~AbstractProductB()
    {
    }

    AbstractFactory::AbstractFactory()
    {
    }
    
    AbstractFactory::~AbstractFactory()
    {
    }

    ConcreteProductA1::ConcreteProductA1()
    {
    }
    
    ConcreteProductA1::~ConcreteProductA1()
    {
    }

    std::string ConcreteProductA1::doSomeA() const
    {
        return "The result of ProductA1";
    }

    ConcreteProductA2::ConcreteProductA2()
    {
    }
    
    ConcreteProductA2::~ConcreteProductA2()
    {
    }

    std::string ConcreteProductA2::doSomeA() const
    {
        return "The result of ProductA2";
    }

    ConcreteProductB1::ConcreteProductB1()
    {
    }
    
    ConcreteProductB1::~ConcreteProductB1()
    {
    }

    std::string ConcreteProductB1::doSomeB(const AbstractProductA &collaborator) const
    {

        return "The result of ProductB1 collaborating with " + collaborator.doSomeA();
    }

    ConcreteProductB2::ConcreteProductB2()
    {
    }
    
    ConcreteProductB2::~ConcreteProductB2()
    {
    }

    std::string ConcreteProductB2::doSomeB(const AbstractProductA &collaborator) const
    {
        return "The result of ProductB2 collaborating with " + collaborator.doSomeA();
    }

    ConcreteFactory1::ConcreteFactory1()
    {
    }
    
    ConcreteFactory1::~ConcreteFactory1()
    {
    }

    AbstractProductA* ConcreteFactory1::createProductA(void)
    {
        return new ConcreteProductA1();
    }

    AbstractProductB* ConcreteFactory1::createProductB(void)
    {
        return new ConcreteProductB1();
    }

    ConcreteFactory2::ConcreteFactory2()
    {
    }
    
    ConcreteFactory2::~ConcreteFactory2()
    {
    }

    AbstractProductA* ConcreteFactory2::createProductA(void)
    {
        return new ConcreteProductA1();
    }

    AbstractProductB* ConcreteFactory2::createProductB(void)
    {
        return new ConcreteProductB1();
    }

    Main::Main()
    {
    }
    
    Main::~Main()
    {
    }

    void Main::execute()
    {
        AbstractFactory* conFact1 = new ConcreteFactory1;
        AbstractFactory* conFact2 = new ConcreteFactory2;

        AbstractProductA* productA = conFact1->createProductA();
        AbstractProductB* productB = conFact1->createProductB();

        std::cout << productA->doSomeA() <<"\n";
        std::cout << productB->doSomeB(*productA) <<"\n";

        delete productA;
        delete productB;

        productA = conFact2->createProductA();
        productB = conFact2->createProductB();

        std::cout << productA->doSomeA() <<"\n";
        std::cout <<  productB->doSomeB(*productA) <<"\n";

        delete productA;
        delete productB;

    }
}


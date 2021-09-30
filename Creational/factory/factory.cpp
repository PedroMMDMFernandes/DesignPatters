#include "factory.hpp"
#include <iostream>

namespace FactoryDP {
    Product::Product()
    {
    }

    Product::~Product()
    {
        std::cout<<"Product do stuff\n";
    }

    void Product::doStuff()
    {
    }

    ConcreteProductA::ConcreteProductA()
    {
    }

    ConcreteProductA::~ConcreteProductA()
    {
    }

    void ConcreteProductA::doStuff()
    {
        std::cout<<"ConcreteProductA do stuff\n";
    }

    ConcreteProductB::ConcreteProductB()
    {
    }

    ConcreteProductB::~ConcreteProductB()
    {
    }

    void ConcreteProductB::doStuff()
    {
        std::cout<<"ConcreteProductB do stuff\n";
    }

    Creator::Creator()
    {
        std::cout<<"Creator Constructor \n";
    }
    
    Creator::~Creator()
    {
    }

    void Creator::someOperation()
    {
        Product* product = this->createProduct();

        std::cout<<"Creator's code juts worked with:";
        product->doStuff();
        std::cout<<"\n";

        delete product;
    }

    ConcreteCreatorA::ConcreteCreatorA()
    {
    }
    
    ConcreteCreatorA::~ConcreteCreatorA()
    {
    }

    Product* ConcreteCreatorA::createProduct() const 
    {
        std::cout<<"ConcreteA Creator Constructor \n";

        return new ConcreteProductA;
    }

    ConcreteCreatorB::ConcreteCreatorB()
    {
    }
    
    ConcreteCreatorB::~ConcreteCreatorB()
    {
    }

    Product* ConcreteCreatorB::createProduct() const
    {
        std::cout<<"ConcreteB Creator Product \n";

        return new ConcreteProductB;
    }
        
    Main::Main()
    {
    }
    
    Main::~Main()
    {
    }

    void Main::execute()
    {
        std::cout<<"ConcreteA Creator Product \n";

        Creator * creator1 = new ConcreteCreatorA;

        creator1->someOperation();

        std::cout<<"ConcreteB Creator Product \n";

        Creator * creator2 = new ConcreteCreatorB;

        creator2->someOperation();

        delete creator1;
        delete creator2;
    }
}

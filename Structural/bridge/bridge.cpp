#include "bridge.hpp"

namespace BridgeDP
{
    ImplementationInterface::ImplementationInterface()
    {
    }
    
    ImplementationInterface::~ImplementationInterface()
    {
    }


    Abstraction::Abstraction()
    {
    }
    
    Abstraction::~Abstraction()
    {
    }

    ConcreteImplementation1::ConcreteImplementation1()
    {
    }
    
    ConcreteImplementation1::~ConcreteImplementation1()
    {
    }


    ConcreteImplementation2::ConcreteImplementation2()
    {
    }
    
    ConcreteImplementation2::~ConcreteImplementation2()
    {
    }

    std::string ConcreteImplementation1::method() const
    {
        return "ConcreteImplementation1 Method1 Implementation";
    }

    std::string ConcreteImplementation2::method() const    
    {
        return "ConcreteImplementation2 Method2 Implementation";
    }

    RefinedAbstraction::RefinedAbstraction(ImplementationInterface* impl)
    {
        this->impl = impl;
    }
    
    RefinedAbstraction::~RefinedAbstraction()
    {
        delete this->impl;
    }

    std::string RefinedAbstraction::DoOperation(void) const
    {
        return "Refined Operation with " + impl->method();
    }

    Main::Main()
    {
    }
    
    Main::~Main()
    {
    }

    void Main::execute()
    {
        ImplementationInterface* conImpl = new ConcreteImplementation1;
        
        Abstraction* abst = new RefinedAbstraction(conImpl);

        std::cout<<abst->DoOperation()<<std::endl;
        
        delete conImpl;
        delete abst;

        conImpl = new ConcreteImplementation2;
        abst = new RefinedAbstraction(conImpl);
        
        std::cout<<abst->DoOperation()<<std::endl;

        delete conImpl;
        delete abst;
    }
}
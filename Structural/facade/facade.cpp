#include "facade.hpp"

namespace FacadeDP
{
    Facade::Facade(Subsystem1* subsystem1, Subsystem2* subsystem2)
    {
        this->subsystem1 = subsystem1 ? nullptr : new Subsystem1;
        this->subsystem2 = subsystem2 ? nullptr : new Subsystem2;
    }
    
    Facade::~Facade()
    {
        delete this->subsystem1;
        delete this->subsystem2;
    }

    std::string Facade::CallSubsystemOperation() const
    {
        return "Facade_Operation " + this->subsystem1->CallOperation() + this->subsystem2->CallOperation();  
    }

    Subsystem1::Subsystem1()
    {
    }
    
    Subsystem1::~Subsystem1()
    {
    }

    std::string Subsystem1::CallOperation() const
    {
        return "Subsystem1_Operation";  
    }

    Subsystem2::Subsystem2()
    {
    }
    
    Subsystem2::~Subsystem2()
    {
    }

    std::string Subsystem2::CallOperation() const
    {
        return "Subsystem2_Operation";
    }

    void Execute()
    {
        
        Facade* facade = new Facade;

        std::cout<<facade->CallSubsystemOperation()<<std::endl;

        delete facade;
    }
}


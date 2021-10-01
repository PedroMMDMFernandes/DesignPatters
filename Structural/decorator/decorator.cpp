#include "decorator.hpp"

namespace DecoratorDP
{
    ComponentInterface::ComponentInterface()
    {
    }
    
    ComponentInterface::~ComponentInterface()
    {
    }
        
    ConcreteComponent::ConcreteComponent()
    {
    }
    
    ConcreteComponent::~ConcreteComponent()
    {
    }

    std::string ConcreteComponent::Execute() const
    {
        return "ConcreteComponent";
    }

    BaseDecorator::BaseDecorator(ComponentInterface* compInt)
    {
        this->compInt = compInt;
    }
    
    BaseDecorator::~BaseDecorator()
    {
    }

    std::string BaseDecorator::Execute() const
    {
        
        return this->compInt->Execute();
    }

    ConcreteDecorator1::ConcreteDecorator1(ComponentInterface* conImpl)
    :BaseDecorator(conImpl)
    {
    }
    
    ConcreteDecorator1::~ConcreteDecorator1()
    {
    }

    std::string ConcreteDecorator1::Execute() const
    {
        
        return  "ConcreteDecorator1 " + BaseDecorator::Execute();
    }

    ConcreteDecorator2::ConcreteDecorator2(ComponentInterface* conImpl)
    :BaseDecorator(conImpl)
    {        
    }
    
    ConcreteDecorator2::~ConcreteDecorator2()
    {
    }

    std::string ConcreteDecorator2::Execute() const
    {
        
        return "ConcreteDecorator2 " + BaseDecorator::Execute();
    }

    void execute()
    {
        ComponentInterface* conComp = new ConcreteComponent();
        ComponentInterface* conDec1= new ConcreteDecorator1(conComp);

        std::cout<<conComp->Execute()<<std::endl;
        std::cout<<conDec1->Execute()<<std::endl;

        ComponentInterface* conDec2= new ConcreteDecorator2(conDec1);

        std::cout<<conDec2->Execute()<<std::endl;

        delete conComp;
        delete conDec1;
        delete conDec2;
    }

    void executeStatic()
    {
        ConcreteComponent conComp;
        ConcreteDecorator1 conDec1(&conComp);

        std::cout<<conComp.Execute()<<std::endl;
        std::cout<<conDec1.Execute()<<std::endl;

        ConcreteDecorator2 conDec2=(&conDec1);

        std::cout<<conDec2.Execute()<<std::endl;
    }
    
}

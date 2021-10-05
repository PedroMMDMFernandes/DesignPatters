#include <iostream>
#include <string>

namespace MediatorDP
{
    class Mediator;

    class BaseComponent
    {
    public:
        BaseComponent(Mediator * mediator = nullptr);
        BaseComponent(BaseComponent &&) = default;
        BaseComponent(const BaseComponent &) = default;
        BaseComponent &operator=(BaseComponent &&) = default;
        BaseComponent &operator=(const BaseComponent &) = default;
        ~BaseComponent();

        void SetMediator(Mediator * mediator );
    
    protected:
      Mediator * mediator;  
    };

    class Mediator
    {
    public:
        virtual void Notify(BaseComponent * baseComp, std::string) const = 0;
    
    private:
        
    };

    class ComponentA: public BaseComponent
    {
    public:
        ComponentA();
        ComponentA(ComponentA &&) = default;
        ComponentA(const ComponentA &) = default;
        ComponentA &operator=(ComponentA &&) = default;
        ComponentA &operator=(const ComponentA &) = default;
        ~ComponentA();

        void DoSomething1();
        void DoSomething2();
    
    private:
        
    };


        
    class ComponentB: public BaseComponent
    {
    public:
        ComponentB();
        ComponentB(ComponentB &&) = default;
        ComponentB(const ComponentB &) = default;
        ComponentB &operator=(ComponentB &&) = default;
        ComponentB &operator=(const ComponentB &) = default;
        ~ComponentB();

        void DoSomething3();
        void DoSomething4();
    
    private:
        
    };
    


    class ConcreteMediator: public Mediator
    {
    public:
        ConcreteMediator(ComponentA* cptA, ComponentB* cptB);
        ConcreteMediator(ConcreteMediator &&) = default;
        ConcreteMediator(const ConcreteMediator &) = default;
        ConcreteMediator &operator=(ConcreteMediator &&) = default;
        ConcreteMediator &operator=(const ConcreteMediator &) = default;
        ~ConcreteMediator();

        void Notify(BaseComponent * baseComp, std::string event) const override;
    
    private:
        ComponentA* cptA;
        ComponentB* cptB;
    };

    void Execute();
    

}
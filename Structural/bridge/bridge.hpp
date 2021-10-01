#include <iostream>

namespace BridgeDP
{
    class ImplementationInterface
    {
    public:
        ImplementationInterface();
        ImplementationInterface(ImplementationInterface &&) = default;
        ImplementationInterface(const ImplementationInterface &) = default;
        ImplementationInterface &operator=(ImplementationInterface &&) = default;
        ImplementationInterface &operator=(const ImplementationInterface &) = default;
        ~ImplementationInterface();

        virtual std::string method() const = 0;
    
    private:
        
    };

    class ConcreteImplementation1 : public ImplementationInterface
    {
    public:
        ConcreteImplementation1();
        ConcreteImplementation1(ConcreteImplementation1 &&) = default;
        ConcreteImplementation1(const ConcreteImplementation1 &) = default;
        ConcreteImplementation1 &operator=(ConcreteImplementation1 &&) = default;
        ConcreteImplementation1 &operator=(const ConcreteImplementation1 &) = default;
        ~ConcreteImplementation1();

        std::string method() const override;
    
    private:
        
    };

    class ConcreteImplementation2: public ImplementationInterface 
    {
    public:
        ConcreteImplementation2();
        ConcreteImplementation2(ConcreteImplementation2 &&) = default;
        ConcreteImplementation2(const ConcreteImplementation2 &) = default;
        ConcreteImplementation2 &operator=(ConcreteImplementation2 &&) = default;
        ConcreteImplementation2 &operator=(const ConcreteImplementation2 &) = default;
        ~ConcreteImplementation2();

        std::string method() const override;
    private:
        
    };
  
    
    class Abstraction
    {
    public:
        Abstraction();
        Abstraction(Abstraction &&) = default;
        Abstraction(const Abstraction &) = default;
        Abstraction &operator=(Abstraction &&) = default;
        Abstraction &operator=(const Abstraction &) = default;
        ~Abstraction();

        virtual std::string DoOperation(void) const = 0;
    
    protected:
        ImplementationInterface* impl;
        
    };

    class RefinedAbstraction:  public Abstraction
    {
    public:
        RefinedAbstraction(ImplementationInterface* impl);
        RefinedAbstraction(RefinedAbstraction &&) = default;
        RefinedAbstraction(const RefinedAbstraction &) = default;
        RefinedAbstraction &operator=(RefinedAbstraction &&) = default;
        RefinedAbstraction &operator=(const RefinedAbstraction &) = default;
        ~RefinedAbstraction();

        std::string DoOperation(void) const override;
    
    private:
        
    };
    


    class Main
    {
    public:
        Main();
        Main(Main &&) = default;
        Main(const Main &) = default;
        Main &operator=(Main &&) = default;
        Main &operator=(const Main &) = default;
        ~Main();

        void execute();
    
    private:
        
    };
}



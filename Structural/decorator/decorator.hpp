#include <iostream>

namespace DecoratorDP
{
    class ComponentInterface
    {
    public:
        ComponentInterface();
        ComponentInterface(ComponentInterface &&) = default;
        ComponentInterface(const ComponentInterface &) = default;
        ComponentInterface &operator=(ComponentInterface &&) = default;
        ComponentInterface &operator=(const ComponentInterface &) = default;
        ~ComponentInterface();

        virtual std::string Execute() const = 0;
    
    private:
        
    };

    class ConcreteComponent: public ComponentInterface
    {
    public:
        ConcreteComponent();
        ConcreteComponent(ConcreteComponent &&) = default;
        ConcreteComponent(const ConcreteComponent &) = default;
        ConcreteComponent &operator=(ConcreteComponent &&) = default;
        ConcreteComponent &operator=(const ConcreteComponent &) = default;
        ~ConcreteComponent();

        std::string Execute() const;
    
    private:
        
    };

    class BaseDecorator: public ComponentInterface
    {
    public:
        BaseDecorator(ComponentInterface* compInt);
        BaseDecorator(BaseDecorator &&) = default;
        BaseDecorator(const BaseDecorator &) = default;
        BaseDecorator &operator=(BaseDecorator &&) = default;
        BaseDecorator &operator=(const BaseDecorator &) = default;
        ~BaseDecorator();

        virtual std::string Execute() const override;
    
    protected:
        ComponentInterface* compInt;
        
    };
    
    class ConcreteDecorator1: public BaseDecorator 
    {
    public:
        ConcreteDecorator1(ComponentInterface* conImpl);
        ConcreteDecorator1(ConcreteDecorator1 &&) = default;
        ConcreteDecorator1(const ConcreteDecorator1 &) = default;
        ConcreteDecorator1 &operator=(ConcreteDecorator1 &&) = default;
        ConcreteDecorator1 &operator=(const ConcreteDecorator1 &) = default;
        ~ConcreteDecorator1();
        
        std::string Execute() const override;

    private:
        ComponentInterface* conImpl;
    };

    class ConcreteDecorator2: public BaseDecorator 
    {
    public:
        ConcreteDecorator2(ComponentInterface* conImpl);
        ConcreteDecorator2(ConcreteDecorator2 &&) = default;
        ConcreteDecorator2(const ConcreteDecorator2 &) = default;
        ConcreteDecorator2 &operator=(ConcreteDecorator2 &&) = default;
        ConcreteDecorator2 &operator=(const ConcreteDecorator2 &) = default;
        ~ConcreteDecorator2();
        
        std::string Execute() const override;

    private:
        ComponentInterface* conImpl;
    };

    void execute();
    void executeStatic();
}
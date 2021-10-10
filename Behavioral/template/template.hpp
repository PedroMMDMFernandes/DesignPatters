#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>

namespace TemplateDP
{
    class AbstractClass
    {
    private:
        /* data */
    public:
        AbstractClass(/* args */);
        ~AbstractClass();

        void TemplateMethod() const;

        void Baseoperation1() const;
        void Baseoperation2() const;
        void Baseoperation3() const;

        virtual void Hook1() const {}
        virtual void Hook2() const {}

        virtual void RequiredOperations1() const = 0;
        virtual void RequiredOperations2() const = 0;
    };

    class ConcreteClass1 : public AbstractClass
    {
    private:
        /* data */
    public:
        ConcreteClass1(/* args */);
        ~ConcreteClass1();
        void RequiredOperations1() const override;
        void RequiredOperations2() const override;
    };

    class ConcreteClass2 : public AbstractClass
    {
    private:
        /* data */
    public:
        ConcreteClass2(/* args */);
        ~ConcreteClass2();
        void RequiredOperations1() const override;
        void RequiredOperations2() const override;
        void Hook1() const override;
    };

    void Execute();

}

#endif // !TEMPLATE_HPP

#ifndef VISITOR_HPP
#define VISITOR_HPP

#include <iostream>

namespace VisitorDP
{
    class ConcreteElement1;
    class ConcreteElement2;

    class Visitor
    {
    private:
        /* data */
        ConcreteElement1 *ConEl1;
        ConcreteElement2 *ConEl2;

    public:
        virtual ~Visitor();

        virtual void visitConcreteElement1(ConcreteElement1 *conEl1) = 0;
        virtual void visitConcreteElement2(ConcreteElement2 *conEl2) = 0;
    };

    class ConcreteVisitor : public Visitor
    {
    private:
        /* data */
    public:
        ConcreteVisitor(/* args */);
        ~ConcreteVisitor();

        void visitConcreteElement1(ConcreteElement1 *conEl1) override;
        void visitConcreteElement2(ConcreteElement2 *conEl2) override;
    };

    class Element
    {
    private:
        /* data */
    public:
        virtual ~Element(){}

        virtual void accept(Visitor *visitor) = 0;
    };

    class ConcreteElement1 : public Element
    {
    private:
        /* data */
    public:
        ConcreteElement1(/* args */);
        ~ConcreteElement1();

        void accept(Visitor *visitor) override;
        void SpecialOperation1();
    };

    class ConcreteElement2 : public Element
    {
    private:
        /* data */
    public:
        ConcreteElement2(/* args */);
        ~ConcreteElement2();
        void accept(Visitor *visitor) override;
        void SpecialOperation2();
    };

    void Execute();
}

#endif // !VISITOR_HPP

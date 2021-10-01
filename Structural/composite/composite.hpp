#include<iostream>
#include<list>

namespace CompositeDP
{
    class Component
    {
    public:
        Component();
        Component(Component &&) = default;
        Component(const Component &) = default;
        Component &operator=(Component &&) = default;
        Component &operator=(const Component &) = default;
        ~Component();

        void SetParent(Component *parent);

        Component* GetParent(void) const;

        virtual bool IsParent() const;
        

        virtual std::string Operation() = 0;

        virtual void AddChild(Component* child);
        virtual void RemoveChild(Component* child);

    protected:
        Component *parent;
        
    };

    class Leaf: public Component
    {
    public:
        Leaf();
        Leaf(Leaf &&) = default;
        Leaf(const Leaf &) = default;
        Leaf &operator=(Leaf &&) = default;
        Leaf &operator=(const Leaf &) = default;
        ~Leaf();

        std::string Operation() override;

    
    private:
        
    };
    
    class Composite: public Component
    {
    public:
        Composite();
        Composite(Composite &&) = default;
        Composite(const Composite &) = default;
        Composite &operator=(Composite &&) = default;
        Composite &operator=(const Composite &) = default;
        ~Composite();

        bool IsParent() const;
        

        std::string Operation() override;

        void AddChild(Component* child);
        void RemoveChild(Component* child);
    
    private:
        std::list<Component*> list_components;
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


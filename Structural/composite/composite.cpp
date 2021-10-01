#include "composite.hpp"

namespace CompositeDP
{
    Component::Component()
    {
    }
    
    Component::~Component()
    {
    }

    void Component::SetParent(Component *parent) 
    {
        this->parent = parent;
    }

    Component* Component::GetParent(void) const
    {
        return this->parent;
    }

    bool Component::IsParent() const
    {
        return false;
    }

    void Component::AddChild(Component* child)
    {

    }

    void Component::RemoveChild(Component* child)
    {

    }

    Leaf::Leaf()
    {
    }
    
    Leaf::~Leaf()
    {
    }

    std::string Leaf::Operation() {
        return "Leaf";
    }

    Composite::Composite(/* args */)
    {
    }

    Composite::~Composite()
    {
    }

    bool Composite::IsParent() const
    {
        return true;
    }
    std::string Composite::Operation()
    {
        std::string result;
        std::list<Component*>::iterator it = list_components.begin();

        for (it=list_components.begin(); it != list_components.end(); ++it)
        {
            result += (*it)->Operation();
        }
        
        return "Branch: ("+result+")";
    }

    void Composite::AddChild(Component* child)
    {
        list_components.push_back(child);
        child->SetParent(this);
    }

    void Composite::RemoveChild(Component* child)
    {
        list_components.remove(child);
        child->SetParent(nullptr);
    }

    Main::Main()
    {
    }
    
    Main::~Main()
    {
    }

    void Main::execute()
    {
        Component* tree = new Composite();
        Component* composite1 = new Composite();
        Component* composite2 = new Composite();
        Component* leaf1 = new Leaf(); 
        Component* leaf2 = new Leaf(); 
        Component* leaf3 = new Leaf(); 

        composite1->AddChild(leaf1);
        composite1->AddChild(leaf2);

        std::cout<<"Composite1 "<<std::endl;
        std::cout<<composite1->Operation()<<std::endl;

        composite2->AddChild(leaf3);

        std::cout<<"Composite2 "<<std::endl;
        std::cout<<composite2->Operation()<<std::endl;

        tree->AddChild(composite1);
        tree->AddChild(composite2);

        std::cout<<"tree "<<std::endl;
        std::cout<<tree->Operation()<<std::endl;

        delete tree;
        delete composite1;
        delete composite2;
        delete leaf1;
        delete leaf2;
        delete leaf3;
    }

}
#include "memento.hpp"
#include <ctime>

namespace MementoDP
{
    Memento::Memento(/* args */)
    {
    }

    Memento::~Memento()
    {
    }

    ConcreteMemento::ConcreteMemento(std::string state)
        : state(state)
    {
        std::time_t now = std::time(0);
        date = std::ctime(&now);
    }

    ConcreteMemento::~ConcreteMemento()
    {
    }

    std::string ConcreteMemento::GetState() const
    {
        return this->state;
    }
    std::string ConcreteMemento::GetDate() const
    {
        return this->date;
    }
    std::string ConcreteMemento::GetName() const
    {
        return this->date + " / (" + this->state.substr(0, 9) + "...)";
    }

    Originator::Originator(std::string state)
        : state(state)
    {
        std::cout << "Originator: My initial state is: " << this->state << "\n";
    }

    Originator::~Originator()
    {
    }

    Memento *Originator::SaveState()
    {
        return new ConcreteMemento(this->state);
    }

    void Originator::Restore(Memento &memento)
    {
        this->state = memento.GetState();

        std::cout << "Originator: My state has changed to: " << this->state << "\n";
    }

    std::string Originator::GenerateRandomString(int length)
    {
        const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
        int stringLength = sizeof(alphanum) - 1;

        std::string random_string;
        for (int i = 0; i < length; i++)
        {
            random_string += alphanum[std::rand() % stringLength];
        }
        return random_string;
    }

    void Originator::DoSomething()
    {
        std::cout << "Originator: I'm doing something important.\n";
        this->state = this->GenerateRandomString(30);
        std::cout << "Originator: and my state has changed to: " << this->state << "\n";
    }

    Caretaker::Caretaker(Originator *orig)
        : orig(orig)
    {
    }

    Caretaker::~Caretaker()
    {
    }

    void Caretaker::Backup()
    {
        mementos.push_back(orig->SaveState());
    }

    void Caretaker::Undo()
    {
        if (!mementos.empty())
        {
            Memento *memento = mementos.back();
            mementos.pop_back();

            std::cout << "Caretaker: Restoring state to: " << memento->GetName() << "\n";

            try
            {
                orig->Restore(*memento);
            }
            catch (...)
            {
                this->Undo();
            }
        }
    }

    void Caretaker::ShowHistory()
    {
        std::vector<Memento *>::iterator it;
        for (it = mementos.begin(); it != mementos.end(); it++)
        {
            /* code */
            std::cout << "Caretaker: Here's the list of mementos:\n";

            std::cout << (*it)->GetName() << "\n";
        }
    }

    void Execute()
    {
        Originator orig("Super-duper-super-puper-super.");
        Caretaker caretaker(&orig);

        caretaker.Backup();
        orig.DoSomething();
        caretaker.Backup();
        orig.DoSomething();
        caretaker.Backup();
        orig.DoSomething();

        std::cout<<"\n";

        caretaker.ShowHistory();

        std::cout << "\nClient: Now, let's rollback!\n\n";
        caretaker.Undo();
        std::cout << "\nClient: Once more!\n\n";
        caretaker.Undo();
    }
}

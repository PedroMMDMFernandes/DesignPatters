#include <iostream>
#include <vector>

namespace MementoDP
{
    class Memento
    {
    private:
        /* data */
    public:
        Memento(/* args */);
        ~Memento();

        virtual std::string GetState() const = 0;
        virtual std::string GetDate() const = 0;
        virtual std::string GetName() const = 0;
    };

    class ConcreteMemento : public Memento
    {
    private:
        /* data */
        std::string state;
        std::string date;
        std::string name;

    public:
        ConcreteMemento(std::string state);
        ~ConcreteMemento();

        std::string GetState() const override;
        std::string GetDate() const override;
        std::string GetName() const override;
    };

    class Originator
    {
    private:
        std::string state;
        std::string GenerateRandomString(int length = 10);

    public:
        Originator(std::string state);
        ~Originator();

        Memento *SaveState();
        void Restore(Memento &memento);
        void DoSomething();
    };

    class Caretaker
    {
    private:
        std::vector<Memento *> mementos;
        Originator *orig;

    public:
        Caretaker(Originator *orig);
        ~Caretaker();

        void Backup();
        void Undo();
        void ShowHistory();
    };

    void Execute();

}

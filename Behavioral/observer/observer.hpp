#include <iostream>
#include <list>
#include <string_view>

namespace ObserverDP
{
    class IObserver
    {
    private:
        /* data */
    public:
        virtual ~IObserver(){}
        virtual void Update(const std::string_view& receivedMsg) = 0;
    };

    class ISubject
    {
    private:
        /* data */
    public:
        virtual ~ISubject(){}
        virtual void Subscribe(IObserver* subscriber) = 0;
        virtual void Unsubscribe(IObserver* subscriber) = 0;
        virtual void Notify() = 0;
        virtual void executeMainOperation(const std::string_view event) = 0;
    };

    class Subject : public ISubject
    {
    private:
        /* data */
        std::list<IObserver*> subscribers;
        std::string message;
    public:
        Subject(/* args */);
        ~Subject();

        void Subscribe(IObserver* subscriber) override;
        void Unsubscribe(IObserver* subscriber) override;
        void Notify() override;
        void executeMainOperation(const std::string_view event) override;
    };

    class Observer: public IObserver
    {
    private:
        /* data */

        Subject& subject;
        static int amountOfObservers;
        int numb;
    public:
        Observer(Subject& subject);
        ~Observer();

        void Update(const std::string_view& receivedMsg);
        void RemoveSubscription();
    };
    

    void Execute();

}

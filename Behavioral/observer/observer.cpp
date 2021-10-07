#include "observer.hpp"

namespace ObserverDP
{
    Subject::Subject(/* args */)
    {
    }

    Subject::~Subject()
    {
    }

    void Subject::Subscribe(IObserver *subscriber)
    {
        subscribers.push_back(subscriber);
    }

    void Subject::Unsubscribe(IObserver *subscriber)
    {
        subscribers.remove(subscriber);
    }

    void Subject::Notify()
    {
        std::list<IObserver *>::iterator it;

        for (it = subscribers.begin(); it != subscribers.end(); ++it)
        {
            /* code */

            (*it)->Update(message);
        }
    }

    void Subject::executeMainOperation(const std::string_view event)
    {
        message = event;
        std::cout << "Notifying from Subject\n";
        Notify();
    }

    int Observer::amountOfObservers = 0;

    Observer::Observer(Subject &subject)
        : subject(subject)
    {
        subject.Subscribe(this);
        std::cout << "Hello from Observer "<< ++Observer::amountOfObservers << "\n";
        this->numb = Observer::amountOfObservers;
        
    }

    Observer::~Observer()
    {
    }

    void Observer::Update(const std::string_view &receivedMsg)
    {
        std::cout << "Observer " << this->numb << " received: " << receivedMsg<< "\n";
    }

    void Observer::RemoveSubscription()
    {
        subject.Unsubscribe(this);
    }

    void Execute()
    {
        Subject subject;

        Observer o1 (subject);
        Observer o2(subject);
        Observer o3(subject);
        Observer o4(subject);

        subject.executeMainOperation("Init");

        o4.RemoveSubscription();
        subject.executeMainOperation("Start");

        o3.RemoveSubscription();
        subject.executeMainOperation("Normal");

        o2.RemoveSubscription();
        subject.executeMainOperation("Stop");
    }
}

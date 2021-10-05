#include <iostream>

namespace CommandDP
{
    class Command
    {
    public:
        Command();
        Command(Command &&) = default;
        Command(const Command &) = default;
        Command &operator=(Command &&) = default;
        Command &operator=(const Command &) = default;
        ~Command();

        virtual std::string Execute() const = 0;
    
    private:
        
    };

    class Invoker
    {
    public:
        Invoker(Command& command);
        Invoker(Invoker &&) = default;
        Invoker(const Invoker &) = default;
        Invoker &operator=(Invoker &&) = default;
        Invoker &operator=(const Invoker &) = default;
        ~Invoker();

        void SetCommand(Command& command);
        std::string ExecuteCommand();
    
    private:
        Command *command;
    };

    class Receiver
    {
    public:
        Receiver();
        Receiver(Receiver &&) = default;
        Receiver(const Receiver &) = default;
        Receiver &operator=(Receiver &&) = default;
        Receiver &operator=(const Receiver &) = default;
        ~Receiver();
        
        std::string Operation(const std::string data);

    
    private:
        
    };

    class Command1: public Command
    {
    public:
        Command1(Receiver& receiver, const std::string data);
        Command1(Command1 &&) = default;
        Command1(const Command1 &) = default;
        Command1 &operator=(Command1 &&) = default;
        Command1 &operator=(const Command1 &) = default;
        ~Command1();

        std::string Execute() const override;
    
    private:
        std::string data;
        Receiver* receiver;
    };

    class Command2: public Command
    {
    public:
        Command2(Receiver& receiver, const std::string data);
        Command2(Command2 &&) = default;
        Command2(const Command2 &) = default;
        Command2 &operator=(Command2 &&) = default;
        Command2 &operator=(const Command2 &) = default;
        ~Command2();

        std::string Execute() const override;
    
    private:
        std::string data;
        Receiver* receiver;
    };
    
    void Execute();

}
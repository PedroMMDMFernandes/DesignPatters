#include <iostream>

namespace SingletonDP
{
    class Singleton
    {
    private:
        static Singleton* instance;
        std::string data;
    protected:
        /* data */
        Singleton(const std::string data);
    public:
        static Singleton* getInstance(const std::string& data);

        /**
         * Singletons should not be cloneable.
         */
        Singleton(Singleton &other) = delete;
        /**
         * Singletons should not be assignable.
         */
        void operator=(const Singleton &) = delete;

        std::string getValue();
        ~Singleton();
    };

    class Main
    {
    private:
        /* data */
    public:
        Main(/* args */)
        {}

        ~Main(){
        }

        void execute()
        {
            Singleton* singleton1 = Singleton::getInstance("FOO");
            Singleton* singleton2 = Singleton::getInstance("BAR");

            std::cout << singleton1->getValue()<<'\n';
            std::cout << singleton2->getValue()<<'\n';
        }
    };
}

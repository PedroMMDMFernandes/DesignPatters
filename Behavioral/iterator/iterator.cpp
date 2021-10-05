#include "iterator.hpp"

namespace IteratorDP
{
    Data::Data(int a)
        : m_data(a)
    {
    }

    void Data::SetData(int a)
    {
        m_data = a;
    }
    void Execute()
    {
        Container<int> cont;

        for (int i = 0; i < 10; i++)
        {
            cont.Add(i);
            /* code */
        }

        Iterator<int, Container<int>> *it = cont.CreateIterator();

        for (; !it->HasMore(); it->Next())
        {
            std::cout << *(it->GetCurrent()) << "\n";
        }

        Container<Data> cont2;
        Data a(100), b(1000), c(10000);
        cont2.Add(a);
        cont2.Add(b);
        cont2.Add(c);

        Iterator<Data, Container<Data>> *it2 = cont2.CreateIterator();
        for (; !it2->HasMore(); it2->Next())
        {
            std::cout << it2->GetCurrent()->GetData() << std::endl;
        }
    }
}

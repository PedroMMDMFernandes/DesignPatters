#include <iostream>
#include <vector>

namespace IteratorDP
{
    template <typename T, typename U>
    class Iterator
    {
    public:
        typedef typename std::vector<T>::iterator iter_type;
        ~Iterator();

        Iterator::Iterator(U *p_data, bool reverse = false)
            : m_p_data(p_data)
        {
            it = m_p_data->m_data.begin();
        }

        iter_type GetCurrent()
        {
            return it;
        }

        void Next()
        {
            it++;
        }

        bool HasMore()
        {
            return (it == m_p_data->m_data.end());
        }

    private:
        U *m_p_data;
        iter_type it;
    };

    template <typename T>
    class Container
    {
        friend class Iterator<T, Container>;

    public:
        Iterator<T, Container> *CreateIterator()
        {
            return new Iterator<T, Container>(this);
        }

        void Add(T a)
        {
            m_data.push_back(a);
        }

    private:
        std::vector<T> m_data;
    };

    class Data
    {
    public:
        Data(int a = 0);

        void SetData(int a);
        int GetData()
        {
            return m_data;
        }

    private:
        int m_data;
    };

    void Execute();
}

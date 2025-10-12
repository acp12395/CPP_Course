template<typename T>
class RingBuffer
{
private:
    int m_size;
    T* m_values;
    int m_pos;
public:
    class iterator;
public:
    RingBuffer(int size) : m_size(size), m_values(NULL), m_pos(0)
    {
        m_values = new T[size];
    }
    iterator begin()
    {
        return iterator(&m_values[0]);
    }
    iterator end()
    {
        return iterator(&m_values[m_size]);
    }
    void add(T val)
    {
        m_values[m_pos] = val;

        if(++m_pos == m_size)
        {
            m_pos = 0;
        }
    }
    T& operator[](const int& pos) const
    {
        return m_values[pos];
    }
    const int& size()
    {
        return m_size;
    }
    ~RingBuffer()
    {
        delete m_values;
        m_values = NULL;
    }
};

template<typename T>
class RingBuffer<T>::iterator
{
private:
    T* m_val;
public:
    iterator(T* val) : m_val(val){}
    T& operator*() {return *m_val;}
    iterator& operator++(int)
    {
        m_val++;
        return *this;
    }
    iterator& operator++()
    {
        m_val++;
        return *this;
    }
    bool operator!=(const iterator& other) const
    {
        return m_val != other.m_val;
    }
};
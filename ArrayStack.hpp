#ifndef ARRAY_STACK_HPP
#define ARRAY_STACK_HPP

#include <algorithm>
#include <exception>
#include <cassert>

#include "IStack.hpp"

template <class T>
class ArrayStack : public IStack<T>
{
    public:
        using size_type  = typename IStack<T>::size_type;
        using value_type = typename IStack<T>::value_type;

        /*
         * Rule of Three
         */
        ArrayStack() = delete;
        ArrayStack(const ArrayStack& other);
        ArrayStack& operator=(const ArrayStack& other);

        virtual ~ArrayStack();

        ArrayStack(size_type capacity);

        virtual void                push(const value_type&);
        virtual const value_type&   top() const;
        virtual void                pop();
        virtual bool                empty() const;
        virtual size_type           size() const;
        
    private:
        T*         mp_buffer{nullptr};
        size_type  m_capacity{size_type{}};
        size_type  m_top{size_type{}};

        void swap(ArrayStack& other);
};



template <class T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& other)
{
    mp_buffer = new T[other.m_top];
    std::copy(other.mp_buffer, 
              other.mp_buffer + other.size(),
              mp_buffer);
}

template <class T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& other)
{
    ArrayStack<T> copy(other);
    swap(copy);

    return *this;
}

template <class T>
ArrayStack<T>::~ArrayStack()
{
    delete[] mp_buffer;
}

template <class T>
ArrayStack<T>::ArrayStack(ArrayStack<T>::size_type capacity)
    : m_capacity(capacity)
{
    try 
    {
        mp_buffer = new T[capacity];
    } 
    catch(const std::bad_alloc& e)
    {
        std::cout << e.what() << '\n';
    }
}

template <class T>
void ArrayStack<T>::push(const ArrayStack<T>::value_type& value)
{
    if(m_top == m_capacity)
    {
        size_type newCapacity = m_capacity * 2;
        T *newBuffer = new T[newCapacity];

        std::copy(mp_buffer, mp_buffer + size(), newBuffer);

        delete mp_buffer;
        mp_buffer = newBuffer;
        m_capacity = newCapacity;
    }

    mp_buffer[m_top] = value;

    m_top++;
}

template <class T>
const typename ArrayStack<T>::value_type& ArrayStack<T>::top() const
{
    return mp_buffer[m_top - 1];
}

template <class T>
void ArrayStack<T>::pop() 
{
    assert(!empty());

    // delete (mp_buffer + m_top - 1);    

    m_top--;
}

template <class T>
bool ArrayStack<T>::empty() const
{
    return size() == 0;
}

template <class T>
typename ArrayStack<T>::size_type ArrayStack<T>::size() const
{
    return m_top - 1;
}

template <class T>
void ArrayStack<T>::swap(ArrayStack<T>& other)
{
    using std::swap;

    swap(mp_buffer, other.mp_buffer);
    swap(m_capacity, other.m_capacity);
    swap(m_top, other.m_top);
}

#endif 

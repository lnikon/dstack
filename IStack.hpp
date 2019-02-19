#ifndef ISTACK_HPP
#define ISTACK_HPP

template <class T>
class IStack
{
    public:
        using size_type  = unsigned long long;
        using value_type = T;

        virtual ~IStack() {}

        virtual void                push(const value_type&) = 0;
        virtual const value_type&   top() const = 0;
        virtual void                pop() = 0;
        virtual bool                empty() const = 0;
        virtual size_type           size() const = 0;
};

#endif

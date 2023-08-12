#ifndef SINGLETON_H
#define SINGLETON_H

#include <memory>

template<class T>
class Singleton
{
public:
    static T &Instance()
    {
        static std::unique_ptr<T> Object;

        if (!Object)
        {
            Object = std::unique_ptr<T>(new T);
        }

        return *Object;
    }
};

#endif // SINGLETON_H

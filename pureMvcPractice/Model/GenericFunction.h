#pragma once
#include <wx/wx.h>

class GenericFunction
{
public:
    template<typename T>
    static T* ConvertToNonConstType(const void* aValue)
    {
        T* result = static_cast<T*>(const_cast<void*>(aValue));
        return result;
    }
};

#ifndef _cb879289_38db_4010_a772_1a670b9bdc21
#define _cb879289_38db_4010_a772_1a670b9bdc21

#include "BaseFactory.h"

template<class T> template<typename TClass>
void BaseFactory<T>::register_()
{
    // if class not already registered
    if (this->_creators.find(TClass::class_name()) == this->_creators.end())
    {
        // register
        this->_creators.insert(std::make_pair(TClass::class_name(),
                                              []() { return TClass::New(); }));
    }
}

#endif // _cb879289_38db_4010_a772_1a670b9bdc21

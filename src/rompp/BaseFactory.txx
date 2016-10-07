#ifndef _BASEFACTORY_TXX_
#define _BASEFACTORY_TXX_

#include "BaseFactory.h"

template<class T> template<typename TClass>
void BaseFactory<T>::register_()
{
    // if class not already registered
    if (this->_creators.find(TClass::class_name()) == this->_creators.end())
    {
        // register
        this->_creators.insert(std::make_pair(TClass::class_name(), []() { return TClass::New(); }));
    }
}

#endif // _BASEFACTORY_TXX_ 


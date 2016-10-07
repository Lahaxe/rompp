#include "BaseFactory.h"

template<class T>
BaseFactory<T>::BaseFactory(): _creators(CreatorMap())
{
    // Nothing else.
}

template<class T>
BaseFactory<T>::~BaseFactory()
{
    // Nothing to do.
}

template<class T>
bool BaseFactory<T>::can_create(std::string const & name) const
{
    CreatorMap::const_iterator const creators_it = this->_creators.find(name);
    return (creators_it != this->_creators.end());
}

template<class T>
std::shared_ptr<T> BaseFactory<T>::create(std::string const & name) const
{
    CreatorMap::const_iterator const creators_it = this->_creators.find(name);
    if (creators_it != this->_creators.end())
    {
        return creators_it->second();
    }
    return nullptr;
}


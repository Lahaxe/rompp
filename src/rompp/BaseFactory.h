#ifndef _BASEFACTORY_H_ 
#define _BASEFACTORY_H_

#include <functional>
#include <map>
#include <memory>
#include <string>

template<class T>
class BaseFactory
{
public:
    BaseFactory();

    virtual ~BaseFactory();

    template<typename TClass>
    void register_();

    bool can_create(std::string const & name) const;

    std::shared_ptr<T> create(std::string const & name) const;

protected:

private:
    typedef std::function<std::shared_ptr<T>()> Creator;

    typedef std::map<std::string, Creator> CreatorMap;

    CreatorMap _creators;

};

#include "BaseFactory.txx"

#endif // _BASEFACTORY_H_


#ifndef _425cf579_c8c3_41ba_b483_7152ecabc0cd
#define _425cf579_c8c3_41ba_b483_7152ecabc0cd

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

#endif // _425cf579_c8c3_41ba_b483_7152ecabc0cd

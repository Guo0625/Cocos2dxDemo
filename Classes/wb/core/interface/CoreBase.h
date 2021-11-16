
#ifndef __CORE_BASE_H__
#define __CORE_BASE_H__

#include <string>

#define VIGAME_BEGIN \
    namespace vigame \
    {
#define VIGAME_END }

VIGAME_BEGIN

class CoreBase
{
public:
    virtual void init() = 0;
    virtual std::string getSignature() = 0;
};

VIGAME_END
#endif //__CORE_BASE_H__
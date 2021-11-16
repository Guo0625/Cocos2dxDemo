
#ifndef __CORE_IOS_H__
#define __CORE_IOS_H__

#include <string>
#include "../interface/CoreBase.h"
#define VIGAME_BEGIN                     namespace vigame {
#define VIGAME_END                       }

VIGAME_BEGIN

class CoreiOS:public CoreBase
{
public:
	CoreiOS();
	~CoreiOS();
    void init() override;
	std::string getSignature() override; 
};

VIGAME_END
#endif //__CORE_IOS_H__
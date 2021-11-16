
#ifndef __CORE_ADDROID_H__
#define __CORE_ADDROID_H__

#include <string>
#include "../interface/CoreBase.h"
#define VIGAME_BEGIN                     namespace vigame {
#define VIGAME_END                       }

VIGAME_BEGIN

class CoreAndroid:public CoreBase
{
public:
	CoreAndroid();
	~CoreAndroid();
    void init() override;
	std::string getSignature() override;
};

VIGAME_END

#endif //__CORE_ADDROID_H__
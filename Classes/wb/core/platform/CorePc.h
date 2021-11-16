
#ifndef __CORE_PC_H__
#define __CORE_PC_H__

#include <string>
#include "../interface/CoreBase.h"
#define VIGAME_BEGIN                     namespace vigame {
#define VIGAME_END                       }

VIGAME_BEGIN

class CorePc:public CoreBase
{
public:
	CorePc();
	~CorePc();
    void init() override;
	std::string getSignature() override; 
};

VIGAME_END
#endif //__CORE_PC_H__
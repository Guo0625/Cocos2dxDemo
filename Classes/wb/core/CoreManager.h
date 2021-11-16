#ifndef __Core_MANAGER_H__
#define __Core_MANAGER_H__

#include <string>
#include <map>
#include <queue>
#include <functional>
#include "interface/CoreBase.h"

#define VIGAME_BEGIN                     namespace vigame {
#define VIGAME_END                       }

VIGAME_BEGIN

class CoreManager
{
public:
	CoreManager();
	~CoreManager();
	static CoreManager* getInstance();
	std::string getSignature();
private:
    CoreBase* mInterface;
};

VIGAME_END

#endif //__Core_MANAGER_H__
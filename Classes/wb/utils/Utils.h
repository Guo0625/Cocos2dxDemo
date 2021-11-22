#ifndef __Utils_H__
#define __Utils_H__

#include <string>

#define VIGAME_BEGIN                     namespace vigame {
#define VIGAME_END                       }

VIGAME_BEGIN

/// 工具类

class Utils
{
public:
	Utils();
	~Utils();
	static Utils* getInstance();

    std::vector<std::string> Split(std::string str, std::string pattern);
};

VIGAME_END

#endif //__Utils_H__
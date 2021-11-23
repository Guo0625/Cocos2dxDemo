#include "cocos2d.h"
#include "Utils.h"

VIGAME_BEGIN

Utils *Utils::getInstance()
{
	static std::unique_ptr<Utils> s_instance;
	static std::once_flag s_instance_created;
	std::call_once(s_instance_created, [=]
				   { s_instance = std::make_unique<Utils>(); });
	return s_instance.get();
}

Utils::Utils()
{
}

Utils::~Utils()
{
}

std::vector<std::string> Utils::Split(std::string str, std::string pattern)
{
    std::vector<std::string> res;
    if(str == "") return res;
    //在字符串末尾也加入分隔符，方便截取最后一段
    std::string strs = str + pattern;
    size_t pos = strs.find(pattern);

    while(pos != strs.npos)
    {
        std::string temp = strs.substr(0, pos);
        res.push_back(temp);
        //去掉已分割的字符串,在剩下的字符串中进行分割
        strs = strs.substr(pos+1, strs.size());
        pos = strs.find(pattern);
    }

    return res;
}

VIGAME_END
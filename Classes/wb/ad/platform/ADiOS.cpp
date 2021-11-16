
#include "ADiOS.h"

VIGAME_BEGIN

ADiOS::ADiOS()
{

}

ADiOS::~ADiOS()
{

}

void ADiOS::init()
{

}

void ADiOS::OpenAd(std::string adName)
{

}

void ADiOS::OpenYsAd(std::string adName, int width, int height, int x, int y)
{

}

void ADiOS::CloseAd(std::string adName)
{

}

bool ADiOS::IsAdReady(std::string adName)
{
	return true;
}

bool ADiOS::IsAdBeOpenInLevel(std::string adName, int level)
{
	return true;
}

std::string ADiOS::GetAdPositionParam(std::string adName, std::string param)
{
	return "";
}

bool ADiOS::IsAdTypeExist(std::string adType)
{
	return true;
}

int ADiOS::GetVideoLimitOpenNum()
{
	return 0;
}

VIGAME_END
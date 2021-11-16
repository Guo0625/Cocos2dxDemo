
#include "ADPc.h"

VIGAME_BEGIN

ADPc::ADPc()
{

}

ADPc::~ADPc()
{

}

void ADPc::init()
{

}

void ADPc::OpenAd(std::string adName)
{

}

void ADPc::OpenYsAd(std::string adName, int width, int height, int x, int y)
{

}

void ADPc::CloseAd(std::string adName)
{

}

bool ADPc::IsAdReady(std::string adName)
{
	return true;
}

bool ADPc::IsAdBeOpenInLevel(std::string adName, int level)
{
	return true;
}

std::string ADPc::GetAdPositionParam(std::string adName, std::string param)
{
	return "";
}

bool ADPc::IsAdTypeExist(std::string adType)
{
	return true;
}

int ADPc::GetVideoLimitOpenNum()
{
	return 0;
}

VIGAME_END
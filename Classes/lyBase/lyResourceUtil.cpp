//
//  lyResourceUtil.cpp
//  ly-client
//  UI控件基类
//  Created by loveyur on 2016/11/11
//


#include "lyResourceUtil.h"
#include "PlatformUtils.h"

std::vector<std::string> lyResourceUtil::getResourceSearchPaths()
{
    std::vector<std::string> searchPath;
    searchPath.push_back("Published-iOS");
    searchPath.push_back("res");
    searchPath.push_back("ui");
    searchPath.push_back("images");
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    searchPath.push_back("sounds/ios");
#else
    searchPath.push_back("sounds/android");
#endif
    /*
    std::string resourcePath = PlatformUtils::getDownloadResourcePath();
    std::string mainPath = resourcePath + std::string("res/");
    searchPath.push_back(mainPath.c_str());
    std::string tutorialPath = resourcePath + std::string("Published-iOS/");
    searchPath.push_back(tutorialPath.c_str());
*/
    
    return searchPath;
    
}
std::vector<std::string> lyResourceUtil::getResourceResolutionOrder()
{
    std::vector<std::string> resolutionsOrder;
    
    resolutionsOrder.push_back("resources-ipad/");
    resolutionsOrder.push_back("resources-ipadhd/");
    resolutionsOrder.push_back("resources-iphone/");
    resolutionsOrder.push_back("resources-iphonehd/");
    
    return resolutionsOrder;
}

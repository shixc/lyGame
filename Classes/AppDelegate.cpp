#include "AppDelegate.h"
#include "HelloWorldScene.h"

//add byshixc test
#include "CCBCustomClassLoaderLibrary.h"
#include "VitaminSceneManager.h"
#include "ApplicationManager.h"
#include "lyResourceUtil.h"
#include "testLayer.h"

//#include "PlatformUtils.h"

USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,  
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("ly", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
        glview = GLViewImpl::create("ly");
#endif
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0f / 60);
    // Set the design resolution
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
    auto frameSize = glview->getFrameSize();
    // if the frame's height is larger than the height of medium size.
    if (frameSize.height > mediumResolutionSize.height)
    {
        director->setContentScaleFactor(MIN(largeResolutionSize.height/designResolutionSize.height, largeResolutionSize.width/designResolutionSize.width));
    }
    // if the frame's height is larger than the height of small size.
    else if (frameSize.height > smallResolutionSize.height)
    {
        director->setContentScaleFactor(MIN(mediumResolutionSize.height/designResolutionSize.height, mediumResolutionSize.width/designResolutionSize.width));
    }
    // if the frame's height is smaller than the height of medium size.
    else
    {
        director->setContentScaleFactor(MIN(smallResolutionSize.height/designResolutionSize.height, smallResolutionSize.width/designResolutionSize.width));
    }

    bool isTest = true;
    if (isTest)
    {
        FileUtils::getInstance()->setSearchPaths(lyResourceUtil::getResourceSearchPaths());
        FileUtils::getInstance()->setSearchResolutionsOrder(lyResourceUtil::getResourceResolutionOrder());
        /*
        char fullPath[1024] = {};
        std::string resourcePath = PlatformUtils::getDownloadResourcePath();
        PlatformUtils::createDirectoryByFullPath(resourcePath.c_str());
        sprintf(fullPath, "%s%s", resourcePath.c_str(), "res/");
        PlatformUtils::createDirectoryByFullPath(fullPath);
        sprintf(fullPath, "%s%s", resourcePath.c_str(), "ui/");
        PlatformUtils::createDirectoryByFullPath(fullPath);
        sprintf(fullPath, "%s%s", resourcePath.c_str(), "images/");
        PlatformUtils::createDirectoryByFullPath(fullPath);
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        PlatformUtils::addDoNotBackupAttribute(resourcePath.c_str());
#endif
        / *
        std::string cachePath = PlatformUtils::getCachePath();
        PlatformUtils::createDirectoryByFullPath(cachePath.c_str());
        sprintf(fullPath, "%s%s", cachePath.c_str(), "res/");
        PlatformUtils::createDirectoryByFullPath(fullPath);
        sprintf(fullPath, "%s%s", cachePath.c_str(), "ui/");
        PlatformUtils::createDirectoryByFullPath(fullPath);
        */
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        //moveDownloadedResources();
#endif
        ApplicationManager::getInstance()->preloadImages();
        
        CCBCustomClassLoaderLibrary::getInstance()->registerCustomClassLoader();
        VitaminSceneManager* sceneMgr = new VitaminSceneManager;
        ApplicationManager::getInstance()->setSceneManager(sceneMgr);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        //sceneMgr->_isFade = false;
#endif
        //ApplicationManager::getInstance()->runWithScene(SCENE_LOGIN);
        ApplicationManager::getInstance()->runWithScene(SCENE_TEST_SCENE);
        //ApplicationManager::getInstance()->runWithScene(SCENE_LOGIN_TEST);
        
        //director->runWithScene(testLayer::create());
    }
    else
    {
        
        register_all_packages();

        auto scene = HelloWorld::createScene();
        director->runWithScene(scene);
    }
    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
    
    ApplicationManager::getInstance()->pause();
    // if you use SimpleAudioEngine, it must be paused
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
    
    ApplicationManager::getInstance()->resume();
    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

void AppDelegate::moveDownloadedResources()
{

}

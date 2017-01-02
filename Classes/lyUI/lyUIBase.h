/***************************************************************
*	lyUIBase
*	by Shixc 2014-04-10
***************************************************************/
#ifndef __lyGame__lyUIBase__
#define __lyGame__lyUIBase__



#include "lyInclude.h"
#include "lyCocosNode.h"


USING_NS_CC;

#define CTRL_NAME_SIZE 16

#define TEST_COLLISION
#ifdef TEST_COLLISION
extern bool gShowTestCollition;
#endif

class lyUIBase :
public lyCocosNode
{
public:
	lyUIBase();
	virtual ~lyUIBase();

	static lyUIBase* Create();
    //CREATE_FUNC_POOL(lyUIBase);
    bool init();

    virtual void onEnter() override;
    virtual void onExit() override;
    virtual void update(float delta) override;
    virtual void visit(Renderer *renderer, const Mat4 &parentTransform, uint32_t parentFlags) override;
    virtual void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) override;
    
    
	void SetCtrlName(const char* strCtrlName);
	long GetObjID();
    
    
    Touch convertToCurWinCoordinateOnlyGL(Node* desWin, Touch* parTouch);    //将坐标系从父坐标系，转换为自身的坐标系(备注：只通过openGL坐标系，不使用屏幕坐标系)
    bool isTouched(Node* desWin, Touch* pTouch);

protected:

	bool    m_bIsCtrlVisible;
	bool    m_bIsTouched;
	bool    m_bCtrlEnable;
	bool    m_bAdjustCtrlSpr;
	char	m_szCtrlName[CTRL_NAME_SIZE];


};


#endif //__lyGame__lyUIBase__

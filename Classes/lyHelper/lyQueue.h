#ifndef _lyQueue_H_
#define _lyQueue_H_


/*** ***
	队列基类
	先进先出
	by Shixc 2014-01-28

*** ***/

template<class T, int maxNum>
class lyQueue
{
public:
	lyQueue()
	{
		_ulIndexHead	= 0;
		_ulIndexEnd		= 0;
		_ulCurrNum		= 0;
		_ulMaxNum		= maxNum;
	}
	~lyQueue()
	{

	}
	inline void Push(const T &value)
	{
		if (IsFull())
		{
			CCLOG("【ERROR】lyQueue is Full£°");
			return;
		}
		if(0 == _ulMaxNum)
		{
			return;
		}
		_pQueue[_ulIndexEnd] = value;
		_ulIndexEnd = (_ulIndexEnd+1)%(_ulMaxNum);
		++_ulCurrNum;
	}
	inline void Pop()
	{
		_ulIndexHead = (_ulIndexHead+1)%(_ulMaxNum);
		--_ulCurrNum;
	}
	inline T* GetHeader()
	{
		if (IsEmpty())
		{
			return NULL;
		}
		return &_pQueue[_ulIndexHead];
	}
	inline bool IsFull()
	{
		return _ulCurrNum == _ulMaxNum;
	}
	inline bool IsEmpty()
	{
		return _ulCurrNum > 0 ? false : true;
	}
	inline Clear()
	{
		_ulIndexHead	= 0;
		_ulIndexEnd		= 0;
		_ulCurrNum		= 0;
		_ulMaxNum		= maxNum;
	}
protected:
	T				_pQueue[maxNum];
	unsigned long	_ulIndexHead;
	unsigned long	_ulIndexEnd;
	unsigned long	_ulCurrNum;
	unsigned long	_ulMaxNum;
	
};



#endif  //_lyQueue_H_

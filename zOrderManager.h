#pragma once
#include "singletonBase.h"
#include <vector>
struct tagZOrder{

};

class gameNode;
class zOrderManager : public singletonBase<zOrderManager>
{
	vector<gameNode*> _vGameNode;
	vector<gameNode*>::iterator _viGameNode;

	vector<int> _vY;
	vector<int>::iterator _viY;
public:
	zOrderManager();
	~zOrderManager();

	HRESULT init();
	void update();
	void release();
					//�׸� Ŭ����		,���� y��(���� ���� ��Ʈ�� bottom)
	void addZOrder(gameNode* tempGameNode,int y);
	void sortY( int start, int num);	//����
	int partition(int start, int end);
	void allClear() { _vGameNode.clear(); _vY.clear(); }
	//void zOrderUpdate();
	//�׷���
	void paintZOrder();
};


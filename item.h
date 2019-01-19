#pragma once
#include "gameNode.h"

enum tagItemType{
	POTION,		//���� �Ҹ�ǰ
	THROW,		//��ô �Ҹ�ǰ(�� object)
	MONEY,		//��
};
enum tagItemState{
	DROP,		//������ �ִ� ����	
	THROWING	//�������� �ִ� ����
};
class item :
	public gameNode
{
protected:
	image* _itemImage;			//������ �̹���
	RECT _rcItem;
	float _x, _y;				//������ ������ǥ
	float _endY;				//���������� ������ y��ǥ
	tagItemType	_itemType;		//������ ����
	tagItemState _itemState;	//������ ����
	int _itemEffect;			//������ ȿ��(��ô -> ������ & ���� -> ȸ�� & ��->ȹ�淮)
	int _price;					//������ ����
	int _count;					//����ִ� ����

	int _frameX;				//���� ������X
	int _frameCount;			//������ ī��Ʈ����

	float _throwPower;
	bool _isRight;

public:
	item();
	~item();

	//��ǥ�� �ʿ���� ���������� �ʱ�ȭ
	virtual HRESULT init();
	//��ǥ�� �ʿ��� ������Ʈ �ʱ�ȭ
	virtual HRESULT init(POINT point);
	//��ǥ�� �ʿ��ϰ� ���͸��� ����ϴ� ���� �ٸ��� �ϱ� ���� �ʱ�ȭ
	virtual HRESULT init(POINT point, int money);
	virtual void release();
	virtual void update();
	virtual void render();

	//��ô������ �̵�
	virtual void move() {}

	//������ ��ǥ ���� (��ô�� ���)
	void setPoint(POINT point){ _x = point.x; _y = point.y; }		
	RECT getItemRC() { return _rcItem; }
	//������ǥ RC
	RECT getAbsoluteRC(){ return RectMakeCenter(_x, _y, _itemImage->getFrameWidth(), _itemImage->getFrameHeight()); }

	//������ ȿ�� ��������(��ô������ : ������, ���� : ȸ����)
	int getItemEffect(){return _itemEffect;}

	//���� �̹����� �̰� ���� �׸��� ��
	image*	getItemImage(){ return _itemImage; }

	//���� ���� ���� ���� �� ��������(���� �μ��� = -1)
	void setCount(int count) { _count = count; }
	int getCount(){ return _count; }

	//���� ��������
	int getPrice(){ return _price; }

	//������ ���� ����
	void setState(bool isThrow){ if (isThrow)_itemState = THROWING; else _itemState = DROP; }
	//������ ����(0 ���, 1 ������)
	int getState(){ return _itemState; }

	//������ Ÿ�� ����(0 ����, 1 ������Ʈ, 2 ��)
	int getItemType(){ return _itemType; }

	float getX() { return _x; }
	float getY() { return _y; }
	void setX(float x) { _x = x; }
	void setY(float y) { _y = y; }
	void setEndY(float endY){ _endY = endY; }
	void setThrowPower(float throwPower){ _throwPower = throwPower; }
	void setIsRight(bool isRight){ _isRight = isRight; }
};


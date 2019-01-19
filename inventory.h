#pragma once
#include "gameNode.h"
#include "orangePotion.h"
#include "redPotion.h"
#include "whitePotion.h"

class character;

class inventory:public gameNode
{
private:
	image* _blackWindowBmp;							// ���ȭ�� ����� ���� ������ ������ â
	image* _inventoryBmp;							// �κ��丮 �̹���
	image* _shopBmp;								// ���� �̹���
	image* _selectBoxBmp;							// ���� �ڽ�

	image* _RNumberBmp;								// �������� ���� �̹���
	image* _ONumberBmp;								// ��Ȳ���� ���� �̹���
	image* _WNumberBmp;								// �Ͼ������ ���� �̹���

	POINT _selectShopPos[2][3];						// �������� ���ùڽ� ������ �� ��ǥ
	POINT _selectInvenPos[3];						// �κ��丮���� ���ùڽ� ������ �� ��ǥ
	
	int _currentMoney;								// ���� ���� ��
	int _currentSelectX;							// 0�϶� ���� 1�϶� �κ�
	int _currentSelectY;							// ������ġ

	int _quickCount;								// �����Կ� �� ������ ����
	int _quickPotion;								// ���� �����Կ� ��ġ�� ��������Ʈ
													// ��Ȳ������ ������ ����Ʈ = 3
													// �������� 5;
													// ���������� 1;
	bool _openShop;
	bool _openInventory;

	redPotion* _RPotion;
	orangePotion* _OPotion;
	whitePotion* _WPotion;

	character* _mainPlayer;

public:
	inventory();
	~inventory();

	HRESULT init();
	void release();
	void update();
	void render();

	void shopState();								//����
	void inventoryState();							//�� �κ��丮

	void openShop() { _openShop = true; }			// ��������
	void openInventory() { _openInventory = true; }	// �κ��丮����
	void closeShop() { _openShop = false; }
	void closeInventory() { _openInventory = false; }

	bool getOpenShop() { return _openShop; }
	bool getOpenInventory() { return _openInventory; }

	int getQuickCount() { return _quickCount; }
	int getQuickPotion() { return _quickPotion; }

	void setCurrentMoney(int currentMoney){ _currentMoney += currentMoney; }

	void setMainPlayerMemoryLink(character* mainPlayer){ _mainPlayer = mainPlayer; }
};


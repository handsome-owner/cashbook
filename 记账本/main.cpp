#include "common.h"
#include "account_item.h"

int main() 
{
	// ��������:
	vector<AccountItem> items;
	loadDataFromFile(items);

	bool quit = false;
	// 	ѭ�� �ȴ��û�������
	while (!quit) {
		// ��ʾ���˵�
		showMainMenu();

		// ��ȡ�û�����
		char option = readMenuSelection(3);
		switch (option) {
		case '1':
			// ����
			showAccountingMenu();
			accounting(items);
			break;
		case '2':
			// ��ѯ
			showQueryMenu();
			query(items);
			break;
		case '3':
			// �˳�
			cout << "ȷ��Ҫ�˳���(Y/N) \n";
			if (readQuitConfirm() == 'Y') {
				quit = true;
			}
			break;
		default:
			break;
		}
		cout << endl;
	}
}
#include "common.h"
#include "account_item.h"

int main() 
{
	// 加载数据:
	vector<AccountItem> items;
	loadDataFromFile(items);

	bool quit = false;
	// 	循环 等待用户操作：
	while (!quit) {
		// 显示主菜单
		showMainMenu();

		// 获取用户输入
		char option = readMenuSelection(3);
		switch (option) {
		case '1':
			// 记账
			showAccountingMenu();
			accounting(items);
			break;
		case '2':
			// 查询
			showQueryMenu();
			query(items);
			break;
		case '3':
			// 退出
			cout << "确定要退出吗？(Y/N) \n";
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
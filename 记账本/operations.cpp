#include "account_item.h"

//针对账目的所有操作函数（比如记账、查询）


// 打印输出一条账目
void printAccountItem(const AccountItem& item) {
	cout << item.itemType << "\t" << item.account << "\t" << item.detail << endl;
}

// 针对账目AccountItem的操作函数
void loadDataFromFile(vector<AccountItem>& items) {
	ifstream input(FILENAME);
	// 逐行读取内容：
	AccountItem item;
	while (input >> item.itemType && input >> item.account && input >> item.detail) {
		items.push_back(item);
	}
	input.close();
}


void insertItemIntoFile(const AccountItem& item) {
	// ios::out | ios::app：这部分是打开文件的模式参数  
	// ios::out 表示以输出模式打开文件，ios::app 表示以追加模式打开文件，即如果文件存在，写入的内容将被追加到文件末尾。
	ofstream output(FILENAME,ios::out | ios::app);

	output << item.itemType << "\t" << item.account << "\t" << item.detail << endl;

	output.close();
}

// 记账
// 记账分为收入和支出 需要根据用户输入进行选择
void accounting(vector<AccountItem>& items) {
	char option = readMenuSelection(3);
	switch (option) {
	case '1':
		income(items);
		break;
	case '2':
		expand(items);
		break;
	default:
		break;
	}
}

// 收入
void income(vector<AccountItem>& items) {
	AccountItem item;
	item.itemType = INCOME;
	cout << "请输入收入金额：" << endl;
	item.account = readAmount();
	cout << "请输入收入备注" << endl;
	getline(cin, item.detail);
	// 将当前内容放入到内存中
	items.push_back(item);
	// 保存记录到文件中：
	insertItemIntoFile(item);
	cout << "记账成功！！" << endl;
}

// 支出
void expand(vector<AccountItem>& items) {
	AccountItem item;
	item.itemType = EXPAND;
	cout << "请输入支出金额：" << endl;
	item.account = readAmount();
	cout << "请输入支出备注" << endl;
	getline(cin, item.detail);
	// 将当前内容放入到内存中
	items.push_back(item);
	// 保存记录到文件中：
	insertItemIntoFile(item);
	cout << "记账成功！！" << endl;
}

// 查询
// 查询所有 查询收入 查询支出 
void query(vector<AccountItem>& items) {
	char option = readMenuSelection(4);
	switch (option) {
	case '1':
		queryItems(items);
		break;
	case '2':
		queryItems(items,INCOME);
		break;
	case '3':
		queryItems(items,EXPAND);
		break;
	default:
		break;
	}
}


void queryItems(vector<AccountItem>& items) {
	cout << "|===============   所有账目   ====================|" << endl;
	cout << "类型\t金额\t备注" << endl;
	int total = 0;
	for (AccountItem item : items) {
		printAccountItem(item);
		if (item.itemType == EXPAND) {
			total -= abs(item.account);
		}
		else {
			total += abs(item.account);
		}
	}
	cout << "总计: \t" << total <<endl;

	cout << "\n请按回车返回主菜单..." << endl;
	string line;
	getline(cin, line);
}

void queryItems(vector<AccountItem>& items, const string accoutType) {
	cout << "|===============   查询结果   ====================|" << endl;
	cout << "类型\t金额\t备注" << endl;
	int total = 0;
	for (AccountItem item : items) {
		if (item.itemType != accoutType) {
			continue;
		}
		printAccountItem(item);
		if (item.itemType == EXPAND) {
			total -= abs(item.account);
		}
		else {
			total += abs(item.account);
		}
	}
	cout << (accoutType == INCOME ? "总收入：\t" : "总支出：\t") << total << endl;

	cout << "\n请按回车返回主菜单..." << endl;
	string line;
	getline(cin, line);
}
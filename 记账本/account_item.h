#pragma once

#include "common.h"

struct AccountItem {
	string itemType;
	int account;
	string detail;
};


// 打印输出一条账目
void printAccountItem(const AccountItem& item);

// 针对账目AccountItem的操作函数
void loadDataFromFile(vector<AccountItem>& items);
void insertItemIntoFile(const AccountItem& item);

// 记账
void accounting(vector<AccountItem>& items);
void income(vector<AccountItem>& items);
void expand(vector<AccountItem>& items);

// 查询
void query(vector<AccountItem>& items);
void queryItems(vector<AccountItem>& items);
void queryItems(vector<AccountItem>& items, const string accoutType);
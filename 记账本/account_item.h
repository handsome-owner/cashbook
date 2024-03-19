#pragma once

#include "common.h"

struct AccountItem {
	string itemType;
	int account;
	string detail;
};


// ��ӡ���һ����Ŀ
void printAccountItem(const AccountItem& item);

// �����ĿAccountItem�Ĳ�������
void loadDataFromFile(vector<AccountItem>& items);
void insertItemIntoFile(const AccountItem& item);

// ����
void accounting(vector<AccountItem>& items);
void income(vector<AccountItem>& items);
void expand(vector<AccountItem>& items);

// ��ѯ
void query(vector<AccountItem>& items);
void queryItems(vector<AccountItem>& items);
void queryItems(vector<AccountItem>& items, const string accoutType);
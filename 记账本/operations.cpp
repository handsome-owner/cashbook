#include "account_item.h"

//�����Ŀ�����в���������������ˡ���ѯ��


// ��ӡ���һ����Ŀ
void printAccountItem(const AccountItem& item) {
	cout << item.itemType << "\t" << item.account << "\t" << item.detail << endl;
}

// �����ĿAccountItem�Ĳ�������
void loadDataFromFile(vector<AccountItem>& items) {
	ifstream input(FILENAME);
	// ���ж�ȡ���ݣ�
	AccountItem item;
	while (input >> item.itemType && input >> item.account && input >> item.detail) {
		items.push_back(item);
	}
	input.close();
}


void insertItemIntoFile(const AccountItem& item) {
	// ios::out | ios::app���ⲿ���Ǵ��ļ���ģʽ����  
	// ios::out ��ʾ�����ģʽ���ļ���ios::app ��ʾ��׷��ģʽ���ļ���������ļ����ڣ�д������ݽ���׷�ӵ��ļ�ĩβ��
	ofstream output(FILENAME,ios::out | ios::app);

	output << item.itemType << "\t" << item.account << "\t" << item.detail << endl;

	output.close();
}

// ����
// ���˷�Ϊ�����֧�� ��Ҫ�����û��������ѡ��
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

// ����
void income(vector<AccountItem>& items) {
	AccountItem item;
	item.itemType = INCOME;
	cout << "�����������" << endl;
	item.account = readAmount();
	cout << "���������뱸ע" << endl;
	getline(cin, item.detail);
	// ����ǰ���ݷ��뵽�ڴ���
	items.push_back(item);
	// �����¼���ļ��У�
	insertItemIntoFile(item);
	cout << "���˳ɹ�����" << endl;
}

// ֧��
void expand(vector<AccountItem>& items) {
	AccountItem item;
	item.itemType = EXPAND;
	cout << "������֧����" << endl;
	item.account = readAmount();
	cout << "������֧����ע" << endl;
	getline(cin, item.detail);
	// ����ǰ���ݷ��뵽�ڴ���
	items.push_back(item);
	// �����¼���ļ��У�
	insertItemIntoFile(item);
	cout << "���˳ɹ�����" << endl;
}

// ��ѯ
// ��ѯ���� ��ѯ���� ��ѯ֧�� 
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
	cout << "|===============   ������Ŀ   ====================|" << endl;
	cout << "����\t���\t��ע" << endl;
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
	cout << "�ܼ�: \t" << total <<endl;

	cout << "\n�밴�س��������˵�..." << endl;
	string line;
	getline(cin, line);
}

void queryItems(vector<AccountItem>& items, const string accoutType) {
	cout << "|===============   ��ѯ���   ====================|" << endl;
	cout << "����\t���\t��ע" << endl;
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
	cout << (accoutType == INCOME ? "�����룺\t" : "��֧����\t") << total << endl;

	cout << "\n�밴�س��������˵�..." << endl;
	string line;
	getline(cin, line);
}
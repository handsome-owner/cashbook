#include "common.h"

// ͨ�ú����������ȡ�������룩


// ��ȡ�û����������� ������Ӧ��char����
char readMenuSelection(int options) {
	string str;
	while (true) {
		getline(cin,str);
		if (str.size() > 1 || str[0] - '0' < 0 || str[0] - '0' > options) {
			cout << "�����ѡ����������������" << endl;
		}
		else {
			return str[0];
		}
	}

}

// ��ȡ��������Ľ����  �ڴ˴�ȫ��ʹ������
int readAmount() {
	int account;
	string str;
	while (true) {
		getline(cin, str);
		// ����ת��
		try {
			return stoi(str);
		}
		catch (invalid_argument e) {
			cout << "��������ȷ������" << endl;
		}
	}
}


// ��ȡ�˳��ַ� �����û���������
char readQuitConfirm() {
	char flag;
	string str;
	while (true) {
		getline(cin, str);
		if (str.empty()) {
			continue;
		}
		flag = toupper(str[0]);
		if (flag != 'Y' && flag != 'N'){
			cout << "�������ȷ��ѡ�� Y/N" << endl;
		}
		else {
			return flag;
		}
	}
}



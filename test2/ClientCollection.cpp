#include "ClientCollection.h"

void ClientCollection::signUp_deleteClient(Client currentUser, ClientCollection ClientCollect) {
	int command = 0;

	//Client *CurrentUser = new Client(1, "guest");


	cout << "1. ȸ�� ����" << endl;
	cout << "2. ȸ�� Ż��" << endl;
	cout << "0. ���� �޴��� ���ư���" << endl;
	cout << "* �Է� ���� : ";
	cin >> command;

	switch (command) {
	case 1:
		cout << "1. ȸ�� ����." << endl;
		//		ClientCollect.signUp(currentUser, ClientCollect);
		//	ClientCollect.PrintAll(currentUser);
		ClientCollect.signUp(currentUser);
		//	ClientCollect.PrintAll(totalClient[0]);
		break;

	case 2:
		cout << "2. ȸ�� Ż��." << endl;
		//			ClientCollect.PrintAll(totalClient[0]);
		//			if (1 == ClientCollect.deleteClient(currentUser)) { cout << "Ż�� �Ϸ�" << endl; }
		//			else { cout << "Ż��ȵ�" << endl; }
		//			ClientCollect.PrintAll(totalClient[0]);
		break;

	case 0:
		cout << "���� �޴��� ���ư��ϴ�." << endl;
		break;

	default:
		cout << "�˸��� �ʴ� ��ȣ�Դϴ�";
		break;
	}

}


void ClientCollection::signUp(Client currentUser) {

	string str = "";
	int newMember = 0;
	for (; n[newMember] != 0; newMember++);

	cout << "name �Է� : ";
	cin >> str;
	totalClient[newMember].setName(str);
	currentUser.setName(str);


	cout << "address �Է� : ";
	cin >> str;
	totalClient[newMember].setAddress(str);
	currentUser.setAddress(str);

	cout << "email �Է� : ";
	cin >> str;
	totalClient[newMember].setEmail(str);
	currentUser.setEmail(str);

	cout << "id �Է� : ";
	cin >> str;
	totalClient[newMember].setId(str);
	currentUser.setId(str);

	cout << "password �Է� : ";
	cin >> str;
	totalClient[newMember].setPassword(str);
	currentUser.setPassword(str);

	n[newMember] = true;

	//totalClient[newMember].setPrivateNumber(newMember);
	//currentUser.setPrivateNumber(newMember);

}
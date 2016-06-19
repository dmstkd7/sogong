#include "ClientCollection.h"


extern ClientCollection ClientCollect;

void ClientCollection::setTotalClient(int inputNum, Client newItem) {
	totalClient[inputNum] = newItem;
}


// ȸ�� ���԰� ȸ�� Ż�� �� �����ϴ� â�Դϴ�.
void ClientCollection::signUp_deleteClient() {
	int command = 0;

	cout << "1. ȸ�� ����" << endl;
	cout << "2. ȸ�� Ż��" << endl;
	cout << "0. ���� �޴��� ���ư���" << endl;

	cout << "* �Է� ���� : ";
	cin >> command;
	cin.clear();
	cin.ignore(256, '\n');

	switch (command) {
	case 1:
		cout << "************** ȸ������ �Ϸ� ���̱��� �ݰ����ϴ� **************" << endl;
		if (CurrentUser.getId() != "!!!"){ cout << "�α׾ƿ� �� ������ �����մϴ�." << endl; }
		else {
			ClientCollect.signUp();
			cout << "ȸ�� ������ �Ϸ�Ǿ����ϴ�." << endl;


		}
		break;

	case 2:
		cout << "************** ȸ��Ż�� �Ϸ� ���̱��� �ݰ����ϴ� **************" << endl;
		// CurrentUser���� Ż�� �����ϴ�
		if (CurrentUser.getId() == "!!!") {
			cout << "�α��� �� Ż�� �����մϴ�." << endl;
		}
		else{
			if (ClientCollect.deleteClient(CurrentUser) == true) { cout << "Ż�� �Ϸ�Ǿ����ϴ�." << endl; }

			else { cout << "Ż�� ��ҵǾ����ϴ�." << endl; }
		}

		break;

	case 0:
		cout << "���� �޴��� ���ư��ϴ�." << endl;
		return;
		break;

	default:
		cout << "�߸��� ���� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���";
		break;
	}

}

//ȸ�� ������ �ϴ� â�Դϴ�.
void ClientCollection::signUp() {
	string str;
	Client newClient;

	int checkNum = 0;
	int newMember = 0;
	for (; totalClient[newMember].getId() != "!!!"; newMember++);

	cout << "name �Է� : ";
	for (; totalClient[newMember].getId() != "!!!"; newMember++);

	try {
		cout << "name �Է�(15�� ���� ����) : ";
		cin >> str;
		cin.clear();
		cin.ignore(256, '\n');
		if (str.length() > 15) throw 1;
		newClient.setName(str);//�� ��° ���� Name�� ������ ������ ���ϴ� �Լ��Դϴ�

		cout << "address �Է�(30�� ���� ����) : ";
		cin >> str;
		cin.clear();
		cin.ignore(256, '\n');
		if (str.length() > 30) throw 2;
		newClient.setAddress(str);

		cout << "email �Է�(30�� ���� ����)  : ";
		cin >> str;
		cin.clear();
		cin.ignore(256, '\n');
		if (str.length() > 30) throw 3;
		newClient.setEmail(str);

		cout << "id �Է�(15�� ���� ����)  : ";
		cin >> str;
		cin.clear();
		cin.ignore(256, '\n');
		if (str.length() > 15) throw 4;

		while (checkNum < 10) {
			if (totalClient[checkNum].getId() == str)
				 break;
			checkNum++;
			
		}
		
			if (checkNum != 10) {
			cout << "�ߺ��� id�� �ֽ��ϴ�." << endl;
			return;
			
		}
			// �ߺ��� id�� ���� ��� ȸ�������� ����˴ϴ�.





		newClient.setId(str);




		cout << "password �Է�(20�� ���� ����)  : ";
		cin >> str;
		cin.clear();
		cin.ignore(256, '\n');
		if (str.length() > 20) throw 5;
		newClient.setPassword(str);

		newClient.setPrivateNumber(newMember);

		//�Է� ���� ������ Collection�� client�� �����ϴ� �Լ��Դϴ�.
		ClientCollect.setTotalClient(newMember, newClient);

		cout << "ȸ�� ������ �Ϸ�Ǿ����ϴ�." << endl;
	}

	catch (int type) {
		switch (type)
		{
		case 1:
			cout << "name�� 15�ڸ� �Ѿ �� �����ϴ�." << endl;
			break;
		case 2:
			cout << "address�� 30�ڸ� �Ѿ �� �����ϴ�." << endl;
			break;
		case 3:
			cout << "email�� 30�ڸ� �Ѿ �� �����ϴ�." << endl;
			break;
		case 4:
			cout << "id�� 15�ڸ� �Ѿ �� �����ϴ�." << endl;
			break;
		case 5:
			cout << "password�� 20�ڸ� �Ѿ �� �����ϴ�." << endl;
			break;
		default:
			break;
		}

	}
	return;
}


//ȸ�� Ż�� �ϴ� â�Դϴ�.
// CurrentUser���� Ż�� �����ϴ�
bool ClientCollection::deleteClient(Client wantDeleteClient) {
	int checkNum = 0;
	string inputId;
	string inputPassword;

	cout << "id�� �Է��ϼ��� : ";
	cin >> inputId;
	cin.clear();
	cin.ignore(256, '\n');

	if (wantDeleteClient.getId() != inputId) {
		cout << "id�� ��ġ���� �ʽ��ϴ�." << endl;
		return false;
	}

	// ��ġ�ϴ� ID�� Ȯ���� Password�� �Է¹޴´�.
	else {
		cout << "PW�� �Է��ϼ��� : ";
		cin >> inputPassword;
		cin.clear();
		cin.ignore(256, '\n');

		// ��ġ�ϴ� ID�� �´� Password�� Ȯ���Ѵ�.
		// ID�� PW�� �ùٸ� ��� Ż�� ���θ� Ȯ���Ѵ�.
		if (wantDeleteClient.getPassword() != inputPassword) {
			cout << "PW�� ��ġ���� �ʽ��ϴ�. " << endl;
			return false;
		}
		else {
			int deleteCheck;
			cout << "Ż���Ͻðڽ��ϱ�? Y (1) /N (0)  : ";
			cin >> deleteCheck;
			cin.clear();
			cin.ignore(256, '\n');

			//Y �� �����ϴ� ��� CliectCollection���� ȸ���� ������ ���� ��Ų��.
			// ���� ������� ������ ��� �����Ѵ�.
			if (deleteCheck == 1) {
				int a;
				a = wantDeleteClient.getPrivateNumber();

				totalClient[a].setSession(1);
				totalClient[a].setName("guest");
				totalClient[a].setPrivateNumber(-1);
				totalClient[a].setAddress("");
				totalClient[a].setEmail("");
				totalClient[a].setId("!!!");
				totalClient[a].setPassword("");

				CurrentUser.setSession(1);
				CurrentUser.setName("guest");
				CurrentUser.setPrivateNumber(-1);
				CurrentUser.setAddress("");
				CurrentUser.setEmail("");
				CurrentUser.setId("!!!");
				CurrentUser.setPassword("");

				return true;
			}
			else
				return false;
		}
	}

}



/*======================== �� �� ��   �� �� �� ��======================*/



// �α��ΰ� �α׾ƿ� �� �����ϴ� â�Դϴ�.
void ClientCollection::Login_Logout() {
	int command = 0;

	//Client *CurrentUser = new Client(1, "guest");


	cout << "1. �α���" << endl;
	cout << "2. �α׾ƿ�" << endl;
	cout << "0. ���� �޴��� ���ư���" << endl;

	cout << "* �Է� ���� : ";
	cin >> command;
	cin.clear();
	cin.ignore(256, '\n');

	//�α����� �Ǿ� �ִ��� ������ Ȯ�����ִ� �����Դϴ�.
	// �α��� �������� ID�� !!�� �ƴϾ� 
	//		-> �α��� �Ұ���
	//  !!!�̸� �α��� ����
	bool loginCheck = false;

	loginCheck = (CurrentUser.getId() == "!!!");


	switch (command) {
	case 1:
		//if (loginCheck && ClientCollect.Login(CurrentUser)) { cout << "�α��� ����" << endl; }
		cout << "************** �α��� �Ϸ� ���̱��� �ݰ����ϴ� **************" << endl;

		//else { cout << "�α��� �Ǿ��ִ�." << endl; }

		if (loginCheck == true){

			if (ClientCollect.Login() == true) {
				cout << "�α��� ����" << endl;
			}
			else {
				cout << "�α��� ����" << endl;
			}
		}
		else { cout << "�̹� �α��� ���� �Դϴ�!!" << endl; }
		break;

	case 2:
		cout << "************** �α׾ƿ� �Ϸ� ���̱��� **************" << endl;

		if (loginCheck == false) {
			if (ClientCollect.Logout() == true) {
				cout << "�α׾ƿ� �Ϸ�" << endl;
			}
			else
				cout << "�α׾ƿ� ���" << endl;
		}
		else
			cout << "�α׾ƿ��� �Ұ��� �մϴ�.  �α����� ���� ���ּ���!!!" << endl;


		//if (isLogin && ClientCollect.Login(CurrentUser) ) { cout << "�α׾ƿ��� �Ұ��� �մϴ�." << endl; }
		//if else  (isLogin && ClientCollect.Logout(CurrentUser)) { cout << "�α׾ƿ� ����" << endl; }

		//else { cout << "�α׾ƿ� ���" << endl; }


		break;

	case 0:
		cout << "���� �޴��� ���ư��ϴ�." << endl;
		return;
		break;

	default:
		cout << "�˸��� �ʴ� ��ȣ�Դϴ�";
		break;
	}

}


//CurrentUser�� ���¸� �޾Ƽ� �α����� �Ǿ��ٸ�
//CurrentUser�� id, session ����� �α��ε� ������ �ٲ۴�

bool ClientCollection::Login(){//Client loginUser) {
	int checkNum = 0;
	string inputId;
	string inputPassword;

	cout << "id�� �Է��ϼ��� : ";
	cin >> inputId;
	cin.clear();
	cin.ignore(256, '\n');


	//��ġ�ϴ°� ���������� while���� ��� ������ ���� ��ġ�ϴ°� ������ checkNum�� ������ ü �������´�
	while (checkNum < 10) {
		if (totalClient[checkNum].getId() == inputId)
			break;
		checkNum++;
	}

	if (checkNum == 10) {
		cout << "��ġ�ϴ� ���̵� �����ϴ�." << endl;
		return false;
	}

	cout << "PW�� �Է��ϼ��� : ";
	cin >> inputPassword;
	cin.clear();
	cin.ignore(256, '\n');

	if (totalClient[checkNum].getPassword() == inputPassword) {
		//ID�� Password�� ��ġ�Ѵٸ� CurrentUser�� ������ set�Ѵ�.
		CurrentUser.setSession(2);	//	session�� ����ڷ� �����Ѵ�.
		CurrentUser.setName(totalClient[checkNum].getName());
		CurrentUser.setPrivateNumber(totalClient[checkNum].getPrivateNumber());
		CurrentUser.setAddress(totalClient[checkNum].getAddress());
		CurrentUser.setEmail(totalClient[checkNum].getEmail());
		CurrentUser.setId(totalClient[checkNum].getId());
		CurrentUser.setPassword(totalClient[checkNum].getPassword());

		return true;
	}

	return false;
}


bool ClientCollection::Logout() {

	bool logoutcheck;

	cout << "���� �α׾ƿ� �Ͻðڽ��ϱ�? Y(1) / N(0) : ";
	cin >> logoutcheck;
	cin.clear();
	cin.ignore(256, '\n');

	if (logoutcheck == 1) {
		CurrentUser.setSession(1);
		CurrentUser.setName("guest");
		CurrentUser.setPrivateNumber(-1);
		CurrentUser.setAddress("");
		CurrentUser.setEmail("");
		CurrentUser.setId("!!!");
		CurrentUser.setPassword("");
		return true;
	}
	else
		return false;
}
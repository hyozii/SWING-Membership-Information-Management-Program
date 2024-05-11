#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Information {
private:
    string name;
    string phone;

public:
    void Set(const string& newName, const string& newPhone) {
        name = newName;
        phone = newPhone;
    }

    string GetName() const {
        return name;
    }

    string GetPhone() const {
        return phone;
    }
};

bool Check(vector<Information>* members, const string& name, const string& phone) {
    for (const auto& member : *members) {
        if (member.GetName() == name && member.GetPhone() == phone) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<Information> members;
    int choice;
    string name, phone, nowName, nowPhone; // ����: nowName, nowPhone�� ����

    do {
        cout << "\n***** ȸ�� ���� ���� ���α׷� *****" << endl;
        cout << "\n1. ȸ������" << endl;
        cout << "2. �α���" << endl;
        cout << "3. ȸ�� ���� ����" << endl;
        cout << "4. ����" << endl;
        cout << "\n��ȣ�� �Է��ϼ���: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n***** ȸ�������� �����մϴ� *****" << endl;
            cout << "\n�̸��� �Է��ϼ���: ";
            cin >> name;
            cout << "��ȭ��ȣ�� �Է��ϼ���: ";
            cin >> phone;

            if (Check(&members, name, phone)) {
                cout << "\n�̹� ��ϵ� �����Դϴ�." << endl;
            }
            else {
                Information newMember;
                newMember.Set(name, phone);
                members.push_back(newMember);
                cout << "\nȸ�������� �Ϸ�Ǿ����ϴ�." << endl;
            }
            break;
        case 2:
            cout << "\n***** �α����� �����մϴ� *****" << endl;
            cout << "\n�̸��� �Է��ϼ���: ";
            cin >> name;
            cout << "��ȭ��ȣ�� �Է��ϼ���: ";
            cin >> phone;

            if (Check(&members, name, phone)) {
                cout << "\n�α����� �Ϸ�Ǿ����ϴ�." << endl;
                cout << "\n***** " << name << "���� ȯ���մϴ�. *****" << endl;
            }
            else {
                cout << "\nȸ�� ������ ��ġ���� �ʽ��ϴ�." << endl;
            }
            break;
        case 3:
            cout << "\n***** ȸ�� ���� ������ �����մϴ� *****" << endl;
            cout << "\n���� ȸ�� ����" << endl;
            cout << "�̸��� �Է��ϼ���: ";
            cin >> nowName; // ����: nowName���� ����
            cout << "��ȭ��ȣ�� �Է��ϼ���: ";
            cin >> nowPhone; // ����: nowPhone���� ����

            if (!Check(&members, nowName, nowPhone)) {
                cout << "\nȸ�� ������ ��ġ���� �ʽ��ϴ�." << endl;
            }
            else {
                cout << "\n���ο� ȸ�� ����" << endl;
                cout << "�̸��� �Է��ϼ���: ";
                cin >> name;
                cout << "��ȭ��ȣ�� �Է��ϼ���: ";
                cin >> phone;

                if (!Check(&members, name, phone)) {
                    cout << "\nȸ�� ���� ������ �Ϸ�Ǿ����ϴ�." << endl;
                    // �ش� ȸ���� ������ ������Ʈ�մϴ�.
                    for (auto& member : members) {
                        if (member.GetName() == nowName && member.GetPhone() == nowPhone) {
                            member.Set(name, phone);
                            break;
                        }
                    }
                }
                else {
                    cout << "\n�̹� ��ϵ� �����Դϴ�." << endl;
                }
            }
            break;
        case 4:
            cout << "\n���α׷��� �����մϴ�." << endl;
            break;
        default:
            cout << "\n��Ȯ�� ��ȣ�� �Է��ϼ���." << endl;
        }
    } while (choice != 4);

    return 0;
}

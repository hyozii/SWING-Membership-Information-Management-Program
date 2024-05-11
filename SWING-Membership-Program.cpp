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
    string name, phone, nowName, nowPhone; // 수정: nowName, nowPhone로 변경

    do {
        cout << "\n***** 회원 정보 관리 프로그램 *****" << endl;
        cout << "\n1. 회원가입" << endl;
        cout << "2. 로그인" << endl;
        cout << "3. 회원 정보 수정" << endl;
        cout << "4. 종료" << endl;
        cout << "\n번호를 입력하세요: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n***** 회원가입을 진행합니다 *****" << endl;
            cout << "\n이름을 입력하세요: ";
            cin >> name;
            cout << "전화번호를 입력하세요: ";
            cin >> phone;

            if (Check(&members, name, phone)) {
                cout << "\n이미 등록된 정보입니다." << endl;
            }
            else {
                Information newMember;
                newMember.Set(name, phone);
                members.push_back(newMember);
                cout << "\n회원가입이 완료되었습니다." << endl;
            }
            break;
        case 2:
            cout << "\n***** 로그인을 진행합니다 *****" << endl;
            cout << "\n이름을 입력하세요: ";
            cin >> name;
            cout << "전화번호를 입력하세요: ";
            cin >> phone;

            if (Check(&members, name, phone)) {
                cout << "\n로그인이 완료되었습니다." << endl;
                cout << "\n***** " << name << "님을 환영합니다. *****" << endl;
            }
            else {
                cout << "\n회원 정보가 일치하지 않습니다." << endl;
            }
            break;
        case 3:
            cout << "\n***** 회원 정보 수정을 진행합니다 *****" << endl;
            cout << "\n현재 회원 정보" << endl;
            cout << "이름을 입력하세요: ";
            cin >> nowName; // 수정: nowName으로 변경
            cout << "전화번호를 입력하세요: ";
            cin >> nowPhone; // 수정: nowPhone으로 변경

            if (!Check(&members, nowName, nowPhone)) {
                cout << "\n회원 정보가 일치하지 않습니다." << endl;
            }
            else {
                cout << "\n새로운 회원 정보" << endl;
                cout << "이름을 입력하세요: ";
                cin >> name;
                cout << "전화번호를 입력하세요: ";
                cin >> phone;

                if (!Check(&members, name, phone)) {
                    cout << "\n회원 정보 수정이 완료되었습니다." << endl;
                    // 해당 회원의 정보를 업데이트합니다.
                    for (auto& member : members) {
                        if (member.GetName() == nowName && member.GetPhone() == nowPhone) {
                            member.Set(name, phone);
                            break;
                        }
                    }
                }
                else {
                    cout << "\n이미 등록된 정보입니다." << endl;
                }
            }
            break;
        case 4:
            cout << "\n프로그램을 종료합니다." << endl;
            break;
        default:
            cout << "\n정확한 번호를 입력하세요." << endl;
        }
    } while (choice != 4);

    return 0;
}

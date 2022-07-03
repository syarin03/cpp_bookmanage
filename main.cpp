#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>
#include "book.h"
#include "user.h"

using namespace std;

void signUp();
User signIn();
void findIDPW();
void library(User user);


vector<User> userLIst;
vector<Book> bookList = {{1, "황순원", "별"}, {2, "이광수", "흙"},
                       {3, "나도향", "벙어리삼룡이"}, {4, "전영택", "화수분"},
                       {5, "김유정", "동백꽃"}, {6, "피터 스완슨", "여덟 건의 완벽한 살인"},
                       {7, "오노 후유미", "시귀1"}, {8, "나가츠키 탓페이", "Re:제로부터 시작하는 이세계 생활"},
                       {9, "베르나르 베르베르", "파피용"}, {10, "정찬주", "공부하다 죽어라"}};

int main() {
    srand((unsigned int)time(nullptr));
    bool loop = true;
    int sel;
    User loginUser;

    while (loop) {
        cout << "(1) 회원가입\n(2) 로그인\n(3) 아이디/비밀번호 찾기\n(4) 종료\n>>> ";
        cin >> sel; cout << endl;
        switch (sel) {
            case 1:
                signUp();
                cout << endl;
                break;
            case 2:
                loginUser = signIn();
                cout << endl;
                if (loginUser.getID().empty()) {
                    break;
                }
                 library(loginUser);
                break;
            case 3:
                findIDPW();
                cout << endl;
                break;
            case 4:
                cout << "종료합니다" << endl;
                loop = false;
                break;
            default:
                break;
        }

    }

    return 0;
}

void signUp() {
    bool registok = true;
    string id, pw, name, phone;
    cout << "아이디: "; cin >> id;
    cout << "비밀번호: "; cin >> pw;
    cout << "이름: "; cin >> name;
    cout << "전화번호: "; cin >> phone;

    if (userLIst.empty()) {
        User newUser(id, pw, name, phone);
        userLIst.push_back(newUser);
        cout << "회원가입 완료" << endl;
    }
    else {
        for (auto i : userLIst) {
            if (i.getID() == id) {
                cout << "중복된 아이디" << endl;
                registok = false;
                break;
            }
            else {
                continue;
            }
        }
        if (registok) {
            User newUser(id, pw, name, phone);
            userLIst.push_back(newUser);
            cout << "회원가입 완료" << endl;
        }
    }
}

User signIn() {
    string id, pw;
    bool loginok = true;
    User loginUser;

    if (userLIst.empty()) {
        cout << "등록된 회원정보 없음\n회원가입 먼저 ㄱㄱ" << endl;
    }
    else {
        cout << "아이디: "; cin >> id;
        cout << "비밀번호: "; cin >> pw;
        for (auto i : userLIst) {
            if (i.getID() == id) {
                if (i.getPW() == pw) {
                    loginUser = i;
                    loginok = true;
                    break;
                }
                else {
                    loginok = false;
                }
            }
            else {
                loginok = false;
            }
        }
        if (loginok) {
            cout << "로그인 성공" << endl;
        }
        else {
            cout << "로그인 실패" << endl;
        }
    }
    return loginUser;
}

void findIDPW() {
    string id, name, phone;
    bool findok = true;
    int sel;
    if (userLIst.empty()) {
        cout << "찾을 거 없음" << endl;
    }
    else {
        cout << "(1) 아이디 찾기\n(2) 비밀번호 찾기\n>>> ";
        cin >> sel; cout << endl;
        switch (sel) {
            case 1:
                cout << "이름: "; cin >> name;
                cout << "전화번호: "; cin >> phone;
                for (auto i : userLIst) {
                    if (i.getName() == name) {
                        if (i.getPhone() == phone) {
                            cout << "아이디: " << i.getID() << endl;
                            findok = true;
                            break;
                        }
                        else {
                            findok = false;
                        }
                    }
                    else {
                        findok = false;
                    }
                }
                if (!findok) {
                    cout << "없음" << endl;
                }
                break;
            case 2:
                cout << "아이디: "; cin >> id;
                cout << "전화번호 : "; cin >> phone;
                for (auto i : userLIst) {
                    if (i.getID() == id) {
                        if (i.getPhone() == phone) {
                            cout << "비밀번호: " << i.getPW() << endl;
                            findok = true;
                            break;
                        }
                        else {
                            findok = false;
                        }
                    }
                    else {
                        findok = false;
                    }
                }
                if (!findok) {
                    cout << "없음" << endl;
                }
                break;
            default:
                break;
        }
    }
}

void library(User user) {
    bool loop = true;
    int sel;

    while (loop) {
        cout << user.getName() << " 로그인 중" << endl << endl;
        cout << "(1) 추천 도서\n(2) 도서 조회\n(3) 대여/반납\n(4) 도서 기증\n(5) 내정보\n(6) 로그아웃\n(7) 일자 변경\n(8) 프로그램 종료\n>>> ";
        cin >> sel; cout << endl;
        random_device rd;
        default_random_engine rng(rd());
        vector<Book> bookListTemp = bookList;
        int searchnum;
        string searchname;
        switch (sel) {
            case 1:
                cout << "◎ 추천 도서 목록 ◎" << endl;
                shuffle(bookListTemp.begin(), bookListTemp.end(), rng);
                for (int i = 0; i < 3; i++) {
                    cout << bookListTemp[i].getNum() << " - " << bookListTemp[i].getName() << " - " << bookListTemp[i].getWriter() << endl;
                }
                bookListTemp.clear();
                cout << endl;
                break;
            case 2:
                int s;
                cout << "(1) 도서 번호로 검색\n(2) 도서 제목으로 검색\n(3) 저자로 검색\n>>> ";
                cin >> s; cout << endl;
                switch (s) {
                    case 1:
                        cout << "검색할 도서 번호: ";
                        cin >> searchnum; cout << endl;
                        cout << "검색 결과" << endl;
                        for (auto i : bookList) {
                            if (searchnum == i.getNum()) {
                                cout << i.getNum() << " - " << i.getName() << " - " << i.getWriter() << endl;
                            }
                        }
                        break;
                    case 2:
                        cout << "검색할 도서 제목: ";
                        cin >> searchname; cout << endl;
                        cout << "검색 결과" << endl;
                        for (auto i : bookList) {
                            if (i.getName().find(searchname) != -1) {
                                cout << i.getNum() << " - " << i.getName() << " - " << i.getWriter() << endl;
                            }
                        }
                        break;
                    case 3:
                        cout << "검색할 저자: ";
                        cin >> searchname; cout << endl;
                        cout << "검색 결과" << endl;
                        for (auto i : bookList) {
                            if (i.getName().find(searchname) != -1) {
                                cout << i.getNum() << " - " << i.getName() << " - " << i.getWriter() << endl;
                            }
                        }
                        break;
                    default:
                        break;
                }
                cout << endl;
                break;
            case 3:
                cout << "(1) 대여\n(2) 반납\n>>> ";
                cin >> s; cout << endl;
                switch (s) {
                    case 1:
//                        while (true) {
                            cout << "대여할 도서 번호: ";
                            cin >> searchnum; cout << endl;
                            for (auto i : bookList) {
                                if (searchnum == i.getNum() && i.getWhorent().empty()) {
                                    bookListTemp.push_back(i);
                                    cout << "장바구니 추가 완료" << endl;
                                }
                                else {
                                    continue;
                                }
                            }
                            if (bookListTemp.empty()) {
                                cout << "장바구니 추가 실패" << endl;
                            }
                            else {
                                int n;
                                cout << "(1) 대여 도서 추가\n(2) 대여\n>>> ";
                                cin >> n; cout << endl;

                            }
//                        }
                        break;
                    case 2:
                        bool hasbook = true;
                        for (auto i : bookList) {
                            if (i.getWhorent() == user.getID()) {
                                cout << i.getNum() << " - " << i.getName() << " - " << i.getWriter() << endl;
                                hasbook = false;
                            }
                            else {
                                continue;
                            }
                        }
                        if (hasbook) {
                            
                        }
                }
                cin >> s; cout << endl;
                break;
            default:
                break;
        }
    }
}
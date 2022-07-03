#ifndef BOOKMANAGE_USER_H
#define BOOKMANAGE_USER_H
#include <cstring>
#include <utility>

using namespace std;

class User {
private:
    string id;
    string pw;
    string name;
    string phone;
public:
    User(string userid, string userpw, string username, string userphone) {
        id = move(userid);
        pw = move(userpw);
        name = move(username);
        phone = move(userphone);
    }
    User(){
        id = "";
        pw = "";
        name = "";
        phone = "";
    }
    string getID() {
        return id;
    }
    string getPW() {
        return pw;
    }
    string getName() {
        return name;
    }
    string getPhone() {
        return phone;
    }
    void changePW(string newpw) {
        pw = move(newpw);
    }
};


#endif //BOOKMANAGE_USER_H

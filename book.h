#ifndef BOOKMANAGE_BOOK_H
#define BOOKMANAGE_BOOK_H
#include <cstring>

using namespace std;


class Book {
private:
    int num;
    string writer;
    string name;
    bool isrent;
    string whorent;
    int rentday;
public:
    Book(int booknum, string bookwriter, string bookname) {
        num = booknum;
        name = move(bookname);
        writer = move(bookwriter);
        isrent = false;
        rentday = 0;
    }
    int getNum() {
        return num;
    }
    string getName() {
        return name;
    }
    string getWriter() {
        return writer;
    }
    bool isRent() {
        return isrent;
    }
    string getWhorent() {
        return whorent;
    }
    int getRentday() {
        return rentday;
    }
    void setWhorent(string user) {
        whorent = move(user);
    }
    void plusRentday() {
        rentday++;
    }
    void resetRentday() {
        rentday = 0;
    }
};


#endif //BOOKMANAGE_BOOK_H

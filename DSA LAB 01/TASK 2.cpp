#include <iostream>
#include <cstring>
using namespace std;
class Exam {
private:
    char* SName;
    char* EDate;
    int score;

public:
    Exam(const char* name, const char* date, int s) {
        SName = new char[strlen(name) + 1];
        strcpy(SName, name);

        EDate = new char[strlen(date) + 1];
        strcpy(EDate, date);
        score = s;
    }

    ~Exam() {
        delete[] SName;
        delete[] EDate;   
    }

    void setDetails(const char* name, const char* date, int s) {
        delete[] SName;
        delete[] EDate;

        SName = new char[strlen(name) + 1];
        strcpy(SName, name);

        EDate = new char[strlen(date) + 1];
        strcpy(EDate, date);

        score = s;
    }

    void show() {
        cout << "Student Name: " << SName << endl;
        cout << "Exam Date: " << EDate << endl;
        cout << "Score: " << score << endl;
    }

   
};

int main() {
    cout << "Original Object:" << endl;
    Exam e1("Sanaullah", "20/09/2025", 72);
    e1.show();

    cout << "\nShallow Copy :" << endl;
    Exam e2 = e1;   
    e2.show();

    cout << "\nEnd of program " << endl;
    return 0;
}


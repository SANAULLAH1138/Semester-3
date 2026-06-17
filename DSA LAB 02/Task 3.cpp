#include <iostream>
using namespace std;

int main() {
    int dep;
    cout << "Enter number of dep: ";
    cin >> dep;

    int* spd = new int[dep];
    int*** marks = new int**[dep];

    for (int i = 0; i < dep; i++) {
        cout << endl << "Enter number of students in dep " << i + 1 << ": ";
        cin >> spd[i];

        marks[i] = new int*[spd[i]];

        for (int j = 0; j < spd[i]; j++) {
            marks[i][j] = new int[5];
            cout << " Enter marks of 5 subjects for student " << j + 1 << ": ";
            for (int k = 0; k < 5; k++) {
                cin >> marks[i][j][k];
            }
        }
    }

    cout << endl << "Dep Results:" << endl;
    for (int i = 0; i < dep; i++) {
        int highest = marks[i][0][0];
        int lowest  = marks[i][0][0];
        int sum = 0, totalMarks = 0;

        for (int j = 0; j < spd[i]; j++) {
            for (int k = 0; k < 5; k++) {
                int m = marks[i][j][k];
                if (m > highest) highest = m;
                if (m < lowest)  lowest  = m;
                sum += m;
                totalMarks++;
            }
        }

        double avg = (double)sum / totalMarks;
        cout << "Dep " << i + 1 << " -> "
             << " Highest: " << highest
             << " Lowest: " << lowest
             << " Average: " << avg << endl;
    }

    for (int i = 0; i < dep; i++) {
        for (int j = 0; j < spd[i]; j++) {
            delete[] marks[i][j];
        }
        delete[] marks[i];
    }
    delete[] marks;
    delete[] spd;

    return 0;
}


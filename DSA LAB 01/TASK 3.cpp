#include <iostream>
using namespace std;

class Box {
private:
    int* data;

public:
    Box(int value = 0) {
        data = new int(value);
        cout << "Constructor value = " << *data << endl;
    }

    ~Box() {
        cout << "Destructor  value = " << *data << endl;
        delete data;
    }

    Box( Box& other) {
        data = new int(*other.data);
        cout << "Copy constructor value = " << *data << endl;
    }

    Box& operator=(const Box& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
            cout << "Copy assignment value = " << *data << endl;
        }
        return *this;
    }

    void setValue(int value) {
        *data = value;
    }

    int getValue() const {
        return *data;
    }

    void shallowCopy(Box& other) {
        this->data = other.data;
        cout << "Shallow copy value = " << *data << endl;
    }
};

int main() {
    cout << " Deep Copy " << endl;
    Box box1(10);
    Box box2 = box1;
    box2.setValue(20);

    cout << "box1 = " << box1.getValue() << endl;
    cout << "box2 = " << box2.getValue() << endl;

    Box box3;
    box3 = box1;
    box3.setValue(30);

    cout << "box1 = " << box1.getValue() << endl;
    cout << "box3 = " << box3.getValue() << endl;

    cout << "\n Shallow Copy Example " << endl;
    Box box4(100);
    Box box5;
    box5.shallowCopy(box4);
    box5.setValue(200);

    cout << "box4 = " << box4.getValue() << endl;
    cout << "box5 = " << box5.getValue() << endl;

    return 0;
}


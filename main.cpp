#include <iostream>
#include <limits>
#include <vector>
using namespace std;

//Ethan Ma 3/26/26
//Functions and classes assignment
class circle {
    double radius;
public:
    circle(double r) {
        radius = r;
    } double getArea() {
        return 3.14 * radius * radius;
    }
};

class rectangle {
    double width, height;
public:
    rectangle(double w, double h) {
        width = w;
        height = h;
    }
    double getArea(){
        return width * height;
    }
};

class calculator {
    double num1, num2;
public:
    calculator(double x, double y) {
        num1 = x;
        num2 = y;
    }
    double add() {
        return num1 + num2;
    }
    double sub() {
        return num1 - num2;
    }
    double mul() {
        return num1 * num2;
    }
    double div() {
        return num1 / num2;
    }
};


class student {
    string name;
    vector<double> tests;
    double average;

public:
    student(string n) {
        name = n;
    }
    void addTest(double t) {
        tests.push_back(t);
    }
    double calcAverage() {
        if (!tests.empty()) {
            for (double test : tests) {
                average += test;
            }
            double temp = average / tests.size();
            average = 0;
            return temp;
        }
        return 0;
    }
};


int intInput() {
    int input;
    while (!(cin >> input)) {
        cout << "Invalid input, please try again." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return input;
}

double doubleInput() {
    double input;
    while (!(cin >> input)) {
        cout << "Invalid input, please try again." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return input;
}



int main() {
    int ask;
    while (ask != 0) {
        ask = 0;
        cout << "\n\nWhat do you want to do? "
                "\n1 for rectangle and circle area calculator"
                "\n2 for regular calculator"
                "\n3 for student grade system"
                "\n0 to quit" << endl;
        ask = intInput();
        while (ask != 1 && ask != 2 && ask != 3 && ask != 0) {
            cout << "Invalid input, please try again." << endl;
            ask = intInput();
        }
        if (ask == 1) {
            //rectangle and circle area
            cout << "\n\nArea calculator \n\nWould you like to create a circle or a rectangle? 1 for circle, 2 for rectangle:" << endl;
            int ask = intInput();
            while (ask != 1 && ask != 2) {
                cout << "Invalid input, please try again." << endl;
                ask = intInput();
            }
            if (ask == 1) {
                cout<<"Enter the radius of the circle:" <<endl;
                double r = doubleInput();
                while (r <= 0) {
                    cout << "Invalid input, please try again." << endl;
                    r = doubleInput();
                }
                circle circle(r);
                cout << "The area of your circle is " << circle.getArea() << endl;
            }
            else if (ask == 2){
                cout<<"Enter the width of the rectangle:" <<endl;
                double w = doubleInput();
                while (w <= 0) {
                    cout << "Invalid input, please try again." << endl;
                    w = doubleInput();
                }
                cout<<"Enter the height of the rectangle:" <<endl;
                double h = doubleInput();
                while (h <= 0) {
                    cout << "Invalid input, please try again." << endl;
                    h = doubleInput();
                }
                rectangle rectangle(w, h);
                cout << "The area of your rectangle is " << rectangle.getArea() << endl;
            }
        }
        else if (ask == 2) {
            //calculator
            cout << "\n\nRegular calculator\n\nEnter 2 numbers:" << endl;
            double num1, num2;
            num1 = doubleInput();
            num2 = doubleInput();
            calculator calculator(num1, num2);
            cout << "Enter an operation (+, -, *, /):" << endl;
            char operation;
            cin >> operation;
            while (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
                cout << "Invalid input, please try again." << endl;
                cin >> operation;
            }
            if (operation == '+') {
                cout << num1 << " + " << num2 << " = " << calculator.add() << endl;
            }
            else if (operation == '-') {
                cout << num1 << " - " << num2 << " = " << calculator.sub() << endl;
            }
            else if (operation == '*') {
                cout << num1 << " * " << num2 << " = " << calculator.mul() << endl;
            }
            else if (operation == '/' && num2 != 0) {
                cout << num1 << " / " << num2 << " = " << calculator.div() << endl;
            }
            else {
                cout << "Error" << endl;
            }
        }
        else if (ask == 3) {
            //student grade system
            cout << "\n\nStudent grade system\n\nEnter the student's name:" << endl;
            string name;
            cin.ignore();
            getline (cin, name);
            cout << "Enter the maximum score:" << endl;
            double max = doubleInput();
            while (max <= 0) {
                cout << "Invalid input, please try again." << endl;
                max = doubleInput();
            }
            student student(name);
            ask = 0;
            while (ask != 3) {
                cout << "Would you like to add a test score or see score average? 1 to add a score, 2 to see average, 3 to quit:" << endl;
                ask = intInput();
                while (ask != 1 && ask != 2 && ask != 3) {
                    cout << "Invalid input, please try again." << endl;
                    ask = intInput();
                }
                if (ask == 1) {
                    cout << "Enter the new score:" << endl;
                    double score = doubleInput();
                    while (score < 0 || score > max) {
                        cout << "Invalid input, please try again." << endl;
                        score = doubleInput();
                    }

                    student.addTest(score);
                }
                else if (ask == 2) {
                    cout << name << "'s average score is " << student.calcAverage() << endl;
                }
            }
        }



    }
    return 0;
}
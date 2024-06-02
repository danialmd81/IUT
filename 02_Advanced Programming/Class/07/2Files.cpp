#include <filesystem>
#include <fstream>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

class student {
  public:
    string name;
    int age;
    student() {
        name = " ";
        age = 0;
    }
    student(string n, double a) {
        name = n;
        age = a;
    }
};
ostream &operator<<(ostream &os, const student &st) {
    os << "Student " << st.name << " is " << st.age << " years old. ";
    return os;
}
istream &operator>>(istream &is, student &st) {
    char c, c2;
    if (is >> c && c == '{' && is >> c2 && c2 == '"') {
        string str;
        while (is.get(c) && c != '"') {
            str += c;
        }
        if (is >> c && c == ',') {
            int num = 0;
            if (is >> num >> c && c == '}') {
                st.name = str;
                st.age = num;
                return is;
            }
        }
    }
    is.setstate(iostream::failbit);
    return is;
}

int main() {
    ofstream ofile;
    ofile.open("test.txt");
    if (!ofile.is_open()) {
        cout << "file was not open";
        return 0;
    } else {
        int i = 112;
        ofile << "The number I want to print is" << endl;
        ofile << i << " the file ends here";
        ofile.close();
    }

    ifstream ifile;
    ifile.open("test.txt");
    if (!ifile.is_open())
        cout << "fail";
    else {
        string str;
        while (getline(ifile, str)) {
            cout << str << endl;
        }
        ifile.close();
    }

    ifstream ifile1;
    ifile1.open("test.txt");
    if (!ifile1.is_open())
        cout << "fail";
    else {
        ifile1.seekg(0);
        int n = ifile1.tellg();
        string str;
        while (getline(ifile1, str)) {
            cout << str << endl;
        }
        int n2 = ifile1.tellg();
        cout << n << " " << n2;
    }

    ifstream ifile2;
    ifile2.open("test.txt");
    if (!ifile2.is_open())
        cout << "fail";
    else {
        int begin = ifile2.tellg();
        ifile2.seekg(0, ios::end);
        int end = ifile2.tellg();
        cout << end - begin;
    }

    fstream file("test.txt", ios::in);
    if (file.is_open()) {
        string str;
        while (getline(file, str)) {
            cout << str << endl;
        }
    }
}

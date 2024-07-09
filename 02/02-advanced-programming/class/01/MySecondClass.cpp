

#include <iostream>
using namespace std;
class Cars {
public:
    Cars() {
        ID = 0;
        name = "";
        color = "";
        price = 0;
    }
    Cars(int i, string n, string c, double p) {
        ID = i;
        name = n;
        color = c;
        price = p;
    }
    int get_ID() {
        return ID;
    }
    string get_name() {
        return name;
    }
    string get_color() {
        return color;
    }
    double get_price() {
        return price;
    }
    void set_price(double newP) {
        price = newP;
    }
private:
    int ID;
    string name;
    string color;
    double price;
};
class Customer {
public:
    Customer(int i, string n, string a, Cars c) {
        ID = i;
        name = n;
        address = a;
        car = c;
    }
    Cars get_car() {
        return car;
    }
    Cars car;
private:
    int ID; 
    string name;
    string address;

};

int main()
{
    Cars c1(1, "benz", "purple", 12.7);
    //cout << "the old price of c1 is : " << c1.get_price() << endl;
    //c1.set_price(67.2);
    //cout << "the new price of c1 is : " << c1.get_price() << endl;
    Customer cu(1, "ali", "isfahan", c1);
    cout << cu.car.get_color();
}


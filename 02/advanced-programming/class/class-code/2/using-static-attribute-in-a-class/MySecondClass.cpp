

#include <iostream>
using namespace std;
class Cars {
public:
    Cars() {
        ID = 0;
        name = "";
        color = "";
        price = 0;
        count++;
    }
    
    Cars(int i, string n, string c, double p) {
        ID = i;
        name = n;
        color = c;
        price = p;
        count++;
    }
    int get_ID() {
        return ID;
    }
    int get_count() {
        return count;
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
    static int count;

};
class Customer {
public:
    Customer(int i, string n, string a, Cars &c) {
        ID = i;
        name = n;
        address = a;
        car = c;
    }
    string get_name() {
        return name;
    }

    Cars car;

private:
    int ID; 
    string name;
    string address;

};
int Cars::count = 0;
  
int main()
{
    Cars c1(1, "benz", "purple", 12.7);
    //cout << "the old price of c1 is : " << c1.get_price() << endl;
    //c1.set_price(67.2);
    //cout << "the new price of c1 is : " << c1.get_price() << endl;
    //Customer cu(1, "ali", "isfahan",c1);
    cout << c1.get_count() << endl;
    Cars c2(1, "benz", "purple", 12.7);
    Cars c3(1, "benz", "purple", 12.7);
    Cars c4(1, "benz", "purple", 12.7);
    cout << "Count of c1 is: " << c1.get_count() << endl;
    cout << "Count of c4 is: " ;
}


#include <iostream>
// introduction to name spaces.
using namespace std;

namespace Shop {// the first namespace which is used to contain the Cars class for shop purpose
    class Cars {// Cars class with price attribute
    public:
        Cars(string m, string c, double p, int y) {//constructor
            model = m;
            color = c;
            price = p;
            year = y;
        }
        string get_model() {
            return model;
        }
        string get_color() {
            return color;
        }
        double get_price() {
            return price;
        }
        int get_year() {
            return year;
        }
    private:
        string model;
        string color;
        double price;
        int year;
    };

}

namespace antique {// second namespace with antique purpose
    class Cars {// cars class without price and including owner attribute
    public:
        Cars(string m, string c, int y, string o) {
            model = m;
            color = c;
            owner = o;
            year = y;
        }
        string get_model() {
            return model;
        }
        string get_color() {
            return color;
        }
        int get_year() {
            return year;
        }
        string get_owner() {
            return owner;
        }
    private:
        string model;
        string color;
        string owner;
        int year;
    };

}
using namespace Shop; // so we dont need to use :: every time we need to use classes in namespace
//using namespace antique;
int main()
{
   Cars c1("benz", "black", 12.6, 56);
    cout <<" car color is: " << c1.get_color() << " car model is :" <<c1.get_model()
        << "car price is: " << c1.get_price() << endl;
    antique::Cars c2("bmw", "white", 1976, "mohammad");
    cout << " car color is :" << c2.get_color() << " car model is : " << c2.get_model()
        << "car owner is :" << c2.get_owner();
}


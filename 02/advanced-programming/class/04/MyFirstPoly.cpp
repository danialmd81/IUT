#include <iostream>

using namespace std;
class shape {
protected:
    int wid; int len;
public:
    shape() { wid = 0; len = 0; }
    shape(int w) { wid = w; len = 0; }
    shape(int w, int l) { wid = w; len = l; }
    virtual double get_area() {
        return 0;
    }
};
class circle :public shape {
public: circle(int w1):shape(w1){}
     // void operator=(shape &s){}
     double get_area() { return 3.14 * wid/2 * wid/2; }
     double get_pi() { return 3.14; }
};
class rectangle : public shape {
public: rectangle(int w, int l):shape (w,l){}
      double get_area() { return wid * len; }

};
void print(shape* s) {
    //if(typeid(*s) == typeid(circle)){ //we check if the object currently in function is a circle
    //    cout << "circle's area is: " << s->get_area() << endl;
    //}
    //if (typeid(*s) == typeid(rectangle)) {
    //    cout << "rectangle's area is: " << s->get_area() << endl;
    //}
    circle* c = dynamic_cast<circle*>(s);// introducing dynamic casting to create a pointer to a circle object
    if(c!= nullptr){ 
        cout << "circle's area is: " << c->get_pi() << endl;
    }
    rectangle* r = dynamic_cast<rectangle*>(s);
    if (r != nullptr) {
        cout << "rectangle's area is: " << s->get_area() << endl;
    }
}
int main()
{
    shape* vec[4];
    circle c1(15); circle c2(20);
    rectangle r1(10, 12); rectangle r2(10, 18);
    // c1 = sh;
    vec[0] = &c1; vec[1] = &c2;
    vec[2] = &r1; vec[3] = &r2;
    for (auto p : vec) {
        print(p);
    }
    //circle c1(12);
}


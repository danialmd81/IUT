// in this code, we will talk about polymorphism and how to impelement it.

#include <iostream>

using namespace std;
class shape // we created a shape class as base class of all shapes we have.
    // thus, all the classes created for each object (like circle, triangle, rectange, etc.) will inherite from shape class.
{
protected:// each shape will have 2 attributes
    int wid; int len;
public:
    shape() { wid = 0; len = 0; }// default costructor
    shape(int w) { wid = w; len = 0; }
    shape(int w, int l) { wid = w; len = l; }
   // virtual double get_area() { return 0; } //if we have a pointer from the base class and it is pointing to an object of one of its driven classes(its childs), whenever a function is called on the pointer of the base class, it will check the relative  child first.
    // if the child overrides the function, the childs function will be called. if not, the parents function is used.
    virtual double get_area() = 0;// this syntax will make the shape class abstract.
    //we cannot creat an object form an abstract class and children of an abstract class, have to impelement the abstract function.
};
class circle :public shape {
public: circle(int w1):shape(w1){}
     // void operator=(shape &s){}
     double get_area() { return 3.14 * wid/2 * wid/2; }// circle overrides the get_area class. if we remove this function, we cannot creat any object from circle because the get_area function is pure virtual in its parent.
};
class rectangle : public shape {
public: rectangle(int w, int l):shape (w,l){}
      double get_area() { return wid * len; }
    };
void print(shape* s) {// using polymorphism in a function
    cout << "shape's area is: " << s->get_area() << endl;
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
    
}


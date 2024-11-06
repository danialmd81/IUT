#include"locus.h"

int main()
{
   srand(time(NULL));
    point p[]={{1,1},{1,2},{2,1},{4,4}};
    locus a(4,p);
    cout<<a.convex_check()<<endl;
    cout<<a.locus_perimeter()<<endl;
    cout<<a.locus_area()<<endl;
    a.show_locus();
    locus b;
    cout<<b.convex_check()<<endl;
    cout<<b.locus_perimeter()<<endl;
    cout<<b.locus_area()<<endl;
    b.show_locus();
    locus c(5);
    cout<<c.convex_check()<<endl;
    cout<<c.locus_perimeter()<<endl;
    cout<<c.locus_area()<<endl;
    c.show_locus();

}

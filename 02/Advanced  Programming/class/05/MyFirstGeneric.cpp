// Introduction of generic programming and templates
#include<list>
#include <iostream>
using namespace std;
//template<typename T, typename U>  // creating a template function with unknown input types
//void sw(T& a, U&b){
//    T tmp = a;
//    b = a;
//    a = tmp;
//}
//template<typename T> // template function with 1 template typename 
//void sw(T& a, T& b) {
//    T tmp = a;
//    a = b;
//    b = tmp;
//    cout << "I am a number" << endl;
//}
//void sw(char& a, char& b) {
//    char tmp = a;
//    a = b;
//
//    b = tmp;
//    cout << " I am a char" << endl;
//}
//void sw(char& a, char& b) {// overriding the template function for char input
//    char tmp = a;
//    a = b;
//    b = tmp;
//}
template <typename T, const int SIZE>//template class with an int variable for class
class vector {
private: //int size;
	   T* elem;
public: vector(T s) {
	//size = s;
	elem = new T[SIZE];
	for (auto p: elem) {
	
	 p = 12;
	}
}
	  T& get_val(int index) { return elem[index]; }
};
int main()
{
	//int a = 4; double b = 8; // testing template functions
	//cout << a << "--" << b << endl;
	//sw<int,double>(a, b);
	//cout << a << "--" << b << endl;
	//char c = 'c', d = 'd';
	//cout << c << "--" << d << endl;
	//sw(c, a);
	//cout << c << "--" << d << endl;
	vector<int,100> v1(10);//testing template class
	
	cout << v1.get_val(4);
}


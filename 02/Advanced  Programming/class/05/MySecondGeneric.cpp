// introducing functor and lambda expression
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//template <typename T> // a template class 
//class vector {
//private: int size;
//	   T* elem;
//public:
//	vector(int s) {
//		size = s;
//		elem = new T[s];
//		//for (int i = 0; i < s; i++) {
//		//	elem[i] = 5;
//		//}
//	}
//	T& value(int index) { 
//		cout << "I am generic \n";
//		return elem[index]; }
//};
//template <>
//class vector<string> { // the same template class for specific type of objects(string)
//private: int size;
//	   string* elem;
//public:
//	vector(int s) {
//		size = s;
//		elem = new string[s];
//		//for (int i = 0; i < s; i++) {
//		//	elem[i] = 5;
//		//}
//	}
//	string& value(int index) { 
//		cout << " I am string" << endl;
//		return elem[index]; }
//};
//class person { // class to test template function and class
//private: int age; string name;
//public: person() { age = 10; name = "mohammad"; }
//	  string get_name() { return name; }
//};
//template <typename T>// template function for using a function described in person class if a person object is passed to this function, it will work properly, otherwise it will have a run-time error
//void print(T p) {
//	cout << p.get_name();
//}
// -------------------------------------------------------
//template<typename T> // a functor class. every object we create from this class can work as a function to compare two objects and return true if the second is greather than first
//class gr_th {
//private: T value;
//public: gr_th(T v) { value = v; }
//	  bool operator()(T data) { return data > value; } // every class or struct that overloads () operator, will be a functor
//};
//template<typename T, typename U>// a counter that will recieve any type of container(list, vector, array, etc.) and an operator, then counts the number of types that operator will occur in the container
//int counter(T vec, U op) {
//	int cnt = 0;
//	for (auto x : vec) {
//		if (op(x))
//			cnt++;
//	}
//	return cnt;
//}
int main()
{
	//vector<int> v1(10);
	//vector<double> v2(15);
	//vector<string> v3(20);
	//vector<person> v4(25);
	////v1.value(5) = 10;
	////cout << v1.value(5) << endl;
	////cout << v2.value(4) << endl;
	////v3.value(8) = "hello";
	////cout << v3.value(8)<< endl;
	//int x = 12;
	//print(x);
	// -------------------------------------------
	//vector<int> vec{ 5,9,15,20,25 }; // testing functor
	//gr_th<int> gt_int(10);
	//gr_th<char> gt_cha('f');
	//gr_th<string> gt_str("hello");
	//bool b1 = gt_int(20);
	//bool b2 = gt_cha('a');
	//bool b3 = gt_str("welcome");
	//cout << b1 << "  " << b2 << "  " << b3;
	//cout << counter(vec, gt_int);
	// --------------------------------------------------
    vector<int> vec{ 5,9,15,20,25 }; // lambda expression
	int d = 4;
	int e = 5;
	for_each(vec.begin(), vec.end(),
		[=](int x) { // each lambda expression have 3 sections, [capture clause](input varibles){function definition}

			if (x % d == 0)
				cout << x << " is dividable by " << d << endl;
			else
				cout << x << " is not dividable by " << d <<endl;
		}
	);
	//[CC](IV){FD}

}

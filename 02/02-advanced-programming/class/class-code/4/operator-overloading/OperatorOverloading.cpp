// operator overloading was discussed in this project. at first, we overloaded the +
// operator for a string and int class.
// then we introduced a class called telegram, with 2 attributes, a string called name and an integer holding the name of the telegram channel
// we overload the + and << operators for telegram class. then, we moved the overloading functions to the class.
// then, we discussed the ++ operator for telegram and created a new class called collection,
// collection was meant to have list with telegram objects.
// we overload the += and -= for collection too and figured out the remove function in the list requiers a == operator in telegram class so we also overload that operator in telegram class
// then we discussed about friend keyword that allowes functions and other classes have access to the private attributes of class.
// we introduced = operator for class and figured out that classes also have a defaul overload for = like cope constructor.
// at last, we again used the vector class and overload the [] operator for this class.


#include <iostream>
#include <list>
#include <string>
using namespace std;
class telegram {// a class we used to learn overloading operators with it.
private:
	//string name
	// stirng members introduced to used in friend keyword
public:
	string name;
	int members;
	telegram(string n, int m) {
		name = n;
		members = m;
	}
	bool operator ==(const telegram t)const { // have to overload == to use remove in collection. inputs have to be const.
		return name == t.name;
	}
	explicit operator int() {// overloading typecasting for class telegram.
		return members;
	}
	telegram operator=(telegram t) {// overloading = operator so the default will not be used.
		members = t.members;
		return t;
	}
	telegram operator+(telegram t) {// overloading + operator with returning a new telegram object.
		telegram t1(name + " " + t.name
			,members + t.members);
		return t1;
	}
	void operator++() { // overloading ++ operator for telegram
		members = members + 100;
	}
	//friend ostream& operator<<(ostream& out, telegram t);	// introducing operator << as friend so it can have access to the private attributes of the class.
};
class collection {//class to have a list of telegrams
public:
	list <telegram> li;
	void operator+=(telegram t) { // overloading += operator to add a telegram to the list
		li.push_back(t);
	}
	void operator-= (telegram t) { // overloading -= operator to remove an object from the list
		li.remove(t);
	}
};
//string operator+(string s, int a ) {//overloading + class with a string and an integer as inputs
//	string p = s + " " + to_string(a);
//	return p;
//}
//ostream& operator<<(ostream& out, telegram t) {// overloading << operator to print a telegram object directly
//	out << "Channel " << t.name << " has "
//		<< t.members << " members" << endl;
//	return out;
//}
// using + and ++ operator outside of class.
//telegram operator+(telegram t1, telegram t2) {
//	telegram t3(t1.name + " " + t2.name
//		, t1.members + t2.members);
//	//t1.members = t1.members + t2.members;
//	//t1.name = t1.name + " " + t2.name;
//	return t3;
//}
//void operator++(telegram& t) {
//	t.members = t.members + 100;
//}
ostream& operator<<(ostream& out, telegram t) {
	out << "Channel " << t.name << " has "
		<< t.members << " members" << endl;
	return out;
}
ostream& operator<<(ostream& out, collection c) {//overloading << operator to print a list of telegrams directly
	for (telegram x : c.li) {
		out << x;
	}
	return out;
}
class vector {// this class needs no introduction anymore :)
private:
	int size;
	int* elem;
public:
	vector(int s) {
		size = s;
		elem = new int[s];
		for (int i = 0; i < s; i++) {
			elem[i] = 4;
		}
	}
	int& value(int index) { // using one function to get and set the wanted value. returning an int&

		return elem[index];
	}
	int& operator[](int index) {//overloading [] operator to have easier access to the vectors.
		return elem[index];
	}
};
int main()
{
	//int a = 5;
	//string s = "ali";
	//cout << s + a;
	//telegram t1("ali", 100);
	//telegram t2("AP", 400);
	//telegram t3 = t1 + t2;
	//collection c;
	//c += t1;
	//c += t2;
	//c += t3;
	//c -= t2;
	////cout << c;
	//double a = 8.5;
	//cout << 12 << 14 << 15;
	//telegram t1("ali", 100);
	//telegram t2("AP", 400);
	//telegram t3 = t1 = t2;
	//cout << t3;
	//vector v1(5);
	//v1.value(3) = 8;
	//cout << v1.value(3);
	vector v2(8);
	v2[3] = 8;
	cout << v2[3];
}

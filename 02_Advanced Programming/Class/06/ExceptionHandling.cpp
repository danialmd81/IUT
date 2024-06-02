#include <iostream>

using namespace std;

// class to throw an object of person
class person
{
private:
	int age;
	string name;

public:
	person()
	{
		age = 10;
		name = "mahdi";
	}
	string get_name() { return name; }
};

// a class with print function that needs some exceptions to be handled with.
class printer
{

private:
	string name;
	// available papers
	int AP;
	int a = 3;

public:
	printer(string n, int a)
	{
		name = n;
		AP = a;
	}
	void print(string txt)
	{
		// required papers
		int RP = txt.length() / 10;
		if (a == 0)
		{
			// throwing an int to show we can have multiple throws in the same scope of code
			throw 101;
		}
		if (AP < RP)
		{
			string s = "printer is empty";
			long a = 12;
			// main throw that will occur if the available pages are less than required pages
			throw a;
		}
		cout << "printing..." << txt << endl;
		AP = AP - RP;
		a--;
	}
};
// another example of exception handling
double divide(double a, double b)
{
	if (b == 0)
	{
		throw 10;
	}
	return a / b;
}

int main()
{
	printer p("HP", 5);
	// an exception might happen here so we write the code in a block of
	try
	{
		//  try and catch section
		p.print("Hello, I am Ali Iranidoust");
		p.print("Hello, I am Ali Iranidoust");
		p.print("Hello, I am Ali Iranidoust");
		p.print("Hello, I am Ali Iranidoust");
	}
	catch (double x)
	{
		cout << "error number " << x << "occurred";
	}
	catch (string x)
	{
		cout << x;
	}
	catch (person p)
	{
		cout << p.get_name();
	}
	catch (const char *txt)
	{
		cout << txt;
	}
	catch (...)
	{
		cout << "default catch was called";
	}

	// try
	// {
	// 	cout << divide(10, 5) << endl;
	// 	cout << divide(12, 6) << endl;
	// 	cout << divide(12, 0);
	// }
	// catch (int a)
	// {
	// 	cout << "cannot divide by zero";
	// }

	// // nested try and catch
	// try
	// {
	// 	try
	// 	{
	// 		// catch in line 62 is called
	// 		throw 10;
	// 	}
	// 	catch (int a)
	// 	{
	// 		cout << a << " this was an internal catch" << endl;
	// 		throw 20;
	// 		// catch in line 68 is called
	// 	}
	// 	person p1;
	// 	throw p1;
	// 	// catch in line 69 is called because it is in the outer
	// 	// try and will call the default catch
	// }
	// catch (int a)
	// {
	// 	cout << a << " this was an external catch";
	// }
	// catch (...)
	// {
	// 	cout << "default was called";
	// }
}

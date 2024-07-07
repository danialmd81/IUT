// C++ program to illustrate dynamic allocation
// and deallocation of memory using new and delete
#include <iostream>
using namespace std;

int main ()
{
    /*
    The new operator can’t be used to allocate
    a function, but it can be used to allocate
    pointers to functions. The following example
    allocates an array of 10 pointers to functions
    (taking no argument and returning int)
    */
    int (**c)() = new (int(*[10])());
    /*
    How to initialize the dynamic array with default (0) value in C++?
    */
    int *piValue = NULL;
    //implement empty parenthesis
    piValue = new int[10]();
    for(int index = 0; index < 10; index++)
    {
        cout<< "Array value = "<< *(piValue+index)<<endl;
    }
    delete [] piValue;

	// Pointer initialization to null
	int* p = NULL;

	/*Request memory for the variable
	using new operator
    */
   /*To avoid the exception throw we can use “nothrow” with
   the new operator. When we are used “nothrow” with the new
    operator, it returns a valid address if it is available
    otherwise it returns a null pointer.
    But here one point needs to remember we need to include file <new>
    for the use of “nothrow” with the new operator.*/
	p = new(nothrow) int;
	if (!p)
		cout << "allocation of memory failed\n";
	else
	{
		// Store value at allocated address
		*p = 29;
		cout << "Value of p: " << *p << endl;
	}

	/* Request block of memory
	using new operator*/
	float *r = new float(75.25);

	cout << "Value of r: " << *r << endl;

	// Request block of memory of size n
	int n = 5;
	int *q = new(nothrow) int[n];

	if (!q)
		cout << "allocation of memory failed\n";
	else
	{
		for (int i = 0; i < n; i++)
			q[i] = i+1;

		cout << "Value store in block of memory: ";
		for (int i = 0; i < n; i++)
			cout << q[i] << " ";
	}

	// freed the allocated memory
	delete p;
	delete r;

	// freed the block of allocated memory
	delete[] q;

	return 0;
}

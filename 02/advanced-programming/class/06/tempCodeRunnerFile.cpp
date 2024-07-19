// nested try and catch
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
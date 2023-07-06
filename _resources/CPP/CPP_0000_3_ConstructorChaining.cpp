// XYZPoint C++ program to demonstrate need of
// constructor delegation.
#include <iostream>
using namespace std;

class XYZPoint {
	int x, y, z;

public:

// 	XYZPoint()
// 	{
// 		x = 0;
// 		y = 0;
// 		z = 0;
// 	}
	
	// This top constructor can also be declared as followed.
	// but only one can be compiled. So comment out the other
	// otherwise you will have this error:
	/*
    main.cpp:32:2: error: ‘XYZPoint::XYZPoint()’ cannot be overloaded with ‘XYZPoint::XYZPoint()’
       32 |  XYZPoint():
          |  ^~~~~~~~
    main.cpp:11:2: note: previous declaration ‘XYZPoint::XYZPoint()’
       11 |  XYZPoint()
          |  ^~~~~~~~
    	
	*/
	
	// we can also have the Constructor initialize its member using member initialization list
	XYZPoint():
	x(0),           // member initialization list start
	y(0),
	z(0)            // member initialization list end
	{
	}
	
	// Constructor delegation
	XYZPoint(int z):
	XYZPoint()
	{
		/* Only initialize z by passing an argument,
		while all the other arguments are
		initialized the same way they were,
		as in the previous constructor*/
		this->z = z;  // Legal
		// because of the constructor delegation, we can't have z in the
		// member initialization list.
	}
	
	// ILLEGAL Constructor delegation. This is not C# or Java, we can't use the 
	// keyword ``this`` to call the other constructor
// 	XYZPoint(int z):
// 	this()
// 	{
// 		this->z = z;
// 	}
	
	// Constructor delegation with mem-initializer error
// 	XYZPoint(int z):
// 	XYZPoint(),
// 	z(z) // ==> ILLEGAL main.cpp:55:5: error: mem-initializer for ‘XYZPoint::z’ follows constructor delegation
// 	{
// 	}

	void show()
	{
		cout << "Point: (" << x << "," << y << "," << z << ")" << endl;
		     
	}
};

int main()
{   
    // Different ways of creating class objects
    cout << "Declaring an object without explicitly calling the constructor" << endl;
    XYZPoint point;  // this call the no-arg constructor to instantiate the object.
	point.show();
	
// 	XYZPoint point(3); // ILLEGAL Can't have the same name as above "error: main.cpp:43:11: error: redeclaration of ‘XYZPoint point’"
// 	point.show();
    
    cout << "Declaring an object using the parameterized constructor" << endl;
	XYZPoint point1(3);
	point1.show();
	
	cout << "\nCreating point object using constructor directly" << endl;
	XYZPoint point2 = XYZPoint(5);
	point2.show();
	
	cout << "\nCreating point object using pointer return by the ``new`` operator" << endl;
	XYZPoint* point3 = new XYZPoint(7);
	point3->show();
	delete point3;
	return 0;
}

/*
[OuputSectionStart]
Declaring an object without explicitly calling the constructor
Point: (0,0,0)
Declaring an object using the parameterized constructor
Point: (0,0,3)

Creating point object using constructor directly
Point: (0,0,5)

Creating point object using pointer return by the ``new`` operator
Point: (0,0,7)


...Program finished with exit code 0
Press ENTER to exit console.
[OuputSectionEnd]
*/
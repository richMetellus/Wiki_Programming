// XYZPoint C++ program to demonstrate need of
// constructor delegation.
#include <iostream>
using namespace std;

class XYZPoint {
	int x, y, z;

public:
	XYZPoint()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	XYZPoint(int z)
	{
		// The below two lines are redundant
		// we will use constructor delegation later to avoid redundant code
		x = 0;
		y = 0;

		/* Only initialize z by passing an argument,
		while all the other arguments are
		initialized the same way they were,
		as in the previous constructor*/
		this->z = z;
	}

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
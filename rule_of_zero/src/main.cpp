#include "InstrumentedClass.h"
#include <vector>
#include <string>

struct Widget : public InstrumentedClass {
public:
    std::string s;
    std::vector<int> v;
};

Widget f(Widget w)
{
    return w;
}

int main(int argc, char *argv[])
{
	std::cout << "Widget w1" << std::endl;
    Widget w1;						// default construct

std::cout << "\nWidget w3{w1}" << std::endl;
    Widget w3{ w1 };				// copy constructor

std::cout << "\nWidget w4 = w3" << std::endl;
	Widget w4 = w3;					// copy constructor

	std::cout << "w3 = w1" << std::endl;
	w3 = w1;						// Assignement operator

	std::cout << "\nWidget w5 = std::move(w3)" << std::endl;
    Widget w5 = std::move(w3);      // Move constructor

	std::cout << "\nw5 = std::move(w1)" << std::endl;
    w5 = std::move(w1);				// Move Assignemnt

	std::cout << "\nWidget w6 = f(w5)" << std::endl;
	Widget w6 = f(w5);

	return 0;
}

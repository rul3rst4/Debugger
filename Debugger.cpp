#include <iostream>

#include "App.h"

int main()
{
	try
	{
		auto app = new App();
		app->run();
	}
	catch (...)
	{
		std::cout << "Error on main..." << std::endl;
	}
}
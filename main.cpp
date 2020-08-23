#include <iostream>
#include <thread>
#include "App.h"

class UiWrapper : public System::Task
{
public:
	void run() override
	{
		auto* app = new App();
		app->run();
	}
};

int main()
{
	try
	{
		System::push_task(new UiWrapper());
		System::wait();
	}
	catch (...)
	{
		std::cout << "Error on main..." << std::endl;
	}
}
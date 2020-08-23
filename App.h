#pragma once
#include <SFML/Graphics.hpp>
#include "json.hpp"
#include "GUI.cpp"
#include "SysManager.cpp"


class App : public System::Task
{
public:
	App();
	void update();
	void render();
	void update_event();
	void run() override;

private:
	sf::RenderWindow window;
	nlohmann::json config;
	GUI ui;
};


#pragma once
#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>
#include "imgui.h"
#include "imgui-SFML.h"
#include "json.hpp"


class App
{
public:
	App();
	void update();
	void render();
	void update_event();
	void run();

private:
	sf::RenderWindow window;
	nlohmann::json config;
};


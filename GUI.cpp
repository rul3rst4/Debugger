#include <imgui-SFML.h>
#include <iostream>

#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics/RenderWindow.hpp>

class GUI
{
/// <summary>
/// Props
/// </summary>
public:
	bool schedule_window_init = false;
	sf::RenderWindow& window_ref;

	// methods
public:
	GUI(sf::RenderWindow& window) : window_ref(window)
	{
		ImGui::SFML::Init(window);
	}

	void draw(sf::Clock& deltaClock)
	{
		ImGui::SFML::Update(window_ref, deltaClock.restart());

		static bool open = true;
		ImGui::ShowDemoWindow(&open);

		ImGui::Begin("Hello, world!");
		ImGui::Button("Look at this pretty button");
		ImGui::End();
	}

	void processEvent(sf::Event& event)
	{
		ImGui::SFML::ProcessEvent(event);
	}

	void render()
	{
		ImGui::SFML::Render(window_ref);
	}
};

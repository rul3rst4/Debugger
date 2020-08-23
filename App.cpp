#include "App.h"
#include <fstream>

App::App()
{
  window.setFramerateLimit(60);

  std::ifstream cfg("config.json");
  cfg >> config;

  int width = config["window"]["width"].get<int>();
  int height = config["window"]["height"].get<int>();
  
  window.create(sf::VideoMode(width, height),"App");
  ImGui::SFML::Init(window);
}



void App::update()
{
  window.resetGLStates();
  sf::Clock deltaClock;
  while (window.isOpen()) {
    this->update_event();
		ImGui::SFML::Update(window, deltaClock.restart());

    static bool open = true;
    ImGui::ShowDemoWindow(&open);

    ImGui::Begin("Hello, world!");
    ImGui::Button("Look at this pretty button");
    ImGui::End();

    this->render();
  }

  ImGui::SFML::Shutdown();
}

void App::render()
{
  window.clear();
  ImGui::SFML::Render(window);
  window.display();
}

void App::update_event()
{
  sf::Event event;
  while (window.pollEvent(event)) {
    ImGui::SFML::ProcessEvent(event);

    if (event.type == sf::Event::Closed) {
      window.close();
    }
  }
}

void App::run()
{
  this->update();
}

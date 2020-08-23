#include "App.h"
#include <fstream>

App::App():window(sf::VideoMode(800, 600), "App"),ui(window)
{
  //window.setFramerateLimit(60);

  std::ifstream cfg("config.json");
  cfg >> config;

  int width = config["window"]["width"].get<int>();
  int height = config["window"]["height"].get<int>();

	if((width | height) != 0) window.setSize(sf::Vector2u(width, height));
}



void App::update()
{
  sf::Clock deltaClock;
  while (window.isOpen()) {
    this->update_event();
    ui.draw(deltaClock);
    this->render();
  }

  ImGui::SFML::Shutdown();
}

void App::render()
{
  window.clear();
  ui.render();
  window.display();
}

void App::update_event()
{
  sf::Event event;
  while (window.pollEvent(event)) {
    ui.processEvent(event);

    if (event.type == sf::Event::Closed) {
      window.close();
    }
  }
}

void App::run()
{
  this->update();
}

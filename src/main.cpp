#include <SFML/Graphics.hpp>
#include <iostream>
#include "curves.h"
#include <glm/ext.hpp>

/**
 * This program tries to draw a cubic Bezier curve, but shows nothing initially because
 * curves.cpp is incomplete.
 */

void drawPixel(sf::RenderWindow& window, glm::ivec2 position, sf::Color color) {
	float pX{ static_cast<float>(position.x) };
	float pY{ static_cast<float>(position.y) };

	sf::Vertex pixel[1]{
		sf::Vector2f{pX, pY},
		color
	};
	window.draw(pixel, 1, sf::PrimitiveType::Points);
}

int main() {
	sf::RenderWindow window{ sf::VideoMode::getFullscreenModes().at(0), "SFML Demo" };
	sf::Clock c;
	auto last{ c.getElapsedTime() };
	while (window.isOpen()) {
		// Check for events.
		while (const std::optional event{ window.pollEvent() }) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
		}

		auto now{ c.getElapsedTime() };
		auto diff{ now - last };
		std::cout << 1 / diff.asSeconds() << " FPS " << std::endl;
		last = now;

		window.clear();
		drawCircleParametric(window, glm::ivec2{ 400, 300 }, 200, sf::Color::White);
		//drawBezierCubic(window, glm::ivec2{ 100, 600 }, glm::ivec2{ 300, 100 },
		//	glm::ivec2{ 500, 800 }, glm::ivec2{ 700, 400 }, sf::Color::Yellow);
		window.display();
	}

	return 0;
}



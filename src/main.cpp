#include <SFML/Graphics.hpp>
#include <iostream>
#include "curves.h"

/**
 * This program tries to draw a cubic Bezier curve, but shows nothing initially because
 * curves.cpp is incomplete.
 */

void drawPixel(sf::RenderWindow& window, sf::Vector2i position, sf::Color color) {
	float pX{ static_cast<float>(position.x) };
	float pY{ static_cast<float>(position.y) };

	std::array<sf::Vertex, 1> pixel{
		sf::Vertex{
			sf::Vector2f{pX, pY},
			color
		}
	};
	window.draw(pixel.data(), 1, sf::PrimitiveType::Points);
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
		drawBezierCubic(window, sf::Vector2i{ 100, 600 }, sf::Vector2i{ 300, 100 },
			sf::Vector2i{ 500, 800 }, sf::Vector2i{ 700, 400 }, sf::Color::Yellow);
		window.display();
	}

	return 0;
}



#include <SFML/Graphics.hpp>
#include <iostream>
#include "curves.h"

/**
 * This program draws a triangle. It uses drawLineNaiveLow by default, so the triangle 
 * doesn't look pretty. Once you copy over your lines.h and lines.cpp from Homework 1,
 * the triangle should render correctly.
 */

void drawPixel(sf::RenderWindow& window, sf::Vector2i position, sf::Color color) {
	sf::Vertex pixel[1] = {
		sf::Vertex(sf::Vector2f(position.x, position.y), color)
	};
	window.draw(pixel, 1, sf::Points);
}

int main() {
	sf::RenderWindow window{ sf::VideoMode{800, 800}, "SFML Demo" };
	sf::Clock c;
	auto last = c.getElapsedTime();

	while (window.isOpen()) {
		sf::Event ev;
		while (window.pollEvent(ev)) {
			if (ev.type == sf::Event::Closed)
				window.close();
		}
		window.clear();

		auto now = c.getElapsedTime();
		auto diff = now - last;
		last = now;
		std::cout << 1 / diff.asSeconds() << " FPS " << std::endl;
		
		drawBezierCubic(window, sf::Vector2i(100, 600), sf::Vector2i(300, 100),
			sf::Vector2i(500, 800), sf::Vector2i(700, 400), sf::Color::Yellow);

		window.display();
	}

	return 0;
}



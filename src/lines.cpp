#include "lines.h"
#include <SFML/Graphics.hpp>
/**
 * @brief Draws a low-slope line using a naive algorithm.
 * @param window the SFML window to draw to.
 * @param start the starting point of the line.
 * @param end the ending point of the line.
 * @param color the color of the line.
 */
void drawLineNaive(sf::RenderWindow& window, glm::ivec2 start, glm::ivec2 end, sf::Color color) {
	if (start.x > end.x) {
		std::swap(start, end);
	}

	double m{ static_cast<double>(end.y - start.y) / (end.x - start.x) };

	// The first point on the line is (start.x, start.y).
	int32_t x{ start.x };

	// We separately track where y *should be*, and also which integer y value is closest to that.
	double yReal{ static_cast<double>(start.y) };
	int32_t yPixel{ start.y };

	while (x <= end.x) {
		drawPixel(window, glm::ivec2{ x, yPixel }, color);
		// x always goes up by 1.
		++x;
		// yReal increases by m.
		yReal += m;
		// yPixel is the rounded yReal.
		yPixel = static_cast<int32_t>(std::round(yReal));
	}
}


void drawLine(sf::RenderWindow& window, glm::ivec2 start, glm::ivec2 end, sf::Color color) {
//	drawLineNaive(window, start, end, color);
	float sX{ static_cast<float>(start.x) };
	float sY{ static_cast<float>(start.y) };
	float eX{ static_cast<float>(end.x) };
	float eY{ static_cast<float>(end.y) };
	std::array<sf::Vertex, 2> points{
		sf::Vertex{sf::Vector2f{sX, sY}, color},
		sf::Vertex{sf::Vector2f{eX, eY}, color}
	};
	window.draw(points.data(), 2, sf::PrimitiveType::Lines);
}


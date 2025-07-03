#include "curves.h"
#include "lines.h"
#define _USE_MATH_DEFINES
#include <math.h>

void drawCircleNaive(sf::RenderWindow& window, sf::Vector2i center, int32_t radius, sf::Color color)
{
	for (int32_t y1{ center.y - radius }; y1 < center.y + 1; ++y1) {
		int32_t sq{ static_cast<int32_t>(std::sqrt(radius * radius - (y1 - center.y) * (y1 - center.y))) };
		int32_t x1{ static_cast<int32_t>(center.x - sq) };
		int32_t x2{ static_cast<int32_t>(center.x + sq) };

		// Use symmetry to find the other scan line on the other semicircle 
		// with the same x coordinates.
		int32_t y2{ 2 * center.y - y1 };

		// Draw pixels at the endpoints of the scan lines.
		drawPixel(window, sf::Vector2i{ x1, y1 }, color);
		drawPixel(window, sf::Vector2i{ x2, y1 }, color);
		drawPixel(window, sf::Vector2i{ x1, y2 }, color);
		drawPixel(window, sf::Vector2i{ x2, y2 }, color);
	}
}


void fillCircleNaive(sf::RenderWindow& window, sf::Vector2i center,
	int32_t radius, sf::Color color) {

	for (int32_t y1{ center.y - radius }; y1 < center.y + 1; ++y1) {
		int32_t sq{ static_cast<int32_t>(std::sqrt(radius * radius - (y1 - center.y) * (y1 - center.y))) };
		int32_t x1{ static_cast<int32_t>(center.x - sq) };
		int32_t x2{ static_cast<int32_t>(center.x + sq) };

		// Use symmetry to find the other scan line on the other semicircle 
		// with the same x coordinates.
		int32_t y2{ 2 * center.y - y1 };

		// Draw horizontal scan lines.
		for (auto i{ x1 }; i < x2 + 1; ++i) {
			drawPixel(window, sf::Vector2i{ i, y1 }, color);
			drawPixel(window, sf::Vector2i{ i, y2 }, color);
		}
	}
}



void drawCircleParametric(sf::RenderWindow& window, sf::Vector2i center, int32_t radius, sf::Color color)
{
	// How many vertices to plot along the circumference?
	auto incr{ 2 * M_PI / 70 };

	sf::Vector2i last{ center.x + radius, center.y };


	for (auto t{ 0.0 }; t <= 2 * M_PI; t += incr) {
		int32_t x{ static_cast<int32_t>(std::round(center.x + radius * cos(t))) };
		int32_t y{ static_cast<int32_t>(std::round(center.y + radius * sin(t))) };
		sf::Vector2i next{ x, y };

		drawLine(window, last, next, color);
		last = next;
	}
}

// TODO: complete this function.
void drawBezierCubic(sf::RenderWindow& window, sf::Vector2i p0, sf::Vector2i p1, sf::Vector2i p2,
	sf::Vector2i p3, sf::Color color) {
}


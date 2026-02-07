#include "curves.h"
#include "lines.h"
#define _USE_MATH_DEFINES
#include <math.h>

void drawCircleNaive(sf::RenderWindow& window, glm::ivec2 center, int32_t radius, sf::Color color)
{
	for (int32_t y1{ center.y - radius }; y1 < center.y + 1; ++y1) {
		int32_t sq{ static_cast<int32_t>(std::sqrt(radius * radius - (y1 - center.y) * (y1 - center.y))) };
		int32_t x1{ static_cast<int32_t>(center.x - sq) };
		int32_t x2{ static_cast<int32_t>(center.x + sq) };

		// Use symmetry to find the other scan line on the other semicircle 
		// with the same x coordinates.
		int32_t y2{ 2 * center.y - y1 };

		// Draw pixels at the endpoints of the scan lines.
		drawPixel(window, glm::ivec2{ x1, y1 }, color);
		drawPixel(window, glm::ivec2{ x2, y1 }, color);
		drawPixel(window, glm::ivec2{ x1, y2 }, color);
		drawPixel(window, glm::ivec2{ x2, y2 }, color);
	}
}


void fillCircleNaive(sf::RenderWindow& window, glm::ivec2 center,
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
			drawPixel(window, glm::ivec2{ i, y1 }, color);
			drawPixel(window, glm::ivec2{ i, y2 }, color);
		}
	}
}



void drawCircleParametric(sf::RenderWindow& window, glm::ivec2 center, int32_t radius, sf::Color color)
{
	const int32_t numVertices{ 1000 };
	// How many vertices to plot along the circumference?
	const float incr{ 2 * glm::pi<float>() / numVertices };

	glm::ivec2 last{ center.x + radius, center.y };

	for (auto t{ 0.0 }; t <= 2 * glm::pi<float>(); t += incr) {
		int32_t x{ static_cast<int32_t>(std::round(center.x + radius * cos(t))) };
		int32_t y{ static_cast<int32_t>(std::round(center.y + radius * sin(t))) };
		glm::ivec2 next{ x, y };

		drawPixel(window, next, color);
	//	drawLine(window, last, next, color);
		last = next;
	}
}

// TODO: complete this function.
void drawBezierCubic(sf::RenderWindow& window, glm::ivec2 p0, glm::ivec2 p1, glm::ivec2 p2,
	glm::ivec2 p3, sf::Color color) {
}


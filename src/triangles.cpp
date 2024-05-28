#include "triangles.h"
#include "lines.h"

void drawTriangle(sf::RenderWindow& window, sf::Vector2i a, sf::Vector2i b,
	sf::Vector2i c, sf::Color color) {
	drawLine(window, a, b, color);
	drawLine(window, a, c, color);
	drawLine(window, b, c, color);
}

void fillTriangleScan(sf::RenderWindow& window, sf::Vector2i a, sf::Vector2i b, sf::Vector2i c, sf::Color color) {
	// First, sort the vertices by y coordinate.
	if (a.y > b.y) {
		std::swap(a, b);
	}
	if (a.y > c.y) {
		std::swap(a, c);
	}
	if (b.y > c.y) {
		std::swap(b, c);
	}

	// Draw the upper segment of the triangle: the lines connecting edge AB with part of AC.

	// First find the inverse slope of AB and AC.
	double imAB = (static_cast<double>(b.x) - a.x) / (b.y - a.y);
	double imAC = (static_cast<double>(c.x) - a.x) / (c.y - a.y);

	// We will "walk" down the lines by repeatedly adding the inverse slope
	// to an x - coordinate accumulator for each line segment, starting at point A.
	double xAB = a.x;
	double xAC = a.x;

	drawPixel(window, a, color);
	// For the vertical range of edge AB:
	for (auto y = a.y + 1; y < b.y; y++) {
		// Compute the x coordinate for edge AB and AC by moving their current coordinate
		// by their inverse slope.
		xAB = xAB + imAB;
		xAC = xAC + imAC;

		// Connect the two points with a horizontal line.
		// Make sure the range goes in increasing order from left to right.
		auto l = static_cast<int32_t>(std::min(xAB, xAC));
		auto r = static_cast<int32_t>(std::max(xAB, xAC));
		for (auto x = l; x < r + 1; x++) {
			drawPixel(window, sf::Vector2i { x, y }, color);
		}
	}

	// Repeat the logic of walking down and connecting points 
	// on lines AC and BC. 
	double imBC = (static_cast<double>(c.x) - b.x) / (c.y - b.y);
	double xBC = b.x;
	for (auto y = b.y; y < c.y + 1; y++) {
		xBC = xBC + imBC;
		xAC = xAC + imAC;

		auto l = static_cast<int32_t>(std::min(xBC, xAC));
		auto r = static_cast<int32_t>(std::max(xBC, xAC));
		for (auto x = l; x < r + 1; x++) {
			drawPixel(window, sf::Vector2i { x, y }, color);
		}
	}
}

bool insideBary2(sf::Vector2i p, sf::Vector2i a, sf::Vector2i b, sf::Vector2i c) {
	auto s1 = static_cast<double>(c.y) - a.y;
	auto s2 = static_cast<double>(c.x) - a.x;
	auto s3 = static_cast<double>(b.y) - a.y;
	auto s4 = static_cast<double>(p.y) - a.y;
	auto w1 = static_cast<double>(a.x * s1 + s4 * s2 - p.x * s1) / (s3 * s2 - (b.x - a.x) * s1);
	auto w2 = static_cast<double>(s4 - w1 * s3) / s1;
	return w1 >= 0 && w2 >= 0 && w1 + w2 <= 1;
}

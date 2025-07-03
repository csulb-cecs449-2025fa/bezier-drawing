#include "lines.h"
#include <SFML/Graphics.hpp>

/**
 * @brief Draws a low-slope line using a naive algorithm.
 * @param window the SFML window to draw to.
 * @param start the starting point of the line.
 * @param end the ending point of the line.
 * @param color the color of the line.
 */
void drawLineNaive(sf::RenderWindow& window, sf::Vector2i start,
    sf::Vector2i end, sf::Color color) {

    // Make sure the line goes from left to right.
    if (start.x > end.x) {
        std::swap(start, end);
    }

    // Compute m ahead of time.
    double m{ static_cast<double>(end.y - start.y) / (end.x - start.x) };
    double y{ start.y };

    // In each step of the loop, x goes up by 1 and y goes up by m.
    for (auto x{ start.x }; x < end.x + 1; ++x) {
        // Round the fractional y to the nearest integer pixel.
        auto yCoord{ static_cast<int32_t>(std::round(y)) };
        drawPixel(window, sf::Vector2i{ x, yCoord }, color);
        y += m;
    }
}


void drawLine(sf::RenderWindow& window, sf::Vector2i start, sf::Vector2i end, sf::Color color) {
	drawLineNaive(window, start, end, color);
}
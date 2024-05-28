#pragma once
#include <SFML/Graphics.hpp>

void drawCircleNaive(sf::RenderWindow& window, sf::Vector2i center, uint32_t radius, sf::Color color);
void fillCircleNaive(sf::RenderWindow& window, sf::Vector2i center, uint32_t radius, sf::Color color);
void drawCircleParametric(sf::RenderWindow& window, sf::Vector2i center, int32_t radius, sf::Color color);
void drawBezierCubic(sf::RenderWindow& window, sf::Vector2i p0, sf::Vector2i p1, sf::Vector2i p2, sf::Vector2i p3, sf::Color color);
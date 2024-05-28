#pragma once
#include <SFML/Graphics.hpp>
void drawTriangle(sf::RenderWindow& window, sf::Vector2i a, sf::Vector2i b, sf::Vector2i c, sf::Color color);
void fillTriangleScan(sf::RenderWindow& window, sf::Vector2i a, sf::Vector2i b, sf::Vector2i c, sf::Color color);
void fillTriangleBound(sf::RenderWindow& window, sf::Vector2i a, sf::Vector2i b, sf::Vector2i c, sf::Color color);
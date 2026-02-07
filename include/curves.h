#pragma once
#include <SFML/Graphics.hpp>
#include <glm/ext.hpp>
void drawCircleNaive(sf::RenderWindow& window, glm::ivec2 center, int32_t radius, sf::Color color);
void fillCircleNaive(sf::RenderWindow& window, glm::ivec2 center, int32_t radius, sf::Color color);
void drawCircleParametric(sf::RenderWindow& window, glm::ivec2 center, int32_t radius, sf::Color color);
void drawBezierCubic(sf::RenderWindow& window, glm::ivec2 p0, glm::ivec2 p1, glm::ivec2 p2, glm::ivec2 p3, sf::Color color);
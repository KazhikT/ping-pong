#include "A:\pract\tetris\Paddle.h"
#include< A:\pract\tetris\Ball.h >
void update() {
    if (player1) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && x > 0) {
            x -= speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && x + paddleShape.getSize().x < windowWidth) {
            x += speed;
        }
    }
    else {
        if (sf::Keyboard::isKeyPressed(leftKey) && x > 0) {
            x -= speed;
        }
        if (sf::Keyboard::isKeyPressed(rightKey) && x + paddleShape.getSize().x < windowWidth) {
            x += speed;
        }
    }
    paddleShape.setPosition(x, y);
}
sf::RectangleShape getShape() {
    return paddleShape;
}
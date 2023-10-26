#include <A:\pract\tetris\Ball.h>
#include< A:\pract\tetris\Paddle.h >
void update() {
    x += speedX;
    y += speedY;

    if (x < 0 || x > windowWidth) {
        speedX = -speedX; // ������ �� ����� � ������ ������ ����
    }

    if (y < 0 || y > windowHeight) {
        speedY = -speedY; // ������ �� ������� � ������ ������ ����
    }

    ballShape.setPosition(x, y);
}

sf::CircleShape getShape() {
    return ballShape;
}

void resetPosition() {
    x = windowWidth / 2;
    y = windowHeight / 2;
    ballShape.setPosition(x, y);
}

void launch() {
    // �������� ����������� ������ ��� ������� ����
}

sf::Vector2f getPosition() {
    return sf::Vector2f(x, y);
}
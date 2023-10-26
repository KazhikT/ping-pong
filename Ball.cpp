#include <A:\pract\tetris\Ball.h>
#include< A:\pract\tetris\Paddle.h >
void update() {
    x += speedX;
    y += speedY;

    if (x < 0 || x > windowWidth) {
        speedX = -speedX; // Отскок от левой и правой границ окна
    }

    if (y < 0 || y > windowHeight) {
        speedY = -speedY; // Отскок от верхней и нижней границ окна
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
    // Добавьте необходимую логику для запуска мяча
}

sf::Vector2f getPosition() {
    return sf::Vector2f(x, y);
}
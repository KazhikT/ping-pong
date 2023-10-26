#ifndef BALL_H
#define BALL_H


float ballSpeedX = 0.3f;
float ballSpeedY = 0.3f;
class Ball {
public:
    Ball(float startX, float startY)
        : x(startX), y(startY) {
        ballShape.setRadius(10);
        ballShape.setPosition(x, y);
        ballShape.setFillColor(sf::Color::White);
        speedX = ballSpeedX;
        speedY = ballSpeedY;
    }

    void update();

    sf::CircleShape getShape();

    void resetPosition();

    void launch();

    sf::Vector2f getPosition();

private:
    sf::CircleShape ballShape;
    float x, y;
    float speedX, speedY;
};
#endif
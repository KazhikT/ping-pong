
#ifndef PADDLE_H
#define PADDLE_H
class Paddle {
public:
    Paddle(float startX, float startY, sf::Keyboard::Key leftKey, sf::Keyboard::Key rightKey, bool isPlayer1)
        : leftKey(leftKey), rightKey(rightKey), player1(isPlayer1) {
        x = startX;
        y = startY;
        paddleShape.setSize(sf::Vector2f(100, 20));
        paddleShape.setPosition(x, y);
        paddleShape.setFillColor(sf::Color::White);
        speed = 0.3f;
    }

    void update();

    sf::RectangleShape getShape();

private:
    sf::RectangleShape paddleShape;
    float x, y;
    float speed;
    sf::Keyboard::Key leftKey, rightKey;
    bool player1;
};
#endif
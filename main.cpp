#include <SFML/Graphics.hpp>

class PongGame {
private:
    sf::RenderWindow window;
    sf::RectangleShape paddle1;
    sf::RectangleShape paddle2;
    sf::CircleShape ball;
    sf::Vector2f ballVelocity;
    int paddleSpeed;
    int ballSpeed;
    int scorePlayer1;
    int scorePlayer2;

public:
    PongGame(int width, int height) {
        window.create(sf::VideoMode(width, height), "Pong Game");
        window.setFramerateLimit(60);

        paddle1.setSize(sf::Vector2f(10, 60));
        paddle1.setFillColor(sf::Color::Green);
        paddle1.setPosition(10, height / 2 - paddle1.getSize().y / 2);

        paddle2.setSize(sf::Vector2f(10, 60));
        paddle2.setFillColor(sf::Color::Green);
        paddle2.setPosition(width - paddle2.getSize().x - 10, height / 2 - paddle2.getSize().y / 2);

        ball.setRadius(5);
        ball.setFillColor(sf::Color::White);
        ball.setPosition(width / 2 - ball.getRadius(), height / 2 - ball.getRadius());
        ballVelocity = sf::Vector2f(-3, 1);

        paddleSpeed = 5;
        ballSpeed = 4.5;
        scorePlayer1 = 0;
        scorePlayer2 = 0;
    }

    void resetBall() {
        ball.setPosition(window.getSize().x / 2 - ball.getRadius(), window.getSize().y / 2 - ball.getRadius());
        ballVelocity = sf::Vector2f(-3, 1);
    }

    void update() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && paddle2.getPosition().y > 0) {
            paddle2.move(0, -paddleSpeed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
            paddle2.getPosition().y + paddle2.getSize().y < window.getSize().y) {
            paddle2.move(0, paddleSpeed);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && paddle1.getPosition().y > 0) {
            paddle1.move(0, -paddleSpeed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
            paddle1.getPosition().y + paddle1.getSize().y < window.getSize().y) {
            paddle1.move(0, paddleSpeed);
        }

        ball.move(ballVelocity);

        if (ball.getGlobalBounds().intersects(paddle1.getGlobalBounds()) ||
            ball.getGlobalBounds().intersects(paddle2.getGlobalBounds())) {
            ballVelocity.x = -ballVelocity.x;
        }

        if (ball.getPosition().y < 0 || ball.getPosition().y + ball.getRadius() * 2 > window.getSize().y) {
            ballVelocity.y = -ballVelocity.y;
        }

        if (ball.getPosition().x < 0) {
            scorePlayer2++;
            resetBall();
        }

        if (ball.getPosition().x > window.getSize().x) {
            scorePlayer1++;
            resetBall();
        }
    }

    void render() {
        window.clear();
        window.draw(paddle1);
        window.draw(paddle2);
        window.draw(ball);

        sf::Font font;
        font.loadFromFile("A:\\pract\\tetris\\cabana.ttf"); // Замените "arial.ttf" на путь к вашему шрифту

        sf::Text scoreText;
        scoreText.setFont(font);
        scoreText.setCharacterSize(30);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setPosition(window.getSize().x / 2 - 20, 10);
        scoreText.setString(std::to_string(scorePlayer1) + " - " + std::to_string(scorePlayer2));
        window.draw(scoreText);

        window.display();
    }

    void run() {
        while (window.isOpen()) {
            update();
            render();
        }
    }
};

int main() {
    PongGame game(800, 600);
    game.run();

    return 0;
}

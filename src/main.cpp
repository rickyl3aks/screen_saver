#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 600), "ScreenSaver");
    window.setFramerateLimit(60);

    sf::RectangleShape rect;
    sf::CircleShape circle(50);

    // rect
    sf::Vector2f rectanglePosition(700 / 2, 600 / 2);
    rect.setPosition(rectanglePosition);
    rect.setSize(sf::Vector2f(100, 100));

    // circle
    sf::Vector2f circle_position(600 / 2, 500 / 2);
    circle.setPosition(circle_position);
    circle.setFillColor(sf::Color(100, 250, 200));

    float x_circle_velocity = 4;
    float y_circle_velocity = 5;

    float xVelocity = 3;
    float yVelocity = 3;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        // physics
        if (rectanglePosition.x < 0 || rectanglePosition.x > 700 - 100)
        {
            xVelocity *= -1;
        }

        if (rectanglePosition.y < 0 || rectanglePosition.y > 600 - 100)
        {
            yVelocity *= -1;
        }

        if (circle_position.x < 0 || circle_position.x > 700 - 100)
        {
            x_circle_velocity *= -1;
        }

        if (circle_position.y < 0 || circle_position.y > 600 - 100)
        {
            y_circle_velocity *= -1;
        }

        rectanglePosition.x += xVelocity;
        rectanglePosition.y += yVelocity;
        rect.setPosition(rectanglePosition);

        circle_position.x += x_circle_velocity;
        circle_position.y += y_circle_velocity;
        circle.setPosition(circle_position);

        // render
        window.clear();
        window.draw(rect);
        window.draw(circle);
        window.display();
    };

    return 0;
}
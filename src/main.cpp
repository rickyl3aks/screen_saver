#include <SFML/Graphics.hpp>
#include <iostream>

float x_circle_velocity = 4;
float y_circle_velocity = 5;

float x_rect_velocity = 3;
float y_rect_velocity = 3;

class Moving_shape
{
public:
    sf::Vector2f position;

public:
    void moving_shape_rect(float pos_x, float pos_y, float x, float second_x, float y, float velocity_x, float velocity_y)
    {
        position.x = pos_x;
        position.y = pos_y;

        if (pos_x < 0 || pos_x > x - y)
        {
            x_rect_velocity = velocity_x *= -1;
        }
        if (pos_y < 0 || pos_y > second_x - y)
        {
            y_rect_velocity = velocity_y *= -1;
        }
    }

public:
    void moving_shape_circle(float pos_x, float pos_y, float x, float second_x, float y, float velocity_x, float velocity_y)
    {
        position.x = pos_x;
        position.y = pos_y;

        if (pos_x < 0 || pos_x > x - y)
        {
            x_circle_velocity = velocity_x *= -1;
        }
        if (pos_y < 0 || pos_y > second_x - y)
        {
            y_circle_velocity = velocity_y *= -1;
        }
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 600), "screen_saver");
    window.setFramerateLimit(60);

    sf::RectangleShape rect;
    sf::CircleShape circle(50);

    // rect
    sf::Vector2f rectangle_position(700 / 2, 600 / 2);
    rect.setPosition(rectangle_position);
    rect.setSize(sf::Vector2f(100, 100));

    // circle
    sf::Vector2f circle_position(500 / 2, 400 / 2);
    circle.setPosition(circle_position);
    circle.setFillColor(sf::Color(100, 250, 200, 150));

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

        Moving_shape rectangle_shape;
        Moving_shape circle_shape;

        rectangle_shape.moving_shape_rect(rectangle_position.x, rectangle_position.y, 700, 600, 100, x_rect_velocity, y_rect_velocity);
        circle_shape.moving_shape_circle(circle_position.x, circle_position.y, 700, 600, 100, x_circle_velocity, y_circle_velocity);

        rectangle_position.x += x_rect_velocity;
        rectangle_position.y += y_rect_velocity;
        rect.setPosition(rectangle_position);

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
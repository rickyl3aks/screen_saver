#include <SFML/Graphics.hpp>
#include <iostream>
#include "classes/moving_shapes.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 600), "screen_saver");
    window.setFramerateLimit(60);

    // creating shapes
    sf::RectangleShape rect;
    sf::CircleShape circle(50);
    sf::CircleShape triangle(80.f, 3);
    sf::CircleShape octagon(80.f, 8);

    // rect
    sf::Vector2f rectangle_position(700 / 2, 600 / 2);
    rect.setPosition(rectangle_position);
    rect.setSize(sf::Vector2f(100, 100));

    // circle
    sf::Vector2f circle_position(500 / 2, 400 / 2);
    circle.setPosition(circle_position);
    circle.setFillColor(sf::Color(100, 250, 200, 150));

    // triange
    sf::Vector2f triangle_position(100, 200);
    triangle.setPosition(triangle_position);
    triangle.setFillColor(sf::Color(148, 214, 37, 130));

    // octagon
    sf::Vector2f octagon_position(100, 200);
    octagon.setPosition(octagon_position);
    octagon.setFillColor(sf::Color(148, 0, 120, 130));

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
        Moving_shape triangle_shape;
        Moving_shape octagon_shape;

        rectangle_shape.moving_shape_rect(rectangle_position.x, rectangle_position.y, 700, 600, 100, x_rect_velocity, y_rect_velocity);
        circle_shape.moving_shape_circle(circle_position.x, circle_position.y, 700, 600, 100, x_circle_velocity, y_circle_velocity);
        triangle_shape.moving_shape_triangle(triangle_position.x, triangle_position.y, 700, 600, 100, x_triangle_velocity, y_triangle_velocity);
        triangle_shape.moving_shape_octagon(octagon_position.x, octagon_position.y, 700, 600, 130, x_octagon_velocity, y_octagon_velocity);

        // set rectangle position
        rectangle_position.x += x_rect_velocity;
        rectangle_position.y += y_rect_velocity;
        rect.setPosition(rectangle_position);

        // set circle position
        circle_position.x += x_circle_velocity;
        circle_position.y += y_circle_velocity;
        circle.setPosition(circle_position);

        // set triangle position
        triangle_position.x += x_triangle_velocity;
        triangle_position.y += y_triangle_velocity;
        triangle.setPosition(triangle_position);

        // set octagon position
        octagon_position.x += x_octagon_velocity;
        octagon_position.y += y_octagon_velocity;
        octagon.setPosition(octagon_position);

        // render on the screen
        window.clear();
        window.draw(rect);
        window.draw(circle);
        window.draw(triangle);
        window.draw(octagon);
        window.display();
    };

    return 0;
}
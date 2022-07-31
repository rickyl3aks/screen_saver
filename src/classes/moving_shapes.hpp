#include <SFML/Graphics.hpp>
#include <iostream>

// set velocity for each shapes
float x_circle_velocity = 4;
float y_circle_velocity = 5;

float x_rect_velocity = 3;
float y_rect_velocity = 3;

float x_triangle_velocity = 2;
float y_triangle_velocity = 6;

float x_octagon_velocity = 3;
float y_octagon_velocity = 4;

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

public:
    void moving_shape_triangle(float pos_x, float pos_y, float x, float second_x, float y, float velocity_x, float velocity_y)
    {
        position.x = pos_x;
        position.y = pos_y;

        if (pos_x < 0 || pos_x > x - y)
        {
            x_triangle_velocity = velocity_x *= -1;
        }
        if (pos_y < 0 || pos_y > second_x - y)
        {
            y_triangle_velocity = velocity_y *= -1;
        }
    }

public:
    void moving_shape_octagon(float pos_x, float pos_y, float x, float second_x, float y, float velocity_x, float velocity_y)
    {
        position.x = pos_x;
        position.y = pos_y;

        if (pos_x < 0 || pos_x > x - y)
        {
            x_octagon_velocity = velocity_x *= -1;
        }
        if (pos_y < 0 || pos_y > second_x - y)
        {
            y_octagon_velocity = velocity_y *= -1;
        }
    }
};
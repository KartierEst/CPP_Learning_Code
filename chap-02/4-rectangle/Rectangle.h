#pragma once

#include <ostream>
class Rectangle
{
public:
    static void set_default_size(float size);
    Rectangle();
    Rectangle(float length, float width);

    Rectangle(float size);
    void scale(float ratio);
    float get_length() const;
    float get_width() const;

private:
    static float _default_size;
    float _length;
    float _width;
};

std::ostream& operator<<(std::ostream& stream, const Rectangle& rect);
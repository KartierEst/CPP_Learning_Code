#include "Rectangle.h"

#include <iostream>

int main()
{
    Rectangle rect(2.f, 4.f);
    std::cout << "{ L: " << rect.get_length() << ", W: " << rect.get_width() << " }" << std::endl;

    rect.scale(3);
    std::cout << "{ L: " << rect.get_length() << ", W: " << rect.get_width() << " }" << std::endl;

    Rectangle::set_default_size(2.f);
    Rectangle s1;
    Rectangle s2;

    Rectangle::set_default_size(7.f);
    Rectangle s3;
    Rectangle s4;
    Rectangle s5;

    std::cout << s1.get_length() << " " << s3.get_length() << std::endl;

    return 0;
}

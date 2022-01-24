#pragma once

#include <string>
#include <iostream>

struct Content
{
    Content(const std::string& name)
        : name { name }
    {
        std::cout << "Content created" << std::endl;
    }
    Content(const Content& other)
    {
        std::cout << "Content copied" << std::endl;
        std::cout << other.name << std::endl;
    }
    ~Content();
    std::string name;
};

class Box
{
public:
    Box(const std::string& name)
        : _content { name }
    {
        std::cout << "Box created" << std::endl;

    }
    ~Box();


    Content& get_content() { return _content; }

private:
    Content _content;
};

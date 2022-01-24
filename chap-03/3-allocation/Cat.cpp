#include "Cat.h"

#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<Cat> cat = std::make_unique<Cat>("Null");
    std::cout << *cat << std::endl;
    std::unique_ptr<Cat> catNull;
    if(catNull == nullptr){
        std::cout << "null" << std::endl;
    }
    catNull = std::make_unique<Cat>("Null");
    std::cout << *catNull << std::endl;

    if(catNull == cat){
        std::cout << "les deux unique_ptr sont égaux." << std::endl;
    }
    if(*catNull == *cat){
        std::cout << "les deux objets pointés sont égaux." << std::endl;
    }

    cat.reset();
    if (cat == nullptr)
    {
        std::cout << "cat1 is nullptr." << std::endl;
    }

    return 0;
}
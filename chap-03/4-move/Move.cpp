#include <vector>
#include <iostream>
#include <memory>
#include <utility>

void display(const std::string& variable_name, const std::unique_ptr<int>& variable)
{
    if (variable)
    {
        std::cout << variable_name << " contains " << *variable << std::endl;
    }
    else
    {
        std::cout << variable_name << " is empty" << std::endl;
    }
}

std::unique_ptr<int> passthrough(std::unique_ptr<int> ptr)
{
    std::cout << "Before move in passthrough" << std::endl;
    display("ptr", ptr);
    std::cout << "--------------------------" << std::endl;

    auto moved_ptr = std::move(ptr);

    std::cout << "After move in passthrough" << std::endl;
    display("moved_ptr", moved_ptr);
    display("ptr", ptr);
    std::cout << "--------------------------" << std::endl;

    return moved_ptr;
}

int main()
{
    std::vector<std::unique_ptr<int>> many_ints;

    auto value = std::make_unique<int>(3);

    if (value != nullptr)
    {
        std::cout << "value is " << *value << std::endl;
    }
    else
    {
        std::cout << "value is empty" << std::endl;
    }

    many_ints.emplace_back(std::move(value));

    if (value != nullptr)
    {
        std::cout << "value is " << *value << std::endl;
    }
    else
    {
        std::cout << "value is empty" << std::endl;
    }

    if (many_ints[0] != nullptr)
    {
        std::cout << "many_ints[0] is " << *many_ints[0] << std::endl;
    }
    else
    {
        std::cout << "many_ints[0] is empty" << std::endl;
    }

    std::vector<std::string> many_strings;

    std::string value1 = "will I move?";
    // auto value = std::string { "will I move?" };

    std::cout << "value is '" << value1 << "'" << std::endl;

    many_strings.emplace_back(std::move(value1));

    std::cout << "value is '" << value1 << "'" << std::endl;
    std::cout << "many_strings[0] is '" << many_strings[0] << "'" << std::endl;

    auto i1 = std::make_unique<int>(3);
    auto i2 = std::make_unique<int>(8);

    std::cout << "Before passthrough call" << std::endl;
    display("i1", i1);
    display("i2", i2);
    std::cout << "--------------------------" << std::endl;

    i2 = passthrough(std::move(i1));

    std::cout << "After passthrough call" << std::endl;
    display("i1", i1);
    display("i2", i2);
    std::cout << "--------------------------" << std::endl;

    return 0;
}
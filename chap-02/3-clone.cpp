#include <iostream>
#include <string>

class Person
{
public:
    Person(const std::string& name, const std::string& surname)
        : _name { name }
        , _surname { surname }
    {}
    Person(const Person& other)
        : _name { other._name }
        , _surname { other._surname }
        //, _age { other._age }
    {}

    std::string  get_full_name() const { return _name + " " + _surname; }
    unsigned int get_age() const { return _age; }
    void wait(unsigned int years) { _age += years; }
    Person& operator=(const Person& other)
    {
        if (this != &other)
        {
            _name = other._name;
            _surname = other._surname;
        }

        return *this;
    }

private:
    std::string  _name;
    std::string  _surname;
    unsigned int _age = 0u;
};

std::ostream& operator<<(std::ostream& stream, const Person& person)
{
    return stream << "Person named '" << person.get_full_name() << "' is " << person.get_age() << " years old.";
}



int main()
{
    Person batman { "Bruce", "Wayne" };
    batman.wait(23);
    Person abder { batman };

    std::cout << "Person named '" << batman.get_full_name() << "' is " << batman.get_age() << " years old."
              << std::endl;
    std::cout << "Person named '" << batman.get_full_name() << "' is " << batman.get_age() << " years old."
              << std::endl;

    std::cout << batman << std::endl;
    std::cout << abder << std::endl;

    Person assigned_clone { "Batman", "2" };
    std::cout << assigned_clone << std::endl;

    assigned_clone = batman;
    std::cout << assigned_clone << std::endl;

    return 0;
}

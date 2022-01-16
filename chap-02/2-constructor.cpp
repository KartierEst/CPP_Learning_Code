#include <iostream>
#include <string>

class Person
{
public:
    Person()
    {}
    Person(const std::string& name, const std::string& surname , unsigned int age):
        _name { name } ,
        _surname { surname },
        _age { age }
    {}
    std::string get_full_name() const { return _name + " " + _surname; }
    void       wait(unsigned int years) { _age+=years; }

    /*void set_name(const std::string& name) { _name = name; }
    void set_age(unsigned int age) { _age = age; }*/

    unsigned int get_age()
    {
        return _age;
    }

private:
    const std::string  _name;
    const std::string _surname;
    unsigned int _age = 0u;
};

int main()
{
    Person p("Bruce","Wayne",23);

    /*p.set_name("Batman");
    p.set_age(23);*/

    std::cout << "Person named '" << p.get_full_name() << "' is " << p.get_age() << " years old." << std::endl;

    return 0;
}

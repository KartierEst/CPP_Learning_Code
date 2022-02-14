#include <iostream>

// concaténation -> operator+ : auto str_3 = str1 + str2;
// extration de sous-chaîne -> substr : auto str_me = std::string { "find me" }.substr(5, 2); -> 5 position et 2 taille
// recherche -> find : auto pos = str.find("abc");
// comparaison -> operator== : auto are_equal = (str1 == str2);
// remplacement -> replace : std::string { "this is old" }.replace(8, 3, "new"); -> 5 position et 3 taille

// Quelle fonction permet de convertir des valeurs numériques en chaînes de caractères ?
// std::to_string

// Quelles fonctions permettent maintenant de faire l’inverse ? Que se passe-t-il si la chaîne de caractères ne contient pas vraiment une valeur du type attendu ?
// Il s’agit des fonctions std::stoi (string to int), std::stol (string to long), std::stof (string to float), etc.
// Si la chaîne ne contient pas réellement un nombre, alors, la fonction lance une exception de type std::invalid_argument.

void print_in_console(std::string_view str)
{
    std::cout << str << std::endl;
}

int main()
{
    print_in_console(std::string { "find me" }.substr(5, 2));
    print_in_console("print me");
    return 0;
}

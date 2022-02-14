#include <vector>
#include <iostream>
#include <algorithm>
int main()
{
    //std::vector<int> tab {4,0}; // donne 4 et 0
    // constructeur :vector( std::initializer_list<T> init, const Allocator& alloc = Allocator() );
    std::vector<int> tab(4,0); //  donne 4 zéros d'affilés
    // constructeur :vector( size_type count,const T& value,const Allocator& alloc = Allocator());
    for(auto v : tab)
    {
        std::cout << v << std::endl;
    }
    int array[] = { 0, 1, 2, 3, 4, 5 };

    std::vector<int> part(&array[2], &array[5]);
    for (const auto v: part)
    {
        std::cout << v << std::endl;
    }
    /*std::vector<int> full(array, array + 6); // mm chose que (&array[0],&array[6])
    for (const auto v: full)
    {
        std::cout << v << std::endl;
    }*/
    std::vector<int> full(array, array + 6);
    for (size_t left = 0, right = full.size() - 1; left < right; ++left, --right)
    {
        std::swap(full[left], full[right]);
    }
    //Pour inserer des éléments au milieu du tableau on a :
    // Pour insérer des éléments à une position arbitraire, il est possible d’utiliser insert ou emplace.
    // En utilisant emplace, il est possible de fournir les paramètres de construction de l’élément à insérer (comme emplace_back),
    // alors que pour insert, il faut fournir l’élément à insérer directement (comme push_back).

    for (auto it = full.begin(); it != full.end(); ++it) // itérateur
    {
        std::cout << *it << std::endl;
    }

    full = {1,2,3};

    for (auto it = full.begin(); it != full.end(); it += 2)
    {
        it = full.insert(it, *it);
    }

    while (!full.empty())
    {
        full.pop_back();
    }

    // v.erase(v.begin() + n); -> supp le n-ieme élément.

    full = {1,2,3,4,5,6,7,8,9,10};
    //full.erase(full.begin() + 3);  (ici 4)

    full.erase(full.begin() + 2, full.begin() + 7); // supp de 2eme element au 7eme donc de 3 à 7 car on joue sur les indices

    /*for (auto it = full.begin(); it != full.end(); ++it) // itérateur
    {
        std::cout << *it << ",";
    }*/

    const auto it = std::find(full.begin(), full.end(), 9);
    if (it != full.end())
    {
        full.erase(it);
    }

    for (auto v = full.begin(); v != full.end(); ++v) // itérateur
    {
        std::cout << *v << ",";
    }

    std::vector<int> v;
    v.assign(5, 2); // v -> prend 5 fois 2
    v.assign({ 0, 2, 32, -4, 3 }); // prend le tableau
    v.clear(); // supp tout dans v

    std::array<char, 3> afcds { 'a', 'b', 'c' };

    for(auto p : afcds)
    {
        std::cout << p << ",";
    }

    return 0;
}
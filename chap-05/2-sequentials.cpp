#include <list>
#include <array>
#include <stack>
#include <vector>

enum Fruit
{
    Apricot,
    Cherry,
    Mango,
    Raspberry,

    Fruit_Count,
};

void try_arrays()
{
    // Implement array tests here.
    std::array<std::string, Fruit_Count> fruit_names;
    fruit_names[Apricot] = "apricot";
    fruit_names[Cherry] = "cherry";
    fruit_names[Mango] = "mango";
    fruit_names[Raspberry] = "raspberry";

}

void try_lists()
{
    std::list<int> l1 {2,9,1232,8};
    std::list<int> l2(3,8);
    std::list<int> l3;
    l3.assign({1,2,3,4});
    std::list<int> l4;
    l4.emplace_front(0);
    l4.emplace_front(5);
    l4.emplace_front(6);

    // First possibility : sort first, then use merge.
    l1.sort();
    l2.sort();
    l1.merge(l2);

    // Second possibility : append one to the other, then use sort.
    l3.splice(l3.begin(), l4);
    l3.sort();

    // Find the middle of the list by using function std::advance, and insert the other list at this position.
    auto mid = l1.begin();
    std::advance(mid, l1.size() / 2);
    l1.splice(mid, l3);

}

void try_stacks() // Implement stack tests here.
{
    //Par défaut, stack est implémentée au moyen d’une std::deque. L’avantage de cette classe pour l’implémentation d’une pile,
    // c’est qu’elle est très efficace pour ajouter et retirer des éléments en fin de conteneur (complexité en O(1)),
    // et lors de ces opérations, les itérateurs sur les autres éléments ne sont jamais invalidés (= plus de sécurité).
    // Elle est aussi plus performante que le vector lors des réallocations (pas de copie des éléments existants).

    // The stack can be initialized from nothing, and then values are added with push or emplace.
    std::stack<int, std::vector<int>> s1;
    s1.emplace(0);
    s1.emplace(1);
    s1.emplace(2);

    // impossible d'utiliser foreach ou for car il n y a pas d'itérable sur stack ( pas de fonction  begin et end )

}

int main()
{
    try_arrays();
    try_lists();
    try_stacks();

    return 0;
}
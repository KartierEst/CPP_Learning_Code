#include <set>
#include <iostream>
#include <unordered_set>
#include <map>
#include "keys.h"

// différences entre set et unordered_set
// Complexité :
// std::set est implémenté (généralement) comme un arbre binaire de recherche.
// Les opérations d’insertions, de recherches et de comparaison s’effectuent donc en temps logarithmique.
// En ce qui concerne l’espace mémoire utilisé, les arbres binaires de recherche ont généralement besoin d’autant de mémoire qu’il y a d’éléments à stocker,
// c’est-à-dire O(n).
// std::unordered_set est implémenté en utilisant des “buckets”, indexés par le hash de l’objet (comme dans une hashmap).
// Les opérations d’insertions, de recherches et de comparaison s’effectuent donc en temps constant amorti (“amorti”, car si deux objets ont le même hash,
// il faut potentiellement parcourir une liste d’objects ensuite). La documentation ne donne pas de détail concernant l’espace mémoire alloué par un unordered_set,
// mais si vous vous rappelez de votre cours d’algorithmique, pour qu’une hashmap soit efficace, il faut limiter le nombre de conflits possibles.
// Cela implique que l’espace alloué doit être très largement supérieur à l’espace réellement occupé par les éléments.
// Contraintes :
// std::set attend que ses éléments soient comparables (= qu’il existe une fonction permettant de dire si un élément est plus petit qu’un autre).
// std::unordered_set attend que ses éléments soient hashables (= qu’il existe une fonction permettant de convertir un élément en un entier,
// respectant le fait que si deux éléments sont considérés égaux, alors les deux entiers obtenus sont égaux également)
// et qu’il existe une fonction permettant de savoir si deux éléments sont égaux ou non (il n’est pas nécessaire ici d’avoir une relation d’ordre sur les éléments).


int main()
{
    /*std::set<ComparableDog> dogs;

    ComparableDog medor { "medor", "labrador" };
    dogs.emplace(medor);

    ComparableDog gus { "gus", "bordercollie" };
    dogs.emplace(gus);

    ComparableDog medor_clone = medor;
    dogs.emplace(medor_clone); // pareil que medor donc il n'est pas ajouté à la set

    std::cout << dogs.size() << std::endl;

    std::unordered_set<HashableDog> dogs2;

    HashableDog med { "medor", "labrador" };*/

    using Owner = std::pair<std::string, std::string>;
    std::map<ComparableDog, Owner> owners_by_dog;

    // fonction insertion éléments map
    // Comportement :
    // insert / emplace / try_emplace : insère l’élément dans la map seulement si la clef n’est pas déjà présente,
    // insert_or_assign : insère l’élément dans la map et remplace l’élément existant si la clef était déjà présente,
    // Syntaxe :
    // insert : la fonction attend une pair : dict.insert(std::make_pair(key, value)); / dict.insert({ key, value });
    // insert_or_assign : on peut passer la clef et la valeur directement : dict.insert_or_assign(key, value);
    // emplace : on peut aussi passer la clef et la valeur directement : dict.emplace(key, value);
    // try_emplace : on peut passer la clef en premier, puis les paramètres de construction de la valeur à la suite : dict.try_emplace(key, p1, p2, p3);


    ComparableDog medor { "medor", "labrador" };
    ComparableDog gus { "gus", "bordercollie" };
    ComparableDog zim { "zim", "poodle" };
    ComparableDog flippy { "flippy", "spaniel" };

    owners_by_dog.insert(std::make_pair(medor, Owner { "Claire", "David" }));
    owners_by_dog.insert_or_assign(gus, Owner { "Marc", "Zipstein" });
    owners_by_dog.emplace(zim, Owner { "Céline", "Noël" });
    owners_by_dog.try_emplace(flippy, "Vincent", "Nozick");

    owners_by_dog.emplace(gus, Owner { "Claire", "David" });
    // -> gus is still owned by Marc (emplace does not modify values with existing keys, neither does insert or try_emplace)

    owners_by_dog.insert_or_assign(gus, Owner { "Vincent", "Nozick" });
    // -> gus is now owned by Vincent (insert_or_assign reassign values with existing keys)

    // si on veut utiliser une unordered_map on doit juste changer tout les ComparableDog par des HashableGog.
    // unordered_map et unordered_set ont besoin d'etre travailler sur des classes qui ont une fonction de hashage ( avec operator() voir dans keys.h
    // dans la classe HashableDog

    return 0;
}
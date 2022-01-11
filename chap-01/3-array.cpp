#include <iostream>
#include <vector>
using namespace std;

int main(int argc,char** argv)
{
    // int array[] = { 0, 1, 2, 3 };
    //int array[50] = {};
    std::vector<int> array;
    array.emplace_back(8);
    array.emplace_back(5);
    array.emplace_back(-3);


    /*for (int i = 0; i < 4; ++i)
    {
        std::cout << array[i] << std::endl;
    }*/

    /*for(int value : array){
        cout << value << endl;
    }*/

    if(argc < 2){
        cerr << "Erreur il n ya pas d'arguments" << endl;
        return -1;
    }

    int length = stoi(argv[1]);
    if (length <= 0){
        cerr << "Expected strictly positive value for array size." << endl;
        return -1;
    }

    cout << length << endl;

    for (int i = 0; i < length; ++i){
        array.emplace_back(i+1);
    }

    for (int value : array){
        std::cout << value << std::endl;
    }

    return 0;
}

//
// Created by abder on 11/01/2022.
//

#include<iostream>
#include <vector>
using namespace std;


vector<unsigned int> count_lower(string str){
    vector<unsigned int> tab;
    for(int i = 0; i < 26; i++){
        tab.emplace_back(0);
    }
    for(char c : str){
        if(c > 96 && c < 123){
            tab[c - 97] += 1;
        }
    }
    return tab;
}

void display_lower_occ(vector<unsigned int> tab){
    for(int i = 0; i < 26; i++){
        cout << char(i+97) << " : " << tab[i] << endl;
    }
}

int main(){
    string str;
    while(str != "QUIT"){
        vector<unsigned int> tab;
        std::cin >> str;
        if(str == "QUIT"){
            break;
        }
        tab = count_lower(str);
        display_lower_occ(tab);
    }
    return 0;
}
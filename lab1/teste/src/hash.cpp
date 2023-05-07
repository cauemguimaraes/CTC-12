#include "hash.h"

// LOOK FOR THE COMMENTS IN THE .H 
// TO UNDERSTAND WHAT EACH FUNCTION MUST DO

Hash::Hash(int tablesize, int (*hf) (std::string) ) {
 // CONSTRUTOR
 //this->_tablesize = tablesize; //armazena o tamanho da tabela hash
 _hash_func = hf; //armazena o ponteiro para a função de hash

 //construção da tabela hash com listas
 for (int i = 0; i < tablesize; i++){
     std::forward_list<std::string> list;
     _table.push_back(list);
 }
}

int Hash::add(std::string str, int &collisions) {

    if (contains(str, collisions) == 1) { return 0; } //se ja tiver a string retorna 0 e não adiciona nada

    int position = hash(str);
    _table[position].push_front(str);
    return 1; //caso contrário, adiciona a string e retorna 1
    
}//add

int Hash::remove(std::string str, int &collisions) {

    if (contains(str, collisions) == 0) { return 0; } //se a string não for achada retorna 0

    _table[hash(str)].remove(str);
    return 1; //remove o elemento e retorna 1
    
}//remove


int Hash::hash(std::string str) { 
    
    return _hash_func(str);
    
}//hash
    
int Hash::contains(std::string str, int &collisions) { 

    int position = hash(str);
    collisions = 0;
    for (auto i : _table[position]){
        collisions = collisions + 1; //conta as colisões, atualizando o endereço "collisions"
        if (i == str) return 1; //string está na lista
    }

    return 0; //string não está na lista
    
}//contains


int Hash::worst_case() {

    int worst = 0; //inicializa a variavel que ira contar o tamanho da lista mais longa

    for (auto i : _table) {
        int aux2 = 0;
        for(auto j : i) {
            aux2++;
        }

        if (aux2 > worst) {
            worst = aux2;//atualiza o tamanho da maior lista a medida que passa por cada uma delas

        }
    }

    return worst;
    
}//worst_case

int Hash::size() {

    int n_strings = 0;

    for (auto i : _table) {
        for(auto j : i) {
            n_strings = n_strings + 1;
        }
    }

    return n_strings;
}//size


#ifndef minha_Rubro_Negra_H
#define minha_Rubro_Negra_H

#include <vector>

class Arvore_Rubro_Negra {
    
public:
    Arvore_Rubro_Negra();
    void inserir(double chave, long valor);
    void acharIntervalo(std::vector<long> &res, double primeiro, double ultimo );
    long tamanho();


private: 
    enum Cor {vermelho, preto};


    struct Node {
        double chave;
        long valor;
        Node *pai, *esquerda, *direita;
        Cor cor;
        
        //Contrutor
        Node(double chave, long valor)
            : chave(chave), valor(valor),pai(nullptr), esquerda(nullptr), direita(nullptr), cor(vermelho) {} 
        
    };

    long _tamanho;
    Node *raiz;
    Node *Nil;

    
    void inserir_privado(Node *z);
    void balancear(Node *z);
    void rotEsquerda(Node *x);
    void rotDireita(Node *x);
    void acharIntervalo_privado(Node *h, std::vector<long> &res, double primeiro, double ultimo );

        
        

    
};


#endif
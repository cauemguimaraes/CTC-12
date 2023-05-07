#include <minha_Rubro_Negra.h>

//Construindo a arvore a partir do nill e da raiz
Arvore_Rubro_Negra::Arvore_Rubro_Negra()
{
    this->Nil = new Node(0, 0);
    this->Nil->pai = this->Nil;
    this->Nil->esquerda = this->Nil;
    this->Nil->direita = this->Nil;
    this->Nil->cor = preto;
    this->raiz = this->Nil;
}

//Implementação da inserção publica:
void Arvore_Rubro_Negra::inserir(double chave, long valor)
{
    Node *z = new Node(chave, valor);
    z->pai = this->Nil;
    z->esquerda = this->Nil;
    z->direita = this->Nil;
    inserir_privado(z);
}

//Implementação da inserção privada
void Arvore_Rubro_Negra::inserir_privado(Node *z)
{
    Node *y, *x;
    y = this->Nil;
    x = this->raiz;
    while (x != this->Nil)
    {
        y = x;
        if (z->chave < x->chave)
        {
            x = x->esquerda;
        }
        else
            x = x->direita;
    }

    z->pai = y;

    if (y == this->Nil)
    {
        this->raiz = z;
    }
    else if (z->chave < y->chave)
    {
        y->esquerda = z;
    }
    else
        y->direita = z;

    z->esquerda = this->Nil;
    z->direita = this->Nil;
    z->cor = vermelho;

    balancear(z);
    _tamanho++;
}

//Implementação do balanceamento que acessora a inserção
void Arvore_Rubro_Negra::balancear(Node *z)
{
    Node *y;
    while (z->pai->cor == vermelho)
    {
        if (z->pai == z->pai->pai->esquerda)
        {
            y = z->pai->pai->direita;
            if (y->cor == vermelho)
            {
                z->pai->cor = preto;
                y->cor = preto;
                z->pai->pai->cor = vermelho;
                z = z->pai->pai;
            }
            else
            {
                if (z == z->pai->direita)
                {
                    z = z->pai;
                    rotEsquerda(z);
                }
                z->pai->cor = preto;
                z->pai->pai->cor = vermelho;
                rotDireita(z->pai->pai);
            }
        }

        else
        {
            y = z->pai->pai->esquerda;
            if (y->cor == vermelho)
            {
                z->pai->cor = preto;
                y->cor = preto;
                z->pai->pai->cor = vermelho;
                z = z->pai->pai;
            }
            else
            {
                if (z == z->pai->esquerda)
                {
                    z = z->pai;
                    rotDireita(z);
                }
                z->pai->cor = preto;
                z->pai->pai->cor = vermelho;
                rotEsquerda(z->pai->pai);
            }
        }
    }
    this->raiz->cor = preto;
}

// implementação da rotação esquerda que acessora o balanceamento
void Arvore_Rubro_Negra::rotEsquerda(Node *x)
{
    Node *y;
    y = x->direita;
    x->direita = y->esquerda;
    if (y->esquerda != this->Nil)
    {
        y->esquerda->pai = x;
    }
    y->pai = x->pai;
    if (x->pai == this->Nil)
    {
        this->raiz = y;
    }
    else if (x == x->pai->esquerda)
    {
        x->pai->esquerda = y;
    }
    else
        x->pai->direita = y;
    y->esquerda = x;
    x->pai = y;
}

// Implementação da rotação direita que acessora o balanceamento
void Arvore_Rubro_Negra::rotDireita(Node *x)
{
    Node *y;
    y = x->esquerda;
    x->esquerda = y->direita;
    if (y->direita != this->Nil)
    {
        y->direita->pai = x;
    }
    y->pai = x->pai;
    if (x->pai == this->Nil)
    {
        this->raiz = y;
    }
    else if (x == x->pai->direita)
    {
        x->pai->direita = y;
    }
    else
        x->pai->esquerda = y;
    y->direita = x;
    x->pai = y;
}

//Implementação da função publica de montagem do vetor no range 
void Arvore_Rubro_Negra::acharIntervalo(std::vector<long> &res, double primeiro, double ultimo)
{
    acharIntervalo_privado(this->raiz, res, primeiro, ultimo);
}

//Implementação da função publica de montagem do vetor no range
void Arvore_Rubro_Negra::acharIntervalo_privado(Node *h, std::vector<long> &res, double primeiro, double ultimo)
{
    if (h == this->Nil)
        return;

    if (h->chave < primeiro) {
        acharIntervalo_privado(h->direita, res, primeiro, ultimo);
    }
    if (h->chave > ultimo) {
        acharIntervalo_privado(h->esquerda, res, primeiro, ultimo);
    }
    if (h->chave >= primeiro && h->chave <= ultimo) {
        acharIntervalo_privado(h->esquerda, res, primeiro, ultimo);
        res.push_back(h->valor);
        acharIntervalo_privado(h->direita, res, primeiro, ultimo);
    }
    
}

//Implementação da função publica que retorna o tamanho da arvore
long Arvore_Rubro_Negra::tamanho()
{
    return _tamanho;
}

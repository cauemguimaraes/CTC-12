
#include <IndexPointsAluno.h>

/// returns the number of elements in the index
long IndexPointsAluno::size() { return _arvore.tamanho(); }

/// adds new element to the index. 
void IndexPointsAluno::add (double key, long idx ) { _arvore.inserir(key, idx) ; }


void IndexPointsAluno::find(std::vector<long> &res, double first, double last ) {
   res.clear();
   _arvore.acharIntervalo(res, first, last);     
}//find

#ifndef CES12_ALUNOINDEXPOINTS_H
#define CES12_ALUNOINDEXPOINTS_H

#include <vector>
#include <map>
#include <IndexPointsAbstract.h>
#include <minha_Rubro_Negra.h>

class IndexPointsAluno : public IndexPointsAbstract {
    
public:
    
    long size() ;
        
    void add (double key, long idx ) ;
    
    //look for a range of values
    void find(std::vector<long> &res, double first, double last ) ;
    
    
private: 
    // ALUNO DEVE IMPLEMENTAR ALGO COM O MESMO COMPORTAMENTO DE MULTIMAP
    Arvore_Rubro_Negra _arvore;
    
};//class


#endif

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "fstream"
using namespace std ;

#ifndef LABELGENERATOR_LABELGENERATOR_H
#define LABELGENERATOR_LABELGENERATOR_H


class LabelGenerator {
protected:
    string name ;
    int index ;
public:
    LabelGenerator() ;
    LabelGenerator(string n , int idx) ;
    void SetLabelName(string n) ;
    string GetLabelName() const ;
    void SetLabelIndex(int idx) ;
    int GetLabelIndex() const ;
    string NextLabel() ;
    friend ostream& operator << (ostream &out , const LabelGenerator& L) ;
};
class FileLabelGenerator : public LabelGenerator{
    private:
    string filename ;
    ifstream InformationFile ;
public:
    FileLabelGenerator(string n , int idx , string file) ;
    string NextLabel() ;
    friend ostream& operator << (ostream &out ,  FileLabelGenerator& L) ;
    ~FileLabelGenerator() ;
};


#endif //LABELGENERATOR_LABELGENERATOR_H

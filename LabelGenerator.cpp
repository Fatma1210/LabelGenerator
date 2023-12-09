#include "LabelGenerator.h"
#include "fstream"
#include "iostream"
LabelGenerator ::LabelGenerator() {
    name = "" ;
    index = 0 ;
}
LabelGenerator ::LabelGenerator(string n, int idx) {
    name = n ;
    index = idx ;
}
void LabelGenerator ::SetLabelName(string n) {
    name = n ;
}
string LabelGenerator ::GetLabelName() const {
    return name ;
}
void LabelGenerator ::SetLabelIndex(int idx) {
    index = idx ;
}
int LabelGenerator ::GetLabelIndex() const {
    return index ;
}
ostream& operator<<(std::ostream& out, const LabelGenerator& L) {
    out << L.name << " " << L.index << std::endl;
    return out;
}
string LabelGenerator ::NextLabel()  {
    string idx = to_string(index) ;
    index++;
    return name + " " + idx ;
}
FileLabelGenerator ::FileLabelGenerator(string n, int idx,string name) :LabelGenerator(n , idx) , filename(name){
  InformationFile.open(name) ;
    if(!InformationFile.is_open()){
        cerr << "the file info.txt  can't be open." << endl ;
    }
}
string FileLabelGenerator :: NextLabel(){
    cout << LabelGenerator :: NextLabel() ;
    string line ;
    if (getline(InformationFile, line)) {
        return " " + line;
    }
    else {
        cerr << "the file info.txt  can't be open." << endl ;
    }
}
FileLabelGenerator :: ~FileLabelGenerator(){
    InformationFile.close() ;
}
ostream& operator<<(ostream& out,  FileLabelGenerator& L) {
    out << static_cast<const LabelGenerator&>(L);
    //L.InformationFile.open("info.txt" , ios :: in) ;
    if(!L.InformationFile.is_open()){
        cerr << "the file info.txt  can't be open." << endl ;
    }
    string line;
    while (getline(L.InformationFile, line)) {
        out << line << endl;
    }
    L.InformationFile.close();

    return out;
}
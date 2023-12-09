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
  if(!InformationFile.is_open()) {
      cerr << "the file " << filename << " can't be open.\n" ;
  }
}
string FileLabelGenerator :: NextLabel(){
    cout << LabelGenerator :: NextLabel() ;
    getline(InformationFile, line) ;
        return ' ' + line;
    }
FileLabelGenerator :: ~FileLabelGenerator(){
    InformationFile.close() ;
}

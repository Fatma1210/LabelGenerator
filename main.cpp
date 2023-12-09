#include <iostream>
#include "LabelGenerator.h"
#include "LabelGenerator.cpp"
int main() {
    LabelGenerator figureNumbers("Figure ", 1);
    LabelGenerator pointNumbers("P", 0);
    cout << "Figure numbers: \n";
    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.NextLabel() << endl ;
    }
    cout << endl << "Point numbers: \n";
    for (int i = 0; i < 5; i++) {
        cout << pointNumbers.NextLabel() << endl ;
    }
    cout << endl << "More figures: \n" ;
    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.NextLabel() << endl;
    }
    cout << endl;
    FileLabelGenerator figureLabels("Figure ", 1, "info.txt");
    cout << "Figure labels: \n";
    for (int i = 0; i < 3; i++) {
       cout << figureLabels.NextLabel() << endl ;
    }
    return 0;

}
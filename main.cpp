#include "Geburtstagsparty.h"


int main() {
    
    srand(time(0));
     
    Group a;
    printer(a);
    
    
    std::vector<Group> arr35;
    for (int i = 0; i < 20; ++i)
        arr35.push_back(Group(35));
    
    std::cout << "Gruppe\tMehrfachgeburtstag\n";

    for(int i = 0; i < arr35.size(); ++i){
        std::cout << i+1 << "\t" << arr35[i].birthdayOnTheSameDay() << "\n"; 
    }
    std::cout << "\n\n";
    
    std::vector<std::vector<Group>> row;
    
    for(int i = 2; i <= 50 ; ++i) {
        std::vector<Group> col;
        row.push_back(col);
        for(int j = 0; j < 10000; ++j)
            row[i-2].push_back(Group(i));
    }
    
    int count;;
    double percent;
    std::cout << "Gruppengroesse\tMehrfachgeburtstage in %\n";
    for(int i = 0; i < row.size(); ++i)
    {
        for(int j = 0; j < row[i].size(); ++j )
            if(row[i][j].birthdayOnTheSameDay()) ++count;
        percent = (double)count * 100 / row[i].size();
        std::cout <<"\t" << i + 2 << "\t\t" << percent << "\n"; 
        count = 0;
    }
    
    
    
    return 0;
}


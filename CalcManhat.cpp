#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
//Function prototype 
std::string getCin();
int ConvStr2Num(std::string str, int*x, int* y);

//Caliculate the manhattan distance between two points from read csv file
int main(){
    //reference https://docs.xilinx.com/v/u/ja-JP/ug475_7Series_Pkg_Pinout
    //file open
    std::string input;
    input = getCin();
    std::ifstream file(input);
    if(!file.is_open()){
        std::cout << "File not found" << std::endl;
        return 1;
    }

    std::string linecsv;
    int x1, y1, x2, y2;
    while (std::getline(file, linecsv)) {
        std::istringstream ss(linecsv);
        std::string field;
        std::string frstpin;
        std::string secpin;
        
        int i=0;
        while (std::getline(ss, field, ',')) {
            if(i%2==0){
                ConvStr2Num(field,&x1,&y1);
                frstpin = field;
                i++;
            }else{
                ConvStr2Num(field,&x2,&y2);
                secpin = field;
                i++;
            }
        }
        //caliculate the manhattan distance
        int manhattan = abs(x1 - x2) + abs(y1 - y2);
        std::cout << "Manhattan distance between " << frstpin << " and " << secpin << " is " << manhattan << "\n";
    }
}


std::string getCin() {
    std::string input;
    std::cout << "Please input : (exclude .csv)";
    std::getline(std::cin, input);
    input += ".csv";
    return input;
}


int ConvStr2Num(std::string str, int*x, int* y){
    std::string letter;
    std::string number;

    std::map<std::string, int> map = {
        {"A" , 0 },{"B"  , 1},{"C", 2},{"D", 3},{"E", 4},{"F", 5},{"G", 6},{"H", 7},{"J", 8},{"K", 9},{"L", 10},
        {"M" , 11},{"N" , 12},{"P", 13},{"R", 14},{"T", 15},{"U", 16},{"V", 17},{"W", 18},{"Y", 19},{"AA", 20},
        {"AB", 21},{"AC", 22},{"AD", 23},{"AE", 24},{"AF", 25}
    };

    for (char c : str) {
        if (std::isalpha(c)) {
            letter += c;
        } else if (std::isdigit(c)) {
            number += c;
        }
    }
    //check if the letter is in the map
    if(map.find(letter) == map.end()) {
        return -1;
    }
    *x = map[letter];
    *y = std::stoi(number);
    return 0;
}
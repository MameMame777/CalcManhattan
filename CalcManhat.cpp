#include <iostream>
#include <string>
#include <fstream>

//Function prototype 
std::string getCin();
int ConvertSrt2Num(char arg_inputstr);
//Caliculate the manhattan distance between two points from read csv file
int main(){
    //reference https://docs.xilinx.com/v/u/ja-JP/ug475_7Series_Pkg_Pinout
    std::string input;
    
    ConvertSrt2Num('A');
    input = getCin();
    std::ifstream file(input);
    if(!file.is_open()){
        std::cout << "File not found" << std::endl;
        return 1;
    }
    
    //std::string line;
    //int x1, y1, x2, y2;
    //int manhattan;
}


std::string getCin() {
    std::string input;
    std::cout << "Please input : (exclude .csv)";
    std::getline(std::cin, input);
    return input;
}

int ConvertSrt2Num(char arg_inputstr){
    int num = 0;
    const char *Row_Column[] = {
      //  1,   2,  3,  4,  5,  6,  7,  8, 9, 10, 11, 12, 13, 14
        "A", "B","C","D","E","F","G","H","J","K","L","M","N","P"
    };
    for (int i =  0; i < sizeof(Row_Column) / sizeof(Row_Column[0]); i++) {
        if (Row_Column[i][0] == arg_inputstr) {
            std::cout << "num = " << i << std::endl;
            return i;
        }
    }
    printf("Error: %c is not found\n", arg_inputstr);
    return -1;
}
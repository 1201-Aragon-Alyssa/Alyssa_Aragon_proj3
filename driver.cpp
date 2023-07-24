#include "calculator.h"

int main() {
    Calculator calc;
    
    ifstream inputFile("commands.txt");
    if (!inputFile.is_open()) {
        cout << "Failed to open the input file." << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        istringstream in(line);
        string command, operand1, operand2, operand3, ops;
        int shift; 

        in >> command; 
        command = calc.toUpper(command); 
        ops = calc.removeWhitespaces(ops); 

        if (command == "MOV") {
            in >> operand1 >> operand2;
            calc.MOV(operand1,operand2);
        } else if (command == "ADDS") {
            in >> operand1 >> operand2 >> operand3;
            calc.ADDS(operand1, operand2, operand3);
        } else if (command == "SUBS") {
            in >> operand1 >> operand2 >> operand3;
            calc.SUBS(operand1, operand2, operand3);
        } else if (command == "ANDS") {
            in >> operand1 >> operand2 >> operand3;
            calc.ANDS(operand1, operand2, operand3);
        } else if (command == "LSRS") {
            in >> operand1 >> operand2 >> shift;
            calc.LSRS(operand1, operand2, shift);
        } else if (command == "LSLS") {
            in >> operand1 >> operand2 >> shift;
            calc.LSLS(operand1, operand2, shift);
        } else if (command == "CMP") {
            in >> operand1 >> operand2;
            calc.CMP(operand1, operand2);
        } else if (command == "TST") {
            in >> operand1 >> operand2;
            calc.TST(operand1, operand2);
        } else if (command == "XOR"){
            in >> operand1 >> operand2 >> operand3;
            calc.XOR(operand1, operand2, operand3); 
        } else if (command == "ORR"){
            in >> operand1 >> operand2 >> operand3;
            calc.ORR(operand1, operand2, operand3);
        }
    
    }    
    

    inputFile.close();
    
    return 0;
}
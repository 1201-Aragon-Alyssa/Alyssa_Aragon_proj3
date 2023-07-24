#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdint>
#include <cctype>
#include <iomanip>
#include <algorithm>
using namespace std;

class Calculator{
string Hex1, Hex2; 
uint32_t R0, R1, R2, R3, R4, R5, R6, R7;
string registers[8];
public: 
    Calculator(); 
    Calculator(string, string); 
    Calculator(const Calculator &rhs); 

    void setHex1(const string&); 
    string getHex1() const; 
    void setHex2(const string&); 
    string getHex2() const; 

    void ADDS(const string, const string, const string); 
    void SUBS(const string, const string, const string); 
    void ANDS(const string, const string, const string);
    void LSRS(const string, const string, const int); 
    void LSLS(const string, const string, const int); 
    void ORR (const string, const string, const string); 
    void XOR(const string, const string, const string); 
    void printFlagStatus(bool, bool, bool, bool); 
    void printRegisters(); 
    void CMP(const string, const string);
    void TST(const string, const string);
    void MOV(const string, const string);
    string toUpper(const string);
    string removeWhitespaces(const string);
    int hexCharToInt(char);
    int hexStringtoInt(const string&);

};
#endif
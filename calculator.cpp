#include "calculator.h"

Calculator::Calculator(){
    Hex1 = "0A";
    Hex2 = "0A";
     for (int i = 0; i < 8; i++) {
        registers[i] = "0"; 
    }
}
Calculator::Calculator(string num1, string num2){
    Hex1 = num1; 
    Hex2 = num2; 
}

Calculator::Calculator(const Calculator &rhs){
    Hex1 = rhs.Hex1;
    Hex2 = rhs.Hex2; 
}

void Calculator::setHex1(const string& hex) {
    Hex1 = hex;
}

void Calculator::setHex2(const string& hex) {
    Hex2 = hex;
}

string Calculator::getHex1() const {
    return Hex1;
}

string Calculator::getHex2() const {
    return Hex2;
}

void Calculator::ADDS(const string operand1, const string operand2, const string operand3){
    int op1 = operand1[1] - '0'; 
    int op2 = operand2[1] - '0';
    int op3 = operand3[1] - '0';

    uint32_t value1 = hexStringtoInt(registers[op2]); 
    uint32_t value2 = hexStringtoInt(registers[op3]);

    uint32_t sum = value1 + value2;

    stringstream ss;
    ss << hex << uppercase << setw(8) << setfill('0') << sum;
    registers[op1] = "0x" + ss.str();

    cout << "ADDS " << operand1 << operand2 <<  operand3 << ": ";
    cout << "0x" << setw(8) << setfill('0') << hex << uppercase << sum << endl;

    printRegisters(); 
    bool N = (sum & 0x80000000) != 0;
    bool Z = sum == 0;
    bool C = sum < value1;
    bool V = ((value1 & 0x80000000) == (value2 & 0x80000000)) && ((value1 & 0x80000000) != (sum & 0x80000000));
    printFlagStatus(N, Z, C,V);

}

void Calculator::SUBS(const string operand1, const string operand2, const string operand3) {
     int op1 = operand1[1] - '0';
    int op2 = operand2[1] - '0';
    int op3 = operand3[1] - '0';

    uint32_t value1 = hexStringtoInt(registers[op2]);
    uint32_t value2 = hexStringtoInt(registers[op3]);

    uint32_t result = value1 - value2;

    stringstream ss;
    ss << hex << uppercase << setw(8) << setfill('0') << result;
    registers[op1] = "0x" + ss.str();

    cout << "SUBS " << operand1 << operand2 << operand3 << ": ";
    cout << "0x" << setw(8) << setfill('0') << hex << uppercase << result << endl;

    printRegisters();
    bool N = (result & 0x80000000) != 0;
    bool Z = result == 0;
    bool C = value1 >= value2;
    bool V = ((value1 & 0x80000000) != (value2 & 0x80000000)) && ((value1 & 0x80000000) != (result & 0x80000000));

    printFlagStatus(N, Z, C, V);
}

void Calculator::ANDS(const string operand1, const string operand2, const string operand3){
   int op1 = operand1[1] - '0';
    int op2 = operand2[1] - '0';
    int op3 = operand3[1] - '0';

    uint32_t value1 = hexStringtoInt(registers[op2]);
    uint32_t value2 = hexStringtoInt(registers[op3]);

    uint32_t result = value1 & value2;

    stringstream ss;
    ss << hex << uppercase << setw(8) << setfill('0') << result;
    registers[op1] = "0x" + ss.str();

    cout << "ANDS " << operand1 <<  operand2 << operand3 << ": ";
    cout << "0x" << setw(8) << setfill('0') << hex << uppercase << result << endl;

    bool N = (result & 0x80000000) != 0;
    bool Z = result == 0;

    printRegisters();
    printFlagStatus(N, Z, 0, 0);
    
}

void Calculator::LSRS(const string operand1, const string operand2, const int shift){
    int op1 = operand1[1] - '0';
    int op2 = operand2[1] - '0';

    uint32_t value = hexStringtoInt(registers[op2]);

    uint32_t result = value >> shift;

    stringstream ss;
    ss << hex << uppercase << setw(8) << setfill('0') << result;
    registers[op1] = "0x" + ss.str();

    cout << "LSRS " << operand1 << operand2 <<shift << ": ";
    cout << "0x" << setw(8) << setfill('0') << hex << uppercase << result << endl;

    printRegisters();
    bool N = (result & 0x80000000) != 0; 
    bool Z = result == 0;
    bool C = (value >> (shift - 1)) & 1;
    printFlagStatus(N, Z, C, 0);
}


void Calculator::LSLS(const string operand1, const string operand2, int shift){
    int op1 = operand1[1] - '0';
    int op2 = operand2[1] - '0';

    uint32_t value = hexStringtoInt(registers[op2]);

    uint32_t result = value << shift;

    stringstream ss;
    ss << hex << uppercase << setw(8) << setfill('0') << result;
    registers[op1] = "0x" + ss.str();

    cout << "LSLS " << operand1 << operand2 << shift << ": ";
    cout << "0x" << setw(8) << setfill('0') << hex << uppercase << result << endl;

    printRegisters();
    bool N = (result & 0x80000000) != 0; 
    bool Z = result == 0;
    bool C = (value >> (32 - shift)) & 1;

    printFlagStatus(N, Z, C, 0);
}

void Calculator::ORR(const string operand1, const string operand2, const string operand3){
    int op1 = operand1[1] - '0';
    int op2 = operand2[1] - '0';
    int op3 = operand3[1] - '0';

    uint32_t value1 = hexStringtoInt(registers[op2]);
    uint32_t value2 = hexStringtoInt(registers[op3]);

    uint32_t result = value1 | value2;

    stringstream ss;
    ss << hex << uppercase << setw(8) << setfill('0') << result;
    registers[op1] = "0x" + ss.str();

    cout << "ORR " << operand1 << ", " << operand2 << ", " << operand3 << ": ";
    cout << "0x" << setw(8) << setfill('0') << hex << uppercase << result << endl;

    printRegisters();
    bool N = (result & 0x80000000) != 0; 
    bool Z = result == 0;
    printFlagStatus(N, Z, 0, 0);
}

void Calculator::XOR(const string operand1, const string operand2, const string operand3){
   int op1 = operand1[1] - '0';
    int op2 = operand2[1] - '0';
    int op3 = operand3[1] - '0';

    uint32_t value1 = hexStringtoInt(registers[op2]);
    uint32_t value2 = hexStringtoInt(registers[op3]);

    uint32_t result = value1 ^ value2;

    stringstream ss;
    ss << hex << uppercase << setw(8) << setfill('0') << result;
    registers[op1] = "0x" + ss.str();

    cout << "XOR " << operand1 << ", " << operand2 << ", " << operand3 << ": ";
    cout << "0x" << setw(8) << setfill('0') << hex << uppercase << result << endl;

    printRegisters();
    bool N = (result & 0x80000000) != 0; 
    bool Z = result == 0;
    printFlagStatus(N,Z, 0, 0);
}

void Calculator::printFlagStatus(bool N, bool Z,bool C, bool V){

    cout << "N:" << (N ? "1" : "0") << " Z:" << (Z ? "1" : "0") << " C:" << (C ? "1" : "0") << " V:" << (V ? "1" : "0") << endl <<endl ;

}

void Calculator::MOV(const string operand1, const string operand2) {

    string reg = removeWhitespaces(operand1);
    string imm = removeWhitespaces(operand2.substr(3));
    
    uint32_t value = 0;
    stringstream ss;
    ss << hex << imm;
    ss >> value; 
    
    int regIndex = reg[1] - '0';
    registers[regIndex] = "0x" + imm;

    cout << "MOV " << reg << " #0x" << imm << endl;
    printRegisters();
  
    printFlagStatus(0,0,0,0); 
}

void Calculator::CMP(const string operand1, const string operand2) {
    int op1 = operand1[1] - '0';
    int op2 = operand2[1] - '0';

    uint32_t value1 = hexStringtoInt(registers[op1]);
    uint32_t value2 = hexStringtoInt(registers[op2]);

    uint32_t result = value1 - value2;
    cout << "CMP " << operand1 << operand2 << endl;

    
    bool N = (result & 0x80000000) != 0; 
    bool Z = result == 0;
    bool C = value1 >= value2; 
    bool V = ((value1 ^ value2) & 0x80000000) && ((value1 ^ result) & 0x80000000);
    printRegisters();
    printFlagStatus(N, Z, C, V);
    
}


void Calculator::TST(const string operand1, const string operand2) {
    int op1 = operand1[1] - '0';
    int op2 = operand2[1] - '0';

    uint32_t value1 = hexStringtoInt(registers[op1]);
    uint32_t value2 = hexStringtoInt(registers[op2]);

    uint32_t result = value1 & value2;
    cout << "TST " << operand1 << operand2 << endl;

     
    printRegisters();
    printFlagStatus(0,0,0,0);
   
}


string Calculator::toUpper(const string str) {
    string result = str;
    for (size_t i = 0; i < result.length(); i++) {
        result[i] = toupper(result[i]);
    }
    return result;
}

void Calculator::printRegisters() {
    for (int i = 0; i < 8; i++) {
        cout << "R" << i << ":" << hex << uppercase << registers[i] << " ";
    }
    cout << endl;
}
    

string Calculator::removeWhitespaces(const string str) {
    string result;
    for (size_t i = 0; i < str.length(); ++i) {
        if (!isspace(str[i])) {
            result += str[i];
        }
    }
    return result;
}

int Calculator::hexCharToInt(char c) {
    if ('0' <= c && c <= '9')
        return c - '0';
    else if ('A' <= c && c <= 'F')
        return c - 'A' + 10;
    else if ('a' <= c && c <= 'f')
        return c - 'a' + 10;
    else
        return -1; 
}

int Calculator::hexStringtoInt(const string& hexString) {
    int result = 0;

    for (size_t i = 0; i < hexString.size(); ++i) {
        char c = hexString[i];
        int value = hexCharToInt(c);
        
        result = result * 16 + value;
    }

    return result;
}




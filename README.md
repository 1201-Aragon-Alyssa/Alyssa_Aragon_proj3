# Alyssa_Aragon_proj3
This ReadMe provides an overview of the Calculator class and its functionalities. The Calculator class is designed to simulate a simple calculator that performs arithmetic and logical operations on 32-bit hexadecimal values. It also calculates and displays the corresponding flags (N, Z, C, and V) for specific operations.

# Working Process
The calculator program processes the command-line arguments to determine the operation and the input numbers. It performs the requested operation and prints the result along with the flag status.

Each operation is implemented using appropriate C++ operators and functions. The input hexadecimal numbers are converted to 32-bit unsigned integers for arithmetic operations and logical operations. The result of each operation is then converted back to a hexadecimal string for printing.

# Flags
The Calculator class implements and tracks four flags associated with arithmetic and logical operations: N (Negative), Z (Zero), C (Carry), and V (Overflow). The Negative flag (N) is set to 1 if the result of an operation is negative, meaning the most significant bit (MSB) of the result is 1. Otherwise, it is set to 0. The Negative flag (N) is set to 1 if the result of an operation is negative, meaning the most significant bit (MSB) of the result is 1. Otherwise, it is set to 0. The Negative flag (N) is set to 1 if the result of an operation is negative, meaning the most significant bit (MSB) of the result is 1. The Negative flag (N) is set to 1 if the result of an operation is negative, meaning the most significant bit (MSB) of the result is 1.  

# Correctness 
The Calculator class demonstrates correct arithmetic operations and ensures that the results are accurately stored in the appropriate registers. Each arithmetic operation, including ADDS, SUBS, ANDS, ORR, XOR, LSLS, and LSRS, has been implemented correctly and successfully generates the expected results based on the provided operands.

The Calculator class uses the registers array to store the results of arithmetic operations. After performing each arithmetic operation, the class updates the corresponding register with the computed result. This process ensures that the results are accurately placed in the registers for future use and display.

However, while the arithmetic operations and register placement work as expected, some of the flags (N, Z, C, V) might not always display the correct values. The primary reason for this is the challenge of preserving the previous flag values and updating only the relevant flags for each operation. To improve the correctness of the flags, further research and development are required to implement mechanisms that preserve the previous flag values correctly. Additional understanding of ARM processor flag handling and more sophisticated flag update strategies will be instrumental in achieving accurate flag representations for all operations.


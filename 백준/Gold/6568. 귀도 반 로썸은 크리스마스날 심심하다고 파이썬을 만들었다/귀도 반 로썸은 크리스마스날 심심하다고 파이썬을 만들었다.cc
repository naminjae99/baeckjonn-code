#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int parse_str_to_bin(string str_bin) {
    int ret = 0;
    for (int i = 0; i < str_bin.size(); i++) {
        ret += ((str_bin[i] - '0') * (pow(2,str_bin.size() - 1 - i)));
    }
    return ret;
}

int main() {
    while (1) {
        vector<int> memory;
    
        for (int i = 0; i < 32; i++) {
            string cur_oper;
            cin >> cur_oper;
            if (cin.eof()) return 0;
            memory.push_back(parse_str_to_bin(cur_oper));
        }
    
        int pc = 0;
        int adder = 0;

        while (1) {
            int type_of_oper = memory[pc] / 32;
            int operand = memory[pc] % 32;
        
            if (7 == type_of_oper) break;
        
            pc = (pc + 1) % 32;
     
            switch (type_of_oper)
            {
            case 0:
                memory[operand] = adder;    
                break;
            case 1:
                adder = memory[operand];
                break;
            case 2:
                if (0 == adder) pc = operand;
                break;
            case 4:
                adder = (adder + 255) % 256;
                break;
            case 5:
                adder = (adder + 1) % 256;;
                break;
            case 6:
                pc = operand;
                break;
            default:
                break;
            }
        }

        for (int i = 7; i >= 0; i--) {
            cout << ((adder >> i) & 1);
        }
        cout << '\n';
    }
}
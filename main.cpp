#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


    class VendingMachine {
private:
    int x;
    int w;
    int k1;
    int k;
    int t;
    int s;

public:

    VendingMachine() {
        k = 0;
        k1 = 0;
        t = 0;
        w = 0;
        x = 1;
    }

    void PrintPrivateVariables() {
        std::cout << "\nPrivate variables: x = " << x << ", w = " << w << ", k1 = " << k1
                  << ", k = " << k << ", t = " << t << std::endl;
    } //Testing oriented method

    int Coin() {
        

        if (x == 1) {
            if ((t + 25 >= w) && (w > 0)) {
                s = 0;
                t = 0;
                x = 2;
                return 1;
            } else if (t + 25 < w) {
                t += 25;
                return 1;
            }
        } else if ((x > 1) && (x < 6)) {
            std::cout << "RETURN COIN" << std::endl;
            return 1;
        }
        return 0;
    }

    int SmallCup() {
        
        if ((x == 2) || (x == 3)) {
            s = 2;
            return 1;
        }
        return 0;
    }

    int LargeCup() {
        
        if ((x == 2) || (x == 3)) {
            s = 1;
            return 1;
        }
        return 0;
    }

    int Sugar() {
        
        if ((x == 2) || (x == 3)) {
            if (x == 2)
                x = 3;
            else
                x = 2;
            return 1;
        }
        return 0;
    }

    int Coffee() {

        if ((x == 2) || (x == 3)) {
            


            if ((x == 2) && (k > 1) && (s == 2)) {
                std::cout << "DISPOSE SMALL CUP OF COFFEE" << std::endl;
                k--;
                x = 1;
                return 1;
            } 

            else if ((x == 2) && (k1 > 1) && (s == 1)) {
                std::cout << "DISPOSE LARGE CUP OF COFFEE" << std::endl;
                k1--;
                x = 1;
                return 1;
            } 

            else if ((x == 2) && (k1 == 1) && (s == 1)) {
                std::cout << "DISPOSE LARGE CUP OF COFFEE" << std::endl;
                k1--;
                x = 5;
                return 1;
            } 

            else if ((x == 2) && (k == 1) && (s == 2)) {
                std::cout << "DISPOSE SMALL CUP OF COFFEE" << std::endl;
                k--;
                x = 4;
                return 1;
            } 

            else if ((x == 3) && (k == 1) && (s == 2)) {
                std::cout << "DISPOSE SMALL CUP OF COFFEE WITH SUGAR" << std::endl;
                k--;
                x = 4;
                return 1;
            } 

            else if ((x == 3) && (k1 == 1) && (s == 1)) {
                std::cout << "DISPOSE LARGE CUP OF COFFEE WITH SUGAR" << std::endl;
                k1--;
                x = 5;
                return 1;
            }

            if ((x == 3) && (k > 1) && (s == 2)) {
                std::cout << "DISPOSE SMALL CUP OF COFFEE WITH SUGAR" << std::endl;
                k--;
                x = 1;
                return 1;
            } 

            else if ((x == 3) && (k1 > 1) && (s == 1)) {
                std::cout << "DISPOSE LARGE CUP OF COFFEE WITH SUGAR" << std::endl;
                k1--;
                x = 1;
                return 1;
            }
        }
        return 0;
    }

    int InsertLargeCups(int n) {
        
        if ((x == 1) && (n > 0)) {
            k1 += n;
            return 1;
        } else if ((x == 5) && (n > 0)) {
            k1 = n;
            x = 1;
            return 1;
        }
        return 0;
    }

    int InsertSmallCups(int n) {
          
        if ((x == 1) && (n > 0)) {
            k += n;
            return 1;
        } else if ((x == 4) && (n > 0)) {
            k = n;
            x = 1;
            return 1;
        }
        return 0;
    }

    int SetPrice(int p) {
      
        if ((x == 1) && (p > 0)) {
            w = p;
            
            return 1;
        }
        return 0;
    }

    int Cancel() {
       
        if ((x == 2) || (x == 3)) {
            std::cout << "RETURN COINS" << std::endl;
            x = 1;
            return 1;
        }
        return 0;
    }

    int Dispose() {
   
        if (x == 1) {
            std::cout << "SHUT DOWN" << std::endl;
            x = 6;
            return 1;
        }
        return 0;
    }

};
void clearScreen() {
    std::cout << "\033[2J\033[1;1H"; // ANSI escape codes to clear screen
}
// Function to split a string into tokens
std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream iss(str);
    std::string token;
    while (std::getline(iss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Execute a single test case
void executeTestCase(VendingMachine& vendingMachine, const std::vector<std::string>& tokens) {
    int r;
    for (size_t i = 1; i < tokens.size(); i += 1) {
        const std::string& command = tokens[i];
        if ((command == "SetPrice")||(command == "InsertLargeCups")||(command == "InsertSmallCups")){
const int value = std::stoi(tokens[i + 1]);
            if (command == "SetPrice") {
            std::cout << "\n\t\t\tSetPrice() function called."<< std::endl;
            r = vendingMachine.SetPrice(value);
            i += 1;
        }
         if (command == "InsertSmallCups") {
             std::cout << "\n\t\t\tInsertSmallCups() function called."<< std::endl;
            r = vendingMachine.InsertSmallCups(value);                
            i += 1;
        }

         if (command == "InsertLargeCups") {
           std::cout << "\n\t\t\tInsertLargeCups() function called."<< std::endl;
            r = vendingMachine.InsertLargeCups(value);                
            i += 1;
        }
         
        }
        
         if (command == "Coin") {
            std::cout << "\n\t\t\tCoin() function called."<< std::endl;
                r = vendingMachine.Coin();
                std::cout << "\nreturned value: "<<r<< std::endl;
                
        }
         if (command == "Sugar") {
            std::cout << "\n\t\t\tSugar() function called."<<std::endl;
                r = vendingMachine.Sugar();
                std::cout << "\nreturned value: "<<r<< std::endl;
                
        }
         if (command == "Coffee") {
           std::cout << "\n\t\t\tCoffee() function called."<< std::endl;
                r = vendingMachine.Coffee();
                std::cout << "\nreturned value: "<<r<< std::endl;
            std::cout <<  "\n"   << std::endl;
        }
         if (command == "Dispose") {
            std::cout << "\n\t\t\tDispose()function called."<< std::endl;
                r = vendingMachine.Dispose();
                std::cout << "\nreturned value: "<<r<< std::endl;
                vendingMachine.PrintPrivateVariables();

            std::cout <<  "\n"   << std::endl;
        }
        
         if (command == "SmallCup") {
           std::cout << "\n\t\t\tSmallCup() function called."<< std::endl;
                r = vendingMachine.SmallCup();
                std::cout << "\nreturned value: "<<r<< std::endl;
             
        }
         if (command == "LargeCup") {
           std::cout << "\n\t\t\tLargeCup() function called."<< std::endl;
                r = vendingMachine.LargeCup();
                std::cout << "\nreturned value: "<<r<< std::endl;
           
        }
         if (command == "Cancel") {
           std::cout << "\n\t\t\tCancel() function called."<< std::endl;
                r = vendingMachine.Cancel();
                std::cout << "\nreturned value: "<<r<< std::endl;

            std::cout << "\n"   << std::endl;
            
        }
    }
}
int main() {
    

    // Read test cases from TS.txt
    std::ifstream inputFile("TS.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening TS.txt" << std::endl;
        return 1;
    }
    
    std::string line;
    while (std::getline(inputFile, line)) {
        VendingMachine vendingMachine;
        if (!line.empty()) {
            std::vector<std::string> tokens = split(line, ' ');
            
            if (!tokens.empty()) {
                std::cout << "Executing test case: " << tokens[0] << std::endl;
                executeTestCase(vendingMachine, tokens);
                std::cout << "-------------------------" << std::endl;
            }
        }
    }

    inputFile.close();
    return 0;
}

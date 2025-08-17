#include <iostream>
#include "Truckloads.h"
#include "EfficientTruckloads.h"
#include "Reverser.h"

int main() {
    Truckloads t;
    std::cout << t.numTrucks(14,3) << "\n";  
    std::cout << t.numTrucks(15,1) << "\n";   
    std::cout << t.numTrucks(1024,5) << "\n"; 

    EfficientTruckloads et;
    std::cout << et.numTrucks(1024,5) << "\n"; 

    Reverser r;
    std::cout << r.reverseDigit(12345) << "\n";     
    std::cout << r.reverseDigit(-7) << "\n";        
    std::cout << r.reverseString("abcde") << "\n";  
    std::cout << r.reverseString("") << "\n";       
    return 0;
}

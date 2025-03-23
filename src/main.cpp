#include <objects.h>
#include <vector.h>
#include <iostream>
#include <cmath>

int main(){

    std::cout << "Testing" << "\n" << "Creating Vector Array" << "\n";
    objects::Circle circle_one(vector::Vector<float, 2>(0.0f, 1.5f), 1.5f, 10.3f, false, 7.5f);

    vector::Vector<float, 2> position= circle_one.getPosition();
    
    std::cout << "circle_one x position = " << position[0] << ", circle_one y position = " << position[1] << "\n";

    // Wait for user input to close the window
    std::cout << "Press Enter to exit...";
    std::cin.get(); 

    return 0;
}
#include <objects.h>
#include <iostream>
#include <cmath>

int main(){

    std::cout << "Testing" << "\n" << "Creating Circle from Objects" << "\n";
    objects::Circle circle_one(0.0f, 1.5f, 10.3f, 7.5f);

    float x = circle_one.getX();
    float y = circle_one.getY();
    
    std::cout << "circle_one x position = " << x << ", circle_one y position = " << y << "\n";

    // Wait for user input to close the window
    std::cout << "Press Enter to exit...";
    std::cin.get(); 

    return 0;
}
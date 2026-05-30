#include "raindrops.h"


namespace raindrops {

std::string convert(int number) {
    std::string final_string = ""; 
    
    if (number % 3 == 0) {
        final_string += "Pling";
    }
    if (number % 5 == 0) {
        final_string += "Plang";
    }

    if (number % 7 == 0) {
        final_string += "Plong";
    }

    if ((number % 3 != 0) &&(number % 5 != 0) && (number % 7 != 0)){
        final_string = std::to_string(number);
    };

    return final_string; // Added missing ;
}

}  // namespace raindrops
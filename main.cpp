//use lower_snake_case
#include <fstream>
#include "JSON parser class.hpp"

using ifstream = std::ifstream;
using json = nlohmann::json;
using string = std::string;

int main() {
    short number_of_file = 0;
    std::cout << "Enter number of file for execution: ";
    std::cin >> number_of_file;
    ifstream file("../examples of json files/example " + std::to_string(number_of_file) + ".json");
    if (file.is_open()) {
        json data = json::parse(file);
        parser::iterating_over_commands(data);
        parser::get_all_values_and_marks();
    } else {
        std::cout << "file was not opened";
    }
    return 0;
}
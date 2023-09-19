//use camelCase
#include <fstream>
#include "JSON parser class.hpp"

using ifstream = std::ifstream;
using json = nlohmann::json;
using string = std::string;

int main() {
    ifstream file("../examples of json files/example 4.json");
    if(file.is_open()){
        json data = json::parse(file);
        parser::iterating_over_commands(data);
        parser::get_all_values_and_marks();
    } else{
        std::cout << "file was not opened";
    }
    return 0;
}
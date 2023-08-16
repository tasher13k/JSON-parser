//use camelCase
#include <iostream>
#include <fstream>
#include "json.hpp"

using ifstream = std::ifstream;
using json = nlohmann::json;
using string = std::string;


int main() {
    ifstream file("../examples of json files/example 1.json");
    if(file.is_open()){
        json data = json::parse(file);
        string pr = data[0];
        string s[] = {to_string(data[1][0]), data[1][1]};
        string es = data[2];

// Print the values
        std::cout << "Who: " << pr << std::endl;
        std::cout << "Variable: " << s[0] + " " + s[1] << std::endl;
        std::cout << "How: " << es << std::endl;
    } else{
        std::cout << "file was not opened";
    }
    return 0;
}

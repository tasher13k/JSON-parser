#ifndef JSON_PARSER_JSON_PARSER_CLASS_H
#define JSON_PARSER_JSON_PARSER_CLASS_H
#include "json.hpp"
#include <iostream>
#include <unordered_map>

using json = nlohmann::json;
using string = std::string;
using pointer_to_methods_for_commands = void (*)(json);
using map_type_for_commands = std::unordered_map<string, pointer_to_methods_for_commands>;

struct parser{

    static void iterating_over_commands(json & list_of_commands){
        auto command = list_of_commands[0];
          for(auto it = list_of_commands.begin(); it != list_of_commands.end(); ++it)   {
              command = *it;

              auto function_for_execute_command = my_map.at(to_string(command[0]));
              function_for_execute_command(command);
          }
    }
    private:

    static void make_variable(json j){
        std::cout << "mk var command" << std::endl;
    }
    static void give_value_to_variable(json j){
        std::cout << "give val command" << std::endl;
    }
    static void make_mark(json j){
        std::cout << "mk mark command" << std::endl;
    }
    static void follow_mark_if(json j){
        std::cout << "follow mark command" << std::endl;
    }

    static map_type_for_commands my_map;

};

map_type_for_commands parser::my_map ={{"\"make_variable\"", &make_variable}, {"\"give_value_to_variable\"", &give_value_to_variable}, {"\"make_mark\"", &make_mark}, {"\"follow_mark_if\"", &follow_mark_if}};

#endif //JSON_PARSER_JSON_PARSER_CLASS_H

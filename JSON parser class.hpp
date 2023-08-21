#ifndef JSON_PARSER_JSON_PARSER_CLASS_H
#define JSON_PARSER_JSON_PARSER_CLASS_H
#include "json.hpp"
#include <iostream>
#include <unordered_map>

using json = nlohmann::json;
using string = std::string;
using pointer_to_methods_for_commands = void (*)(json);
using map_type_for_commands = std::unordered_map<string, pointer_to_methods_for_commands>;
using map_type_for_variables = std::unordered_map<string, int>;

struct parser{
    static void iterating_over_commands(json & list_of_commands);
private:

    static void make_variable(json j);
    static void give_value_to_variable(json);
    static void make_mark(json);
    static void follow_mark_if(json);

    static map_type_for_commands map_for_commands;
    static map_type_for_variables map_for_variables;
};
#endif //JSON_PARSER_JSON_PARSER_CLASS_H

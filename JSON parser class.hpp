#ifndef JSON_PARSER_JSON_PARSER_CLASS_H
#define JSON_PARSER_JSON_PARSER_CLASS_H
#include "json.hpp"
#include <iostream>
#include <unordered_map>

using json = nlohmann::json;
using string = std::string;
using iter_on_const_json = json::const_iterator;
using ref_on_iter_on_const_json = iter_on_const_json &;
using pointer_to_methods_for_commands = iter_on_const_json (* const)(ref_on_iter_on_const_json);
//this type will be necessary to call functions depending on the name from the parsed file
//this return type helps with "follow mark" command via value from map_for_marks which stores iterator on command in parsed file

using map_type_for_commands = const std::unordered_map<string, pointer_to_methods_for_commands>;
using map_type_for_variables = std::unordered_map<string, int>;
using map_type_for_marks = std::unordered_map<string, json::const_iterator>;

struct parser{
    static void get_all_values_and_marks();

    static void iterating_over_commands(json const & list_of_commands);
private:
    static iter_on_const_json make_variable(ref_on_iter_on_const_json);
    static iter_on_const_json give_value_to_variable(ref_on_iter_on_const_json);
    static iter_on_const_json make_mark(ref_on_iter_on_const_json);
    static iter_on_const_json follow_mark_if(ref_on_iter_on_const_json);

    static map_type_for_commands map_for_commands;
    static map_type_for_variables map_for_variables;
    static map_type_for_marks map_for_marks;
};
#endif //JSON_PARSER_JSON_PARSER_CLASS_H
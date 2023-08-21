#include "JSON parser class.hpp"

map_type_for_commands parser::map_for_commands ={{"\"make_variable\"", &make_variable}, {"\"give_value_to_variable\"", &give_value_to_variable}, {"\"make_mark\"", &make_mark}, {"\"follow_mark_if\"", &follow_mark_if}};

void parser::iterating_over_commands(json &list_of_commands) {
    auto command = list_of_commands[0];
    for(auto it = list_of_commands.begin(); it != list_of_commands.end(); ++it)   {
        command = *it;

        auto function_for_execute_command = map_for_commands.at(to_string(command[0]));
        function_for_execute_command(command);
    }
}

void parser::make_variable(json j) {
    std::cout << "mk var command" << std::endl;
}

void parser::give_value_to_variable(json) {
    std::cout << "give val command" << std::endl;
}

void parser::make_mark(json) {
    std::cout << "mk mark command" << std::endl;
}

void parser::follow_mark_if(json) {
    std::cout << "follow mark command" << std::endl;
}

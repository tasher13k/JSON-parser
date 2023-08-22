#include "JSON parser class.hpp"

map_type_for_commands parser::map_for_commands ={{"make variable", &make_variable}, {"give value to variable", &give_value_to_variable}, {"make mark", &make_mark}, {"follow mark if", &follow_mark_if}};
map_type_for_variables parser::map_for_variables = {};
map_type_for_marks parser::map_for_marks = {};

void parser::iterating_over_commands(json const & list_of_commands) {
    for(json::const_iterator it = list_of_commands.begin(); it != list_of_commands.end(); ++it)   {
        auto function_for_execute_command = map_for_commands.at((*it)[0]);
        it = function_for_execute_command(it);
    }
}
//struct of command: ["make variable", "name of variable"]
iter_on_const_json parser::make_variable(ref_on_iter_on_const_json make_var_command_iter) {
    std::cout << "mk var command " << (*make_var_command_iter)[1] << std::endl;
    map_for_variables.emplace((*make_var_command_iter)[1], 0);
    return make_var_command_iter;
}
//struct of command: ["give value to variable", expression for assigning, "name of variable"]
iter_on_const_json parser::give_value_to_variable(ref_on_iter_on_const_json give_val_command_iter) {
    std::cout << "give val command, finding  " << (*give_val_command_iter)[2] << " and value will be " << (*give_val_command_iter)[1] << std::endl;
    map_for_variables.find((*give_val_command_iter)[2])->second = int((*give_val_command_iter)[1]); //check this place
    return give_val_command_iter;
}
//struct of command: ["make mark", "name of mark"]
iter_on_const_json parser::make_mark(ref_on_iter_on_const_json make_mark_command) {
    std::cout << "mk mark command, mark name -  " << (*make_mark_command)[1] << std::endl;
    map_for_marks.emplace((*make_mark_command)[1], make_mark_command);
    return make_mark_command;
}
//struct of command:  ["follow mark if", "name of variable", "name of mark"]
iter_on_const_json parser::follow_mark_if(ref_on_iter_on_const_json follow_mark_command) {
    std::cout << "follow mark command, var to check -  " << (*follow_mark_command)[1] << std::endl;
    auto value_of_variable = map_for_variables.find((*follow_mark_command)[1])->second;
    std::cout << "name of var is " << value_of_variable << std::endl;
    return  value_of_variable ? map_for_marks.find((*follow_mark_command)[2])->second - 1 : follow_mark_command;
}

void parser::get_all_values_and_marks() {
    std::cout << std::endl << "Variables in map_for_variables: " << std::endl;
    for(auto& [name, value] : map_for_variables){
        std::cout << "name: " << name << ", value: " << value << std::endl;
    }
    std::cout << "Names of marks in map_for_marks: " << std::endl;
    for(auto [name, value] : map_for_marks){
        std::cout << "name: " << name << std::endl;
    }
}
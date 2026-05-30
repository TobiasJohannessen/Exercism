#include <string>

namespace log_line {
std::string message(std::string line) {
    int colon_index = line.find(":");
    std::string message = line.substr(colon_index + 2);
    return message;
}

std::string log_level(std::string line) {
    int bracket_start = line.find("[");
    int bracket_end = line.find("]");
    return line.substr(bracket_start + 1, bracket_end - 1);
}

std::string reformat(std::string line) {
    std::string message = log_line::message(line);
    std::string log_level = log_line::log_level(line);
    return message + " (" + log_level + ")";
}
}  // namespace log_line

#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> new_scores;
    for (size_t i = 0; i < student_scores.size(); i++){
        new_scores.emplace_back(static_cast<int>(student_scores[i]));
    }
    return new_scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int count = 0;
    for (size_t i= 0; i < student_scores.size(); i++){
        if (student_scores[i] <= 40){count++;};
    }
    return count;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    double letter_step = (highest_score - 40) / 4;
    std::array<int,4> letter_grades = {41, 41+static_cast<int>(letter_step), 41 + static_cast<int>(letter_step*2), 41+static_cast<int>(letter_step*3)};
    return letter_grades;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> ordered_ranking{};
    size_t student_size = student_scores.size();
    for (size_t i = student_size; i > 0; i--){
        std::string current_student = std::to_string(student_size-i+1) + ". " + student_names[student_size - i] + ": " + std::to_string(student_scores[student_size - i]);
        ordered_ranking.emplace_back(current_student);
    }
    return ordered_ranking;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names){
    // Loop through the scores sequentially
    for (size_t i = 0; i < student_scores.size(); i++) {
        // As soon as we find the FIRST 100, return that student's name immediately
        if (student_scores[i] == 100) {
            return student_names[i];
        }
    }
    
    // If the loop finishes and no 100 was found, return an empty string
    return "";
}

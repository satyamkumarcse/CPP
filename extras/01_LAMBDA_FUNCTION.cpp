#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

struct Student
{
    string name;
    int score;
};

int main()
{
    vector<Student> classList = {
        {"Alice", 92},
        {"Bob", 78},
        {"Charlie", 88},
        {"Diana", 65},
        {"Ethan", 95},
        {"Fiona", 72}
    };

    int threshold = 80;

    vector<Student> honorsList;

    auto isHonorsStudent = [threshold](const Student& s) -> bool
    {
        if(s.score >= threshold)
            return true;
        return false;
    };

    copy_if(classList.begin(), classList.end(),
            back_inserter(honorsList),
            isHonorsStudent);

    cout << "Students above threshold:\n";

    for(const auto &s : honorsList)
    {
        cout << s.name << " : " << s.score << endl;
    }

    return 0;
}
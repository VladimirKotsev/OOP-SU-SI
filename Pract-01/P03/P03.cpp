#include <iostream>

constexpr unsigned int STUDENT_NAME = 16;

enum class Major
{
    SI,
    IS,
    KN,
    INF,
    MI,
    PM,
    AD
};

struct Student
{
    char name[STUDENT_NAME];
    int fn;
    Major major;
};

struct Course
{
    Student* students;
    int studentsCount;
};

int numberSize(int n)
{
    int count = 0;
    while (n != 0)
    {
        n /= 10;
        count++;
    }

    return count;
}

bool strAreEqual(char* str1, const char* str2)
{
    while (*str1 && *str2)
    {
        if (*str1 != *str2)
            return false;

        str1++;
        str2++;
    }

    return true;
}



void readStudent(Student& student)
{
    int facultyNumber = 0;
    char major[3];
    std::cin >> student.name;
    std::cin >> facultyNumber;
    if (numberSize(facultyNumber) != 6)
    {
        std::cout << "Invalid faculty number";
        return;
    }
    student.fn = facultyNumber;
    std::cin >> major;

    if (strAreEqual(major, "SI"))
        student.major = Major::SI;
    else if (strAreEqual(major, "IS"))
        student.major = Major::IS;
    else if (strAreEqual(major, "KN"))
        student.major = Major::KN;
    else if (strAreEqual(major, "INF"))
        student.major = Major::INF;
    else if (strAreEqual(major, "MI"))
        student.major = Major::MI;
    else if (strAreEqual(major, "PM"))
        student.major = Major::PM;
    else if (strAreEqual(major, "AD"))
        student.major = Major::AD;
    else
    {
        std::cout << "Invalid major!";
        return;
    }
}

int main()
{
    int n = 0;
    std::cin >> n;

    Student* students = new Student[n];

    for (size_t i = 0; i < n; i++)
    {
        Student student;
        readStudent(student);
        students[i] = student;
    }

    Course course;
    course.students = students;
    course.studentsCount = n;
}


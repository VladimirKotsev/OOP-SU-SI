#include <iostream>

constexpr unsigned int STUDENT_NAME = 16;
constexpr unsigned int MAJOR_NAME = 16;

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

Major readMajor()
{
    Major major;
    char input[MAJOR_NAME];
    std::cin >> input;

    if (strAreEqual(input, "SI"))
        major = Major::SI;
    else if (strAreEqual(input, "IS"))
        major = Major::IS;
    else if (strAreEqual(input, "KN"))
        major = Major::KN;
    else if (strAreEqual(input, "INF"))
        major = Major::INF;
    else if (strAreEqual(input, "MI"))
        major = Major::MI;
    else if (strAreEqual(input, "PM"))
        major = Major::PM;
    else if (strAreEqual(input, "AD"))
        major = Major::AD;
    else
    {
        std::cout << "Invalid major!";
        return;
    }

    return major;
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
    student.major = readMajor();
}

int countOfStudentFromMajor(const Course course, Major major, Student* students)
{
    int count = 0;
    for (size_t i = 0; i < course.studentsCount; i++)
    {
        if (course.students[i].major == major)
            students[count++] = course.students[i]; //adds the student to the array of students from a given major and increments count;
    }

    return count;
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

    Major major = readMajor();
    Student* studentsFromMajor = new Student[course.studentsCount]; // not more than the students in the course

    delete[] students;
    delete[] studentsFromMajor;
}


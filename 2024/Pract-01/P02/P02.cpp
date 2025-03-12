#include <iostream>

constexpr unsigned int EVENT_NAME = 16;

enum class DayOfWeek
{
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

struct Event
{
    char name[EVENT_NAME];
    DayOfWeek dayOfWeek;
    double duration;
};

// извежда на стандартния изход информацията за event-a (форматирайте както пожелаете) 
void printEvent(const Event& myEvent)
{
    std::cout << "Event: " << myEvent.name << std::endl;
    switch (myEvent.dayOfWeek)
    {
    case DayOfWeek::Monday:
        std::cout << "Day: Monday" << std::endl;
        break;
    case DayOfWeek::Tuesday:
        std::cout << "Day: Tuesday" << std::endl;
        break;
    case DayOfWeek::Wednesday:
        std::cout << "Day: Wednesday" << std::endl;
        break;
    case DayOfWeek::Thursday:
        std::cout << "Day: Thursday" << std::endl;
        break;
    case DayOfWeek::Friday:
        std::cout << "Day: Friday" << std::endl;
        break;
    case DayOfWeek::Saturday:
        std::cout << "Day: Saturday" << std::endl;
        break;
    case DayOfWeek::Sunday:
        std::cout << "Day: Sunday" << std::endl;
        break;
    }
    std::cout << "Duration: " << myEvent.duration << std::endl;
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

void readEvent(Event& myEvent)
{
    DayOfWeek dayOfWeek;
    char day[10];

    std::cin >> myEvent.name;
    //std::cin.getline(myEvent.name, EVENT_NAME);
    std::cin >> day;

    if (strAreEqual(day, "Monday"))
    {
        dayOfWeek = DayOfWeek::Monday;
    }
    else if (strAreEqual(day, "Tuesday"))
    {
        dayOfWeek = DayOfWeek::Tuesday;
    }
    else if (strAreEqual(day, "Wednesday"))
    {
        dayOfWeek = DayOfWeek::Wednesday;
    }
    else if (strAreEqual(day, "Thursday"))
    {
        dayOfWeek = DayOfWeek::Thursday;
    }
    else if (strAreEqual(day, "Friday"))
    {
        dayOfWeek = DayOfWeek::Friday;
    }
    else if (strAreEqual(day, "Saturday"))
    {
        dayOfWeek = DayOfWeek::Saturday;
    }
    else if (strAreEqual(day, "Sunday"))
    {
        dayOfWeek = DayOfWeek::Sunday;
    }
    else
    {
        std::cout << "Incorrect day!";
        return;
    }

    std::cin >> myEvent.duration;
    myEvent.dayOfWeek = dayOfWeek;
}

// извежда на стандартния изход всички event-и от масива events, които се състоят на ден day
void printEventsOn(DayOfWeek day, const Event* events, int size)
{
    if (!events)
        return;

    for (size_t i = 0; i < size; i++)
    {
        if (events[i].dayOfWeek == day)
            printEvent(events[i]);
    }
}

void readDayOfWeek(DayOfWeek& dayOfWeek)
{
    char day[10];
    std::cin >> day;

    if (strAreEqual(day, "Monday"))
    {
        dayOfWeek = DayOfWeek::Monday;
    }
    else if (strAreEqual(day, "Tuesday"))
    {
        dayOfWeek = DayOfWeek::Tuesday;
    }
    else if (strAreEqual(day, "Wednesday"))
    {
        dayOfWeek = DayOfWeek::Wednesday;
    }
    else if (strAreEqual(day, "Thursday"))
    {
        dayOfWeek = DayOfWeek::Thursday;
    }
    else if (strAreEqual(day, "Friday"))
    {
        dayOfWeek = DayOfWeek::Friday;
    }
    else if (strAreEqual(day, "Saturday"))
    {
        dayOfWeek = DayOfWeek::Saturday;
    }
    else if (strAreEqual(day, "Sunday"))
    {
        dayOfWeek = DayOfWeek::Sunday;
    }
    else
    {
        std::cout << "Incorrect day!";
        return;
    }
}

int main()
{
    //P. 02
    int n = 0;
    std::cin >> n;
    Event* arr = new Event[n];

    for (size_t i = 0; i < n; i++)
    {
        Event event1;
        readEvent(event1);
        arr[i] = event1;
    }

    DayOfWeek dayOfWeek;
    readDayOfWeek(dayOfWeek);

    printEventsOn(dayOfWeek, arr, n);

    delete[] arr;

}


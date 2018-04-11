#include <iostream>

using namespace std;

enum life_stage
{
    kid, student, adult, old_man
};

life_stage age_to (int);

int main()
{
    int age;
    cin >> age;
    cout << age_to(age);
    return 0;
}

life_stage age_to (int age)
{
    if (age < 7)
    {
        return kid;
    }
    else if (age < 15)
    {
        return student;
    }
    else return old_man;
}

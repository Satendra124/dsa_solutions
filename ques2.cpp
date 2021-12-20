#include <bits/stdc++.h>
using namespace std;

class student
{
public:
    char name[20];
    int rollno;
    int percentage;
    void getdata()
    {
        cout << "n Enter the name of the student";
        cin >> name;
        cout << "n Enter the roll no.";
        cin >> rollno;
        cout << "n Enter the percentage of the student";
        cin >> percentage;

    }
};
class topper : public student
{
public:
    void display()
    {
        cout << "n Name : " << name;
        cout << "n Roll. No. : " << rollno;
        cout << "n Percentage : " << percentage;
    }
};
main()
{
    int j, k, l, i;
    student s[10];
    for (i = 0; i < 10; i++)
        s[i].getdata();
    
}

#include <bits/stdc++.h>
using namespace std;

class Student{
    public:
        string name;
        double percentage;
        Student(string n,double p){
            name = n;
            percentage = p;
        }
        Student(){}
        void show(){
            cout<<"Name: "<<name<<" Percentage: "<<percentage<<endl;
        }
};
class Topper:public Student{
    public:
    Topper(string n,double p){
        name = n;
        percentage = p;
    }
};

int main()
{
    int n;
    cout<<"number of student: ";
    cin>>n;
    cout<<endl;
    vector<Student> studentList(n);
    vector<Topper*> toppers;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter student name: ";
        cin>>studentList[i].name;
        cout<<endl<<"Enter student percentage: ";
        cin>>studentList[i].percentage;
        cout<<endl;
        if(studentList[i].percentage>=90){
            toppers.push_back(new Topper(studentList[i].name,studentList[i].percentage));
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        studentList[i].show();
    }
    for (int i = 0; i < toppers.size(); i++)
    {
        toppers[i]->show();
    }
    

}
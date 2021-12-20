#include <bits/stdc++.h>
using namespace std;

class Student{
    public:
        int studentId;
        int percentage;
        Topper* topper;
        Student(int id,int per){
            studentId = id;
            percentage = per;

            if(percentage>=90){
                Topper* t = new Topper();
            }
        }
        void printDetails(){
            cout<<"Student ID: "<<studentId<<" Percentage(%): "<<percentage<<endl;
        }
    
};

class Topper : Student{

};

int main()
{
    
}
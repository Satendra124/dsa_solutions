#include <bits/stdc++.h>
using namespace std;

class Student{
    public:
        int id;
        Student(int i){
            id = i;
        }
};

class Person:public Student{
    public:
        string name;
        Person(int i,string n):Student(i){
            name = n;
        }
};

class BasketBallPlayer:Person{
    string tshirtNo;
    int points;
    public:
        BasketBallPlayer(string tNo,int p,string n,int i):Person(i,n){
            tshirtNo = tNo;
            points = p;
        }
        void show(){
            cout<<id<<". Name: "<<name<<" T Shirt No.: "<<tshirtNo<<" Points: "<<points<<endl;
        }
};
int main()
{
    int n;
    cout<<"Number of players: ";
    cin>>n;
    cout<<endl;
    vector<BasketBallPlayer*> players;
    for (int i = 0; i < n; i++)
    {
        string tNo;
        int points;
        string name;
        int id;
        cout<<"ID: ";
        cin>>id;
        cout<<endl;
        cout<<"Name: ";
        cin>>name;
        cout<<endl;
        cout<<"Tshirt No: ";
        cin>>tNo;
        cout<<endl;
        cout<<"Points: ";
        cin>>points;
        cout<<endl;
        BasketBallPlayer* player = new BasketBallPlayer(tNo,points,name,id);
        players.push_back(player);
    }
    for (int i = 0; i < n; i++)
    {
        players[i]->show();
    }
    
    
}
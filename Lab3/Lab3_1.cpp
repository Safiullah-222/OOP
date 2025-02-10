#include<iostream>
using namespace std;

class User{
    public:
    int Age;
    string Name;

};

int main(){
    User obj;
    obj.Name = "Teo";
    obj.Age = 24;

    cout<< "My name "<< obj.Name<< "and my age is "<< obj.Age<< endl;


}
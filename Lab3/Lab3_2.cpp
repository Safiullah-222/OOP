#include<iostream>
using namespace std;

class Date{
    public:
    int month;
    int day;
    int year;

    void displayDate(){
        cout<< month<< "/" << day<< "/" << year << endl;
    };



};

int main(){
    Date date;
    cout<< "Enter month, day and year "<<endl ;
    cin >> date.month>>date.day >> date.year;

    date.displayDate();
    return 0;


}
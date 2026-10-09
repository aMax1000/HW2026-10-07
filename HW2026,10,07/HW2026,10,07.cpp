// HW2026,10,07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
using namespace std;
constexpr auto Dayyear = 360;
constexpr auto Daymonth = 30;
//constexpr std::array<int, 4> arr = {1,2,3,4};


class Arrmod {
    
public:
    int value;
    static constexpr std::size_t size = 1;

    static constexpr std::array<int, 1> arr = { 1 };

        template<int a>
    Arrmod(int value) : value(value) {
        constexpr auto size = 1;
        constexpr std::array<int, size> arr = {a};
        constexpr auto pow = a;
    }

    template<int a, typename... ArgTypes>
    Arrmod(int value):value(value) {
        constexpr auto size = 1+Arrmod::size;
        constexpr auto pow = a * Arrmod::pow;
        constexpr std::array<int, size> newarr = { pow };
        for (int i = 1;i < Arrmod::size;i++) {
            newarr[i]=Arrmod::arr[i-1]
        }
        Arrmod::arr = newarr;
    }
    
    Arrmod(int value) : value(value) {}


/*    int operator[](int i) {
        return  value/ arr[i];
    }*/
};

template<typename T>
int add(T t) {
    return t;
};

template<typename T, typename... ArgTypes>
int add(T t, ArgTypes... args)
{
    return t + add(args...);
}



template <class T, int N>
struct Fifo {
    T t;
};




class Date {
    int days;
public:
    Date(int days) :days(days) {

    }
    Date(int year, int month, int day):
        Date(Dayyear *year 
            +month > Dayyear/Daymonth -1 ? Dayyear - Daymonth : Daymonth * month 
            +day > Daymonth-1 ? Daymonth-1 : day) {
        
    }
    int getyear()const {
        return days / 365;
    }
    int getmonth()const {
        return (days / 30) % 12;
    }
    int getday()const {
        return (days) % 30;
    }

    void setyear(int year) {
        days = Dayyear * year 
            + days % Dayyear;
    }
    void setmonth(int month) {
        int actmonth = (month > Dayyear / Daymonth - 1) ? Dayyear / Daymonth - 1 : month;
        days = Daymonth * actmonth
            +Dayyear*(days/Dayyear) 
            +days % Daymonth;
    }
    void setday(int day) {
        int actday = (day > Daymonth - 1) ? Daymonth - 1 : day;
        days = day
            +Daymonth * (days / Daymonth);
    }
    void setdaysdev(int days) {
        days = days;
    }


    void print() {

    }
};




int main() {
/*    const int Q_SIZE = 4;
    Fifo<int[4], Q_SIZE> f = { 1,2,3,4 };
    std::cout << sizeof f << "\n";
    for(int i=0;i<Q_SIZE;i++){
    cout << *(f.t+i);
    }*/

/*    Arrmod < 4,arr> a(100);
    for (int i = 0;i < 4;i++) {
        cout << a[i];
    }*/
    cout<<add(1, 2, 3);

    Arrmod<2, 3, 5> a(10);

    for (int x `: a.arr){
        std::cout << x << ' ';
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

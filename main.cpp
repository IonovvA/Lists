#include "List.h"
#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    List list1, list2, list3;
    ifstream file("File.txt");
    file >> list1;
    cout << list1 << endl;
    file >> list2;
    cout << list2 << endl;

    cout << "Пересечение списков: " << endl;
    list3 = list1.Intersection(list2);
    cout << list3 << endl;
    
	return 0;
}
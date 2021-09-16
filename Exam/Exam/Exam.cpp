#include <iostream>
#include <fstream>
#include "Header.h"

#pragma warning (disable: 4996)
using namespace std;


int main()
{

    book* lib = nullptr;
    int size_b = 0;
    people* client = nullptr;
    int size_c = 0;
    int choiceBook;
    bool job = 1;

    while (job)
    {
        
        cout << "Enter your choice\n1 - Add\n2 - Show\n3 - Delete\n4 - Read\n5 - Write\n6 - Edit\n";
        cout << "7 - Sort\n8 - Search\n 9 - Take the book\n10 - Return the book\n11 - Book info\n0 - Exit\n";
        cout<<"12 - Active reader\n 13 - Popular book\n -- > ";
        cin >> choiceBook;
        switch (choiceBook)
        {
        case 1: Add(client, size_c, lib, size_b); break;
        case 2: Show(client, size_c, lib, size_b); break;
        case 3: Delete(client, size_c, lib, size_b); break;
        case 4: Read(client, size_c, lib, size_b); break;
        case 5: Write(client, size_c, lib, size_b); break;
        case 6: Edit(client, size_c, lib, size_b); break;
        case 7: Sort(client, size_c, lib, size_b); break;
        case 8: Search(client, size_c, lib, size_b); break;
        case 9: BookOut(lib, client, size_b, size_c); break;
        case 10: BookIn(lib, client, size_b, size_c); break;
        case 11: InfoBook(lib, size_b); break;
        case 12: ActiveReader(client, size_c); break;
        case 13: PopularBook(lib, size_b); break;

        case 0: job = 0; break;
        default: cout << "Wrong case!!!" << endl; break;
        }
    }
}



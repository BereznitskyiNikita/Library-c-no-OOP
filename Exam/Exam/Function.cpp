#include <iostream>
#include <fstream>
#include "Header.h"
#pragma warning (disable:4996)
using namespace std;




void Add(people*& client, int& size_c, book*& lib, int& size_b)
{
    int choice1;
    bool job = 1;
    while (job)
    {
        cout << "Enter your choice\n1 - Add Book\n2 - Add Person\n0 - Exit\n";
        cin >> choice1;
        switch (choice1)
        {
        case 1: AddBook(lib, size_b); break;
        case 2: AddPeople(client, size_c); break;
        case 0: job = 0; break;
        default: cout << "Wrong case, ERROR!" << endl;
        }
    }
}

void Delete(people*& client, int& size_c, book*& lib, int& size_b)
{
    int choice2;
    bool job = 1;
    while (job)
    {
        cout << "Enter your choice\n1 - Delete Book\n2 - Delete Person\n0 - Exit\n";
        cin >> choice2;
        switch (choice2)
        {
        case 1: DeleteBook(lib, size_b); ShowBook(lib, size_b); break;
        case 2: DeletePeople(client, size_c); ShowPeople(client, size_c); break;
        case 0: job = 0; break;
        default: cout << "Wrong case, ERROR!" << endl;
        }
    }
}


void Read(people*& client, int& size_c, book*& lib, int& size_b)
{
    int choice3;
    bool job = 1;
    while (job)
    {
        cout << "Enter your choice\n1 - Read Book\n2 - Read Person\n0 - Exit\n";
        cin >> choice3;
        switch (choice3)
        {
        case 1: ReadBook(lib, size_b); break;
        case 2: ReadPeople(client, size_c); break;
        case 0: job = 0; break;
        default: cout << "Wrong case, ERROR!" << endl;
        }
    }
}



void Edit(people*& client, int& size_c, book*& lib, int& size_b)
{
    int choice4;
    bool job = 1;
    while (job)
    {
        cout << "Enter your choice\n1 - Edit Book\n2 - Edit Person\n0 - Exit\n";
        cin >> choice4;
        switch (choice4)
        {
        case 1: EditBook(lib, size_b); ShowBook(lib, size_b); break;
        case 2: EditPeople(client, size_c); ShowPeople(client, size_c); break;
        case 0: job = 0; break;
        default: cout << "Wrong case, ERROR!" << endl;
        }
    }
}


void Sort(people*& client, int& size_c, book*& lib, int& size_b)
{
    int choice5;
    bool job = 1;
    while (job)
    {
        cout << "Enter your choice\n1 - Sort Book\n2 - Sort Person\n0 - Exit\n";
        cin >> choice5;
        switch (choice5)
        {
        case 1: SortBook(lib, size_b); ShowBook(lib, size_b); break;
        case 2: SortPeople(client, size_c); ShowPeople(client, size_c); break;
        case 0: job = 0; break;
        default: cout << "Wrong case, ERROR!" << endl;
        }
    }
}


void Write(people*& client, int& size_c, book*& lib, int& size_b)
{
    int choice6;
    bool job = 1;
    while (job)
    {
        cout << "Enter your choice\n1 - Sort Book\n2 - Sort Person\n0 - Exit\n";
        cin >> choice6;
        switch (choice6)
        {
        case 1: WriteBook(lib, size_b); break;
        case 2: WritePeople(client, size_c); break;
        case 0: job = 0; break;
        default: cout << "Wrong case, ERROR!" << endl;
        }
    }
}


void Search(people*& client, int& size_c, book*& lib, int& size_b)
{
    int choice7;
    bool job = 1;
    while (job)
    {
        cout << "Enter your choice\n1 - Sort Book\n2 - Sort Person\n0 - Exit\n";
        cin >> choice7;
        switch (choice7)
        {
        case 1: SearchBook(lib, size_b); break;
        case 2: SearchPeople(client, size_c); break;
        case 0: job = 0; break;
        default: cout << "Wrong case, ERROR!" << endl;
        }
    }
}

void Show(people*& client, int& size_c, book*& lib, int& size_b)
{
    int choice8;
    bool job = 1;
    while (job)
    {
        cout << "Enter your choice\n1 - Sort Book\n2 - Sort Person\n0 - Exit\n";
        cin >> choice8;
        switch (choice8)
        {
        case 1: ShowBook(lib, size_b); break;
        case 2: ShowPeople(client, size_c); break;
        case 0: job = 0; break;
        default: cout << "Wrong case, ERROR!" << endl;
        }
    }
}


//функция добавления клиентов библиотеки
void AddPeople(people*& client, int& size_c)
{
    char buff[100];//временная строка
    people* temp = new people[size_c + 1];//создание нового массива на единицу больше от того что был изначально
    for (int i = 0; i < size_c; i++)//цыкл для копирования информации из предыдущего массива в только что созданый
        temp[i] = client[i];
    delete[] client;//удаление старого массива
    client = temp;//копирование из временного массива в постоянный

    cout << "Enter FIO - "; cin.getline(buff, 100);
    client[size_c].FIO = new char[strlen(buff) + 1];
    strcpy(client[size_c].FIO, buff);

    cout << "Enter date of birthday - "; cin.getline(buff, 100);
    client[size_c].bday = new char[strlen(buff) + 1];
    strcpy(client[size_c].bday, buff);

    cout << "Enter number of passport - "; cin.getline(buff, 100);
    client[size_c].numPassport = new char[strlen(buff) + 1];
    strcpy(client[size_c].numPassport, buff);

    cout << "Enter ID of reader - "; cin >> client[size_c].readID;

    cout << "Enter count of readed book - "; cin >> client[size_c].readed;

    cout << "Enter count of book on hand - "; cin >> client[size_c].onHand;

    size_c++;
}


//функция вывода клиентов библиотеки на экран
void ShowPeople(people*& client, int& size_c)
{
    cout << "#\tFIO\tB-Day\t\tNumber passport\tRead ID\tCount readed book\tCount on hand\n";
    for (int i = 0; i < size_c; i++)
    {
        cout << i << "\t" << client[i].FIO << "\t" << client[i].bday << "\t";
        cout << client[i].numPassport << "\t" << client[i].readID << "\t";
        cout << client[i].readed << "\t\t\t" << client[i].onHand << "\n";
        if (client[i].onHand != 0)
        {
            for (int j = 0; j < client[i].onHand; j++)
            {
                cout << "\t" << client[i].lib[j] << "\n";
            }
        }
        cout << "\n";
    }
}




//удаление клиентов из списка
void DeletePeople(people*& client, int& size_c)
{
    people* temp = new people[size_c - 1];

    int delClientIndex;
    cout << "Enter index of client to delete - "; cin >> delClientIndex;

    for (int i = 0; i < size_c; i++)
    {
        if (i < delClientIndex)
            temp[i] = client[i];
        else if (i == delClientIndex)
            continue;
        else if (i > delClientIndex)
            temp[i - 1] = client[i];
    }
    delete[] client;
    client = temp;
    size_c--;
}




//чтение клиентов из файла
void ReadPeople(people*& client, int& size_c)
{
    char buff[100];
    char* temp;
    ifstream fin("peopleIn.txt");
    if (!fin)
        cout << "Wrong file!" << endl;
    else
    {
        while (fin)
        {
            fin.getline(buff, 100);
            size_c++;
        }
        fin.close();
        size_c--;
        client = new people[size_c];
        fin.open("peopleIn.txt");
        for (int i = 0; i < size_c; i++)
        {
            fin.getline(buff, 100);
            temp = strtok(buff, " ");
            client[i].FIO = new char[strlen(temp) + 1];
            strcpy(client[i].FIO, temp);
            temp = strtok(NULL, " ");
            client[i].bday = new char[strlen(temp) + 1];
            strcpy(client[i].bday, temp);
            temp = strtok(NULL, " ");
            client[i].numPassport = new char[strlen(temp) + 1];
            strcpy(client[i].numPassport, temp);
            //group[i].ID = atoi(strtok(NULL, " "));
            client[i].readID = atoi(strtok(NULL, " "));
            client[i].readed = atoi(strtok(NULL, " "));
            client[i].onHand = atoi(strtok(NULL, " "));
        }
        fin.close();
    }
}



//запись списка клиентов в файл
void WritePeople(people* client, int size_c)
{
    ofstream fout("peopleOut.txt");

    fout << "FIO\tB-Day\t\tNumber passport\tRead ID\tCount readed book\tCount on hand\n";
    for (int i = 0; i < size_c; i++)
    {
        fout << client[i].FIO << "\t" << client[i].bday << "\t";
        fout << client[i].numPassport << "\t" << client[i].readID << "\t";
        fout << client[i].readed << "\t\t\t" << client[i].onHand << "\n";
    }
    fout.close();//закрываем поток
    cout << "File closed, information writed!" << endl;
}


//сортировка клиентов

void SortPeople(people* client, int size_c)
{
    int choiceSortBook;
    cout << "Sort by\n1 - FIO\n2 - Count of readed book\n3 - ID\n4 - Number of passport\n - ";
    cin >> choiceSortBook;
    switch (choiceSortBook)
    {
    case 1:
        for (int i = 0; i < size_c; i++)
        {
            for (int j = 0; j < size_c - 1; j++)
            {
                int z = 0;
                while (client[j].FIO[z] == client[j + 1].FIO[z])
                {
                    z++;
                }
                if (client[j].FIO[z] > client[j + 1].FIO[z])
                {
                    swap(client[j], client[j + 1]);
                }
            }
        }
        break;
    case 2:
        for (int i = 0; i < size_c; i++)
        {
            for (int j = 0; j < size_c - 1; j++)
            {
                if (client[j].readed > client[j + 1].readed)
                {
                    swap(client[j], client[j + 1]);
                }
            }
        }
        break;
    case 3:
        for (int i = 0; i < size_c; i++)
        {
            for (int j = 0; j < size_c - 1; j++)
            {
                if (client[j].readID > client[j + 1].readID)
                {
                    swap(client[j], client[j + 1]);
                }
            }
        }
        break;
    case 4:
        for (int i = 0; i < size_c; i++)
        {
            for (int j = 0; j < size_c - 1; j++)
            {
                int z = 0;
                while (client[j].numPassport[z] == client[j + 1].numPassport[z])
                {
                    z++;
                }
                if (client[j].numPassport[z] > client[j + 1].numPassport[z])
                {
                    swap(client[j], client[j + 1]);
                }
            }
        }
        break;
    }
}



//поиск клиентов
void SearchPeople(people* client, int size_c)
{
    int choiceSearchPeople;
    string searchPeople;
    int count = 0;
    cout << "Search by\n1 - FIO\n2 - ID\n3 - Number of passport\n - ";
    cin >> choiceSearchPeople;
    switch (choiceSearchPeople)
    {
    case 1:
        cout << "Enter FIO to search - "; cin >> searchPeople;
        cin.ignore();

        int buff1;

        for (int i = 0; i < size_c; i++)
        {
            if (client[i].FIO == searchPeople)
            {
                buff1 = i;
                count++;
                break;
            }
        }
        if (count != 0)
        {
            cout << "FIO\tB-Day\t\tNumber passport\tRead ID\tCount readed book\tCount on hand\n";
            cout << client[buff1].FIO << "\t" << client[buff1].bday << "\t";
            cout << client[buff1].numPassport << "\t" << client[buff1].readID << "\t";
            cout << client[buff1].readed << "\t\t\t" << client[buff1].onHand << "\n";

        }
        else if (count == 0)
        {
            cout << "Wrong book name!" << endl;
        }
        break;
    case 2:
        cout << "Enter ID of client to search - "; cin >> searchPeople;
        cin.ignore();

        int buff2;
        for (int i = 0; i < size_c; i++)
        {
            if (client[i].FIO == searchPeople)
            {
                buff2 = i;
                count++;
                break;
            }
        }
        if (count != 0)
        {
            cout << "FIO\tB-Day\t\tNumber passport\tRead ID\tCount readed book\tCount on hand\n";
            cout << client[buff2].FIO << "\t" << client[buff2].bday << "\t";
            cout << client[buff2].numPassport << "\t" << client[buff2].readID << "\t";
            cout << client[buff2].readed << "\t\t\t" << client[buff2].onHand << "\n";

        }
        else if (count == 0)
        {
            cout << "Wrong book name!" << endl;
        }
        break;
    case 3:
        cout << "Enter genre of book to search - "; cin >> searchPeople;
        cin.ignore();

        int buff3;
        for (int i = 0; i < size_c; i++)
        {
            if (client[i].FIO == searchPeople)
            {
                buff3 = i;
                count++;
                break;
            }
        }
        if (count != 0)
        {
            cout << "FIO\tB-Day\t\tNumber passport\tRead ID\tCount readed book\tCount on hand\n";
            cout << client[buff3].FIO << "\t" << client[buff3].bday << "\t";
            cout << client[buff3].numPassport << "\t" << client[buff3].readID << "\t";
            cout << client[buff3].readed << "\t\t\t" << client[buff3].onHand << "\n";

        }
        else if (count == 0)
        {
            cout << "Wrong book name!" << endl;
        }
        break;
    }
}

//редактирование
void EditPeople(people* client, int size_c)
{
    int choiceEdit;
    cout << " E D I T I N G \n1 - Partly\n2 - All row\n - ";
    cin >> choiceEdit;
    switch (choiceEdit)
    {
    case 1:
        int index;
        int row;
        char buff[100];
        cout << "Enter index element to edit - ";
        cin >> index;
        if (index < 0 || index > size_c - 1)
            cout << "Wrong index\n";
        else
        {
            cout << "Enter row to edit\n1 - FIO\n2 - B-Day\n3 - Number of passport\n4 - ID of reader\n 5 - Count of readed book\n6 - Count of book on hand\n - ";
            cin >> row;
            if (row < 1 || row > 6)
                cout << "Wrong row to edit\n";
            else
            {
                switch (row)
                {
                case 1:
                    cin.ignore();
                    cout << "Enter new client FIO - ";
                    cin.getline(buff, 100);
                    delete[] client[index].FIO;
                    client[index].FIO = new char[strlen(buff) + 1];
                    strcpy(client[index].FIO, buff);
                    break;
                case 2:
                    //cin.ignore();
                    cout << "Enter new client birthday - ";
                    cin.getline(buff, 100);
                    delete[] client[index].bday;
                    client[index].bday = new char[strlen(buff) + 1];
                    strcpy(client[index].bday, buff);
                    break;
                case 3:
                    //cin.ignore();
                    cout << "Enter new number of passport - ";
                    cin.getline(buff, 100);
                    delete[] client[index].numPassport;
                    client[index].numPassport = new char[strlen(buff) + 1];
                    strcpy(client[index].numPassport, buff);
                    break;
                case 4:
                    //cin.ignore();
                    cout << "Enter new ID of reader - ";
                    cin >> client[index].readID;
                    break;
                case 5:
                    //cin.ignore();
                    cout << "Enter new count of readed book - ";
                    cin >> client[index].readed;
                    break;
                case 6:
                    //cin.ignore();
                    cout << "Enter new count of book on hand - ";
                    cin >> client[index].onHand;
                    break;

                default: break;
                }
            }
        }
        break;
    case 2:
        int row1;
        cout << "Enter row to edit(0 <-> size_b )\n - ";
        cin >> row1;
        if ((row1) < 0 || (row1) > size_c)
            cout << "Wrong row to edit\n";
        else
        {
            cin.ignore();
            cout << "Enter new client FIO - ";
            cin.getline(buff, 100);
            delete[] client[row1].FIO;
            client[row1].FIO = new char[strlen(buff) + 1];
            strcpy(client[row1].FIO, buff);

            //cin.ignore();
            cout << "Enter new client birthday - ";
            cin.getline(buff, 100);
            delete[] client[row1].bday;
            client[row1].bday = new char[strlen(buff) + 1];
            strcpy(client[row1].bday, buff);

            cin.ignore();
            cout << "Enter new client number of passport - ";
            cin.getline(buff, 100);
            delete[] client[row1].numPassport;
            client[row1].numPassport = new char[strlen(buff) + 1];
            strcpy(client[row1].numPassport, buff);

            //cin.ignore();
            cout << "Enter new ID of reader - ";
            cin >> client[row1].readID;

            //cin.ignore();
            cout << "Enter new count of readed book - ";
            cin >> client[row1].readed;

            //cin.ignore();
            cout << "Enter new count of book on hand - ";
            cin >> client[row1].onHand;


        }
        break;
    default: break;
    }
}







//добавление книг
void AddBook(book*& lib, int& size_b)//функция добавления книг
{
    char buff[100];//временная строка
    book* temp = new book[size_b + 1];//создание массива размерностью на единицу больше от того что было изначально
    for (int i = 0; i < size_b; i++)//цыкл для копирование информации из предыдущего массива в только что созданый
        temp[i] = lib[i];
    delete[] lib;//удаление старого массива
    lib = temp;//копирование из временного массива в постоянный
    cout << "Enter data - "; cin >> lib[size_b].Data;
    cin.ignore();
    cout << "Enter name - "; cin.getline(buff, 100);
    lib[size_b].name = new char[strlen(buff) + 1];
    strcpy(lib[size_b].name, buff);
    cout << "Enter author - "; cin.getline(buff, 100);
    lib[size_b].author = new char[strlen(buff) + 1];
    strcpy(lib[size_b].author, buff);
    cout << "Enter genre - "; cin.getline(buff, 100);
    lib[size_b].genre = new char[strlen(buff) + 1];
    strcpy(lib[size_b].genre, buff);
    cout << "Enter cost - "; cin >> lib[size_b].cost;
    cout << "Enter ID - "; cin >> lib[size_b].ID;

    size_b++;
}


//чтение списка книг из файла
void ReadBook(book*& lib, int& size_b)
{
    ifstream fin("bookIn.txt");
    if (!fin)
        cout << "Wrong file!" << endl;
    else
    {
        char* temp;
        char buff[1000];//времення строка
        while (fin)//пока не дошли до конца файла
        {
            fin.getline(buff, 1000);//вычитываем строку
            size_b++;//изменяем размер на 1
        }
        size_b--;
        fin.close();//закрываем поток
        lib = new book[size_b];//создаем новый массив размером size
        fin.open("bookIn.txt");//открываем поток
        for (int i = 0; i < size_b; i++)//пока размер больше 0
        {
            fin.getline(buff, 1000);//вычитываем строку
            temp = strtok(buff, " ");//все до запятой записываем в temp
            lib[i].name = new char[strlen(temp) + 1];//выделяем память под имя
            strcpy(lib[i].name, temp);//копируем имя в эту память
            temp = strtok(NULL, " ");
            lib[i].author = new char[strlen(temp) + 1];
            strcpy(lib[i].author, temp);
            temp = strtok(NULL, " ");
            lib[i].genre = new char[strlen(temp) + 1];
            strcpy(lib[i].genre, temp);
            lib[i].Data = atoi(strtok(NULL, " "));
            lib[i].cost = atoi(strtok(NULL, " "));
            lib[i].ID = atoi(strtok(NULL, " "));
            lib[i].user_ID = atoi(strtok(NULL, " "));
            lib[i].out = atoi(strtok(NULL, " "));

        }
        fin.close();
    }
    cout << "File readed, all good:)" << endl;

}



//удаление книг из списка
void DeleteBook(book*& lib, int& size_b)
{
    book* temp = new book[size_b - 1];

    int delbookIndex;
    cout << "Enter index of book to delete - "; cin >> delbookIndex;

    for (int i = 0; i < size_b; i++)
    {
        if (i < delbookIndex)
            temp[i] = lib[i];
        else if (i == delbookIndex)
            continue;
        else if (i > delbookIndex)
            temp[i - 1] = lib[i];
    }
    delete[] lib;
    lib = temp;
    size_b--;

}






//вывод на экран списка книг
void ShowBook(book*& lib, int& size_b)
{
    cout << "#\tAuthor\t\tName\t\tData\tGenre\tCost\tID\tUser_ID\tData_out\tCount using\n";
    for (int i = 0; i < size_b; i++)
    {
        cout << i << "\t" << lib[i].author << "\t\t" << lib[i].name << "\t\t";
        cout << lib[i].Data << "\t" << lib[i].genre << "\t";
        cout << lib[i].cost << "\t" << lib[i].ID << "\t";
        cout << lib[i].user_ID << "\t" << lib[i].out << "\t" << lib[i].countUsed << "\n";
    }
}


//редактирование списка книг
void EditBook(book* lib, int size_b)
{
    int choiceEdit;
    cout << " E D I T I N G \n1 - Partly\n2 - All row\n - ";
    cin >> choiceEdit;
    switch (choiceEdit)
    {
    case 1:

        int index;
        int row;
        char buff[100];
        cout << "Enter index element to edit - ";
        cin >> index;
        if (index < 0 || index > size_b - 1)
            cout << "Wrong index\n";
        else
        {
            cout << "Enter row to edit\n1-Author\n2-Name\n3 - Date\n4 - Genre\n 5 - Cost\n6 - ID\n - ";
            cin >> row;
            if (row < 1 || row > 6)
                cout << "Wrong row to edit\n";
            else
            {
                switch (row)
                {
                case 1:
                    cin.ignore();
                    cout << "Enter new author name - ";
                    cin.getline(buff, 100);
                    delete[] lib[index].author;
                    lib[index].author = new char[strlen(buff) + 1];
                    strcpy(lib[index].author, buff);
                    break;
                case 2:
                    //cin.ignore();
                    cout << "Enter new book name - ";
                    cin.getline(buff, 100);
                    delete[] lib[index].name;
                    lib[index].name = new char[strlen(buff) + 1];
                    strcpy(lib[index].name, buff);
                    break;
                case 3:
                    //cin.ignore();
                    cout << "Enter new date - ";
                    cin >> lib[index].Data;
                    break;
                case 4:
                    //cin.ignore();
                    cout << "Enter new genre - ";
                    cin.getline(buff, 100);
                    delete[] lib[index].genre;
                    lib[index].genre = new char[strlen(buff) + 1];
                    break;
                case 5:
                    //cin.ignore();
                    cout << "Enter new cost - ";
                    cin >> lib[index].cost;
                    break;
                case 6:
                    //cin.ignore();
                    cout << "Enter new ID - ";
                    cin >> lib[index].ID;
                    break;

                default:
                    break;
                }
            }
        }
        break;

    case 2:
        int row1;
        cout << "Enter row to edit(0 <-> size_b )\n - ";
        cin >> row1;
        if ((row1) < 0 || (row1) > size_b)
            cout << "Wrong row to edit\n";
        else
        {
            cin.ignore();
            cout << "Enter new author name - ";
            cin.getline(buff, 100);
            delete[] lib[row1].author;
            lib[row1].author = new char[strlen(buff) + 1];
            strcpy(lib[row1].author, buff);

            //cin.ignore();
            cout << "Enter new book name - ";
            cin.getline(buff, 100);
            delete[] lib[row1].name;
            lib[row1].name = new char[strlen(buff) + 1];
            strcpy(lib[row1].name, buff);

            //cin.ignore();
            cout << "Enter new date - ";
            cin >> lib[row1].Data;

            cin.ignore();
            cout << "Enter new book genre - ";
            cin.getline(buff, 100);
            delete[] lib[row1].genre;
            lib[row1].genre = new char[strlen(buff) + 1];
            strcpy(lib[row1].genre, buff);

            //cin.ignore();
            cout << "Enter new cost - ";
            cin >> lib[row1].cost;

            //cin.ignore();
            cout << "Enter new ID - ";
            cin >> lib[row1].ID;

            lib[row1].user_ID = 0;
            lib[row1].out = 0;
        }
        break;
    }
}




//запись списка книг в файл
void WriteBook(book*& lib, int size_b)
{
    ofstream fout("bookOut.txt");

    fout << "Author\tName\tData\tGenre\tCost ID\tUser_ID\tData_out\n";

    for (int i = 0; i < size_b; i++)
    {
        fout << lib[i].author << " " << lib[i].name << " ";
        fout << lib[i].Data << " " << lib[i].genre << " ";
        fout << lib[i].cost << " " << lib[i].ID << " ";
        fout << lib[i].user_ID << " " << lib[i].out << "\n";
    }
    fout.close();//закрываем поток
    cout << "File closed, information writed!" << endl;
}




//сортировка списка книг
void SortBook(book* lib, int size_b)
{
    int choiceSortBook;
    cout << "Sort by\n1 - Name\n2 - Author\n3 - Genre\n - ";
    cin >> choiceSortBook;
    switch (choiceSortBook)
    {
    case 1:
        for (int i = 0; i < size_b; i++)
        {
            for (int j = 0; j < size_b - 1; j++)
            {
                int z = 0;
                while (lib[j].name[z] == lib[j + 1].name[z])
                {
                    z++;
                }
                if (lib[j].name[z] > lib[j + 1].name[z])
                {
                    swap(lib[j], lib[j + 1]);
                }
            }
        }
        break;
    case 2:
        for (int i = 0; i < size_b; i++)
        {
            for (int j = 0; j < size_b - 1; j++)
            {
                int z = 0;
                while (lib[j].author[z] == lib[j + 1].author[z])
                {
                    z++;
                }
                if (lib[j].author[z] > lib[j + 1].author[z])
                {
                    swap(lib[j], lib[j + 1]);
                }
            }
        }
        break;
    case 3:
        for (int i = 0; i < size_b; i++)
        {
            for (int j = 0; j < size_b - 1; j++)
            {
                int z = 0;
                while (lib[j].genre[z] == lib[j + 1].genre[z])
                {
                    z++;
                }
                if (lib[j].genre[z] > lib[j + 1].genre[z])
                {
                    swap(lib[j], lib[j + 1]);
                }
            }
        }
        break;
    default: break;
    }

}


//поиск книг в списке
void SearchBook(book* lib, int size_b)
{
    int choiceSearchBook;
    string searchBook;
    int count = 0;
    cout << "Search by\n1 - Author\n2 - Name\n3 - Genre\n - ";
    cin >> choiceSearchBook;
    switch (choiceSearchBook)
    {
    case 1:
        cout << "Enter author of book to search - "; cin >> searchBook;
        cin.ignore();

        int buff1;

        for (int i = 0; i < size_b; i++)
        {
            if (lib[i].author == searchBook)
            {
                buff1 = i;
                count++;
                break;
            }
        }
        if (count != 0)
        {
            cout << "Author\tName\tData\tGenre\tCost\tID\tUser_ID\tData_out\n";
            cout << lib[buff1].author << "\t" << lib[buff1].name << "\t";
            cout << lib[buff1].Data << "\t" << lib[buff1].genre << "\t";
            cout << lib[buff1].cost << "\t" << lib[buff1].ID << "\t";
            cout << lib[buff1].user_ID << "\t" << lib[buff1].out << "\n";
        }
        else if (count == 0)
        {
            cout << "Wrong book name!" << endl;
        }
        break;
    case 2:
        cout << "Enter name of book to search - "; cin >> searchBook;
        cin.ignore();

        int buff2;
        for (int i = 0; i < size_b; i++)
        {
            if (lib[i].name == searchBook)
            {
                buff2 = i;
                count++;
                break;
            }
        }
        if (count != 0)
        {
            cout << "Author\tName\tData\tGenre\tCost\tID\tUser_ID\tData_out\n";
            cout << lib[buff2].author << "\t" << lib[buff2].name << "\t";
            cout << lib[buff2].Data << "\t" << lib[buff2].genre << "\t";
            cout << lib[buff2].cost << "\t" << lib[buff2].ID << "\t";
            cout << lib[buff2].user_ID << "\t" << lib[buff2].out << "\n";
        }
        else if (count == 0)
        {
            cout << "Wrong book name!" << endl;
        }
        break;
    case 3:
        cout << "Enter genre of book to search - "; cin >> searchBook;
        cin.ignore();

        int buff3;
        for (int i = 0; i < size_b; i++)
        {
            if (lib[i].genre == searchBook)
            {
                buff3 = i;
                count++;
                break;
            }
        }
        if (count != 0)
        {
            cout << "Author\tName\tData\tGenre\tCost\tID\tUser_ID\tData_out\n";
            cout << lib[buff3].author << "\t" << lib[buff3].name << "\t";
            cout << lib[buff3].Data << "\t" << lib[buff3].genre << "\t";
            cout << lib[buff3].cost << "\t" << lib[buff3].ID << "\t";
            cout << lib[buff3].user_ID << "\t" << lib[buff3].out << "\n";
        }
        else if (count == 0)
        {
            cout << "Wrong book name!" << endl;
        }
        break;
    }
}



//вывод информации о книгах которые находятся на руках
void InfoBook(book* lib, int size_b)
{
    cout << "#\tAuthor\t\tName\t\tData\tGenre\tCost\tID\tUser_ID\tData_out\n";

    for (int i = 0; i < size_b; i++)
    {
        if (lib[i].user_ID != 0)
        {
            cout << i << "\t" << lib[i].author << "\t\t" << lib[i].name << "\t\t";
            cout << lib[i].Data << "\t" << lib[i].genre << "\t";
            cout << lib[i].cost << "\t" << lib[i].ID << "\t";
            cout << lib[i].user_ID << "\t" << lib[i].out << "\n";
        }
    }
}



//функция выдачи книг на руки
void BookOut(book* lib, people* client, int size_b, int size_c/*, int book_index, int client_index*/)
{
    int book_index, client_index;

    ShowPeople(client, size_c);
    do
    {
        cout << "Enter client index to give book out - "; cin >> client_index;
    } while (client_index<0 || client_index > size_c - 1);
    ShowBook(lib, size_b);
    do
    {
        cout << "Enter index of book to give out - "; cin >> book_index;
    } while (book_index<0 || book_index>size_b - 1);
    if (lib[book_index].user_ID != 0)
        cout << "Book is busy" << endl;
    else
    {
        lib[book_index].user_ID = client[client_index].readID;
        int* temp = new int[client[client_index].onHand + 1];
        for (int i = 0; i < client[client_index].onHand; i++)
            temp[i] = client[client_index].lib[i];
        //delete[] client[client_index].lib;
        client[client_index].lib = temp;
        client[client_index].lib[client[client_index].onHand] = lib[book_index].ID;
        client[client_index].onHand++;
        client[client_index].readed++;
        lib[book_index].countUsed++;
    }
}


//функция возврата книг
void BookIn(book* lib, people* client, int size_b, int size_c/*, int book_index, int client_index*/)
{
    int book_index, client_index;

    cout << "#\tAuthor\t\tName\t\tData\tGenre\tCost\tID\tUser_ID\tData_out\n";

    for (int i = 0; i < size_b; i++)
    {
        if (lib[i].user_ID != 0)
        {
            cout << i << "\t" << lib[i].author << "\t\t" << lib[i].name << "\t\t";
            cout << lib[i].Data << "\t" << lib[i].genre << "\t";
            cout << lib[i].cost << "\t" << lib[i].ID << "\t";
            cout << lib[i].user_ID << "\t" << lib[i].out << "\n";
        }
    }
    do
    {
        cout << "Enter client index to give book back - "; cin >> client_index;
    } while (client_index < 0 || client_index > size_c - 1);
    do
    {
        cout << "Enter index of book to give back - "; cin >> book_index;
    } while (book_index < 0 || book_index > size_b - 1);
    
    if (lib[book_index].user_ID == 0)
        cout << "Sorry, you didn`t take this book!" << endl;
    else
    {
        lib[book_index].user_ID = 0;
        client[client_index].lib = 0;
        client[book_index].onHand--;
    }
}







void ActiveReader(people* client, int size_c)
{
    cout << "#\tFIO\tB-Day\t\tNumber passport\tRead ID\tCount readed book\tCount on hand\n";
    for (int i = 0; i < size_c; i++)
    {
        if (client[i].readed > 3)
        {
            cout << i << "\t" << client[i].FIO << "\t" << client[i].bday << "\t";
            cout << client[i].numPassport << "\t" << client[i].readID << "\t";
            cout << client[i].readed << "\t\t\t" << client[i].onHand << "\n";
        }
        else
            cout << "Activnost ne ochen!" << endl;
    }
}


void PopularBook(book* lib, int size_b)
{
    cout << "#\tAuthor\t\tName\t\tData\tGenre\tCost\tID\tUser_ID\tData_out\n";

    for (int i = 0; i < size_b; i++)
    {
        if (lib[i].countUsed > 3)
        {
            cout << i << "\t" << lib[i].author << "\t\t" << lib[i].name << "\t\t";
            cout << lib[i].Data << "\t" << lib[i].genre << "\t";
            cout << lib[i].cost << "\t" << lib[i].ID << "\t";
            cout << lib[i].user_ID << "\t" << lib[i].out << "\t" << lib[i].countUsed << "\n";
        }
    }
}

#pragma once

struct people
{
    char* FIO;  //ФИО
    char* bday;   //Год рождения
    char* numPassport;    //номер паспорта
    int readID;    //номер читателя
    int readed;    //кол-во прочитаных
    int onHand;    //кол-во книг на руках

    int* lib;
};

struct book
{
    int Data;       //дата издания
    char* name;     //название
    char* author;   //автор
    char* genre;    //жанр
    int cost;       //цена
    int ID;         //номер
    int user_ID = 0;    //ID читателя
    int out = 0;        //дата выдачи
    int in = 0;         //дата возврата
    int countUsed = 0;  //счётчик использования книги
};


void Add(people*& client, int& size_c, book*& lib, int& size_b);

void Delete(people*& client, int& size_c, book*& lib, int& size_b);

void Read(people*& client, int& size_c, book*& lib, int& size_b);

void Edit(people*& client, int& size_c, book*& lib, int& size_b);

void Sort(people*& client, int& size_c, book*& lib, int& size_b);

void Write(people*& client, int& size_c, book*& lib, int& size_b);

void Show(people*& client, int& size_c, book*& lib, int& size_b);

void Search(people*& client, int& size_c, book*& lib, int& size_b);

void AddPeople(people*& client, int& size_c);

void ShowPeople(people*& client, int& size_c);

void DeletePeople(people*& client, int& size_c);

void ReadPeople(people*& client, int& size_c);

void WritePeople(people* client, int size_c);

void SortPeople(people* client, int size_c);

void SearchPeople(people* client, int size_c);

void EditPeople(people* client, int size_c);

void AddBook(book*& lib, int& size_b);

void ReadBook(book*& lib, int& size_b);

void DeleteBook(book*& lib, int& size_b);

void ShowBook(book*& lib, int& size_b);

void EditBook(book* lib, int size_b);

void WriteBook(book*& lib, int size_b);

void SortBook(book* lib, int size_b);

void SearchBook(book* lib, int size_b);

void BookOut(book* lib, people* client, int size_b, int size_c);

void BookIn(book* lib, people* client, int size_b, int size_c);

void InfoBook(book* lib, int size_b);

void ActiveReader(people* client,int size_c);

void PopularBook(book* lib, int size_b);
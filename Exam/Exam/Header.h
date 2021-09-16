#pragma once

struct people
{
    char* FIO;  //���
    char* bday;   //��� ��������
    char* numPassport;    //����� ��������
    int readID;    //����� ��������
    int readed;    //���-�� ����������
    int onHand;    //���-�� ���� �� �����

    int* lib;
};

struct book
{
    int Data;       //���� �������
    char* name;     //��������
    char* author;   //�����
    char* genre;    //����
    int cost;       //����
    int ID;         //�����
    int user_ID = 0;    //ID ��������
    int out = 0;        //���� ������
    int in = 0;         //���� ��������
    int countUsed = 0;  //������� ������������� �����
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
#include <iostream>
#include <vector>

using namespace std;

class Book
{
public:
    string Title,Author;
    bool status;
    Book(string T, string A, bool S) : Title(T), Author(A), status(S) {}
    void showInfo()
    {
        cout<<"Book Title: "<<Title<<"\nAuthor: "<<Author<<"\nStatus: ";
        if (status)
        {
            cout<<"Available.\n\n";
        }
        else
        {
            cout<<"Borrowed.\n\n";
        }
    }
};
class Member
{
protected:
    string Name;
    inline static vector<Book> Borrowed;
public:
    Member(string N): Name(N){}
    void borrowBook(Book& pbook)
    {
        if(pbook.status)
        {
            pbook.status=false;
            Borrowed.push_back(pbook);
            cout<<Name<<" Borrowed "<<pbook.Title<<" successfully.\n\n";
        }
        else
        {
            cout<<pbook.Title<<" is already borrowed!\n\n";
        }
    }
    void returnBook(Book& pbook)
    {
        int pos=-1;
        for (int i=0; i<Borrowed.size(); i++)
        {
            if (Borrowed[i].Title == pbook.Title)
            {
                pos=i;
            }
        }
        if (pos != -1)
        {
            pbook.status=true;
            Borrowed.erase(Borrowed.begin() + pos);
        }
        else
        {
            cout<<Name<<" Didn't Borrow that book.\n";
        }
    }
};

class Library : public Member
{
    vector<Book> Books;
    vector<Member> Members;
public:
    Library() : Member("Lib"){

    }
    void addBook(Book& pbook)
    {
        Books.push_back(pbook);
        cout<<"Library added book: "<<pbook.Title<<" successfully \n\n";
    }

    void addMember(Member& pmember)
    {
        Members.push_back(pmember);
        cout<<"Library added a member successfully \n\n";
    }

    void searchBook(string BookTitle)
    {
        bool Found;
        for (Book book : Books)
        {
            if (book.Title == BookTitle){
                cout<<"Book found: \n";
                book.showInfo();
                Found=true;
            }
        }
        if (Found == false){
            cout<<"Couldn't find "<<BookTitle<<"\n\n";
        }
}
    void showAllBooks(){
        for (Book book : Books){
            book.showInfo();
        }
    }
};

int main()
{
    Book book1("The Railway Children","don't Know",true);
    Book book2("Oliver Twist","Charles Dickens",true);

    book1.showInfo();
    book2.showInfo();

    Member member1("Ahmed");

    member1.borrowBook(book1);
    member1.borrowBook(book2);
    member1.returnBook(book1);
    member1.returnBook(book2);

    Library AlexLibrary;

    AlexLibrary.addBook(book1);
    AlexLibrary.addBook(book2);

    AlexLibrary.addMember(member1);

    AlexLibrary.searchBook("Oliver Twist");
    AlexLibrary.searchBook("OliverTwist");

    AlexLibrary.showAllBooks();

    return 0;
}

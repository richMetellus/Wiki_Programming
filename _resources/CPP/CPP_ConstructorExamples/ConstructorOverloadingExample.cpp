// C++ program to demonstrate constructor overloading
#include <iostream>
#include <string>
#include <sstream>    // header file for stringstream for int to str conversion

// forward class declaration
class Book;

typedef struct
{
    int month;
    int day;
    int year;
} Date;

std::string arrayToString (std::string* arrayptr, int size)
{
    std::string arrStr;
    for (int i = 0; i < size; i++)
    {
        arrStr.append(*(arrayptr + i) + " ");
    }
    
    return arrStr;
}

class Person
{

private:
    std::string name;
    int age;
    Date dateOfBirth;
    
    // here I needed Book& in order to have a class(Object) as a data member within another class
    // otherwise I will have a "error: field ‘favoriteBook’ has incomplete type ‘Book’"
    // and because the class Book is defined later after Person, the compiler needed
    // a forward class declaration of Book. https://www.learncpp.com/cpp-tutorial/classes-and-class-members/
    // Having favoriteBook as data member thus will require every Constructor in Person to
    // initialize favoriteBook otherwise this error
        /*
            main.cpp: In constructor ‘Person::Person()’:
        main.cpp:50:5: error: uninitialized reference member in ‘class Book&’ [-fpermissive]
           50 |     Person()
              |     ^~~~~~
        main.cpp:45:11: note: ‘Book& Person::favoriteBook’ should be initialized
           45 |     Book& favoriteBook;
              |           ^~~~~~~~~~~~
        main.cpp: In constructor ‘Person::Person(int)’:
        main.cpp:56:5: error: uninitialized reference member in ‘class Book&’ [-fpermissive]
           56 |     Person(int a)
              |     ^~~~~~
        main.cpp:45:11: note: ‘Book& Person::favoriteBook’ should be initialized
           45 |     Book& favoriteBook;
              |           ^~~~~~~~~~~~
        */      
    Book& _favoriteBook;


public:
    
    // Because of _favoriteBook I cannot have a no-arg constructor.
    // this will not compile:
        // 1. Constructor with no arguments
        // Person()
        // {
        //     age = 20;
        // }
    // every Constructor of Person **MUST** have _favoriteBook initialized in order to compile
    
    // this will not compile
    // Person(Book& favoriteBook)
    // {
    //     // this->age = 20;
    //     // Person::age = 20; //  compiler will not complain
        
    //     // this->_favoriteBook = (favoriteBook); // compiler will complain can't initialize like this
    //     // this->_favoriteBook = favoriteBook; // can't initialize it like this either
    // }
    
    // this is also legal. 
    // Person(Book& favoriteBook):
    // _favoriteBook(favoriteBook)
    // {
    //     this->age = 20;
    // }
    
    // this is also legal. it will compile. Although in some instance
    // if using a .h file, I use to see the compiler required to initialize the data
    // members in the order they were declared.
    // Person(Book& favoriteBook):
    // _favoriteBook(favoriteBook),
    // age(20)
    // {
    // }
    
    Person(Book& favoriteBook):
    age(20),
    _favoriteBook(favoriteBook)
    {
    }

    // 2. Constructor with an argument
    Person(int a, Book& favoriteBook):
    age(a),
    _favoriteBook(favoriteBook)
    {
    }
    
    Person(std::string name, Date& dob, Book& favoriteBook):
    name(name),
    dateOfBirth(dob),
    _favoriteBook(favoriteBook)
    {
    }
    
    ~Person(){}
    
    std::string getName()
    {
        return name;
    }
    
    int getAge()
    {
        return age;
    }

    std::string toString()
    {
        std::ostringstream stream; // this is needed here to convert int to string
        stream << "Name: " << name << "\n\t"
               "age: " << getAge() << "\n\t" <<
               "dob: " << dateOfBirth.month << "/" << dateOfBirth.day << "/" << dateOfBirth.year << "\n\t";
            //   " favoriteBook: " << _favoriteBook.toString(); // this will cause some error.
              
                          /*
                          main.cpp:136:36: error: invalid use of incomplete type ‘class Book’
                              136 |               " favoriteBook: " << _favoriteBook.toString(); // this will cause some error.
                                  |                                    ^~~~~~~~~~~~~
                          */
                        // I will have to split the file between .h and a .cpp file and I don't want to do that yet.
                        // https://techoverflow.net/2018/01/21/how-to-fix-gcc-error-invalid-use-of-incomplete-type-class/
        
        return stream.str();   
    }

};

class Book{

private:
    static const int arrSize = 3;   // the const is needed.  error: ISO C++ forbids in-class initialization of non-const static member ‘Book::arrSize’
    std::string title;
    std::string authors[arrSize];
    
    // I needed this pointer to avoid incompatible type when initializing authors in the constructor
    // Book(std::string title, std::string* authors)
    std::string* authors_ptr = authors;
                                    

public:
    
    // [BookConstructorOverloadingSectionStart]
    Book()
    {
        
    }
    
    Book(std::string title)
    {
        this->title = title;
    }
    
    Book(std::string title, std::string* authors)
    {
        this->title = title;
        
        // the next statement will not compile. and exibit this error:
            // main.cpp:130:25: error: incompatible types in assignment of ‘std::string*’ {aka ‘std::__cxx11::basic_string*’} to ‘std::string [3]’ {aka ‘std::__cxx11::basic_string [3]’}
        // this->authors = authors; 
        
        this->authors_ptr = authors; // this will compile
    }
    
    // [BookConstructorOverloadingSectionEnd]

    ~Book(){}

    std::string getTitle()
    {
        return title;
    }
    
    std::string* getAuthor()
    {
        return authors;
    }
    
    std::string toString()
    {
        return "title: " + title + "\n\t"
               "author: " + arrayToString(authors_ptr, arrSize);
    }

    
};

int main()
{
    std::string fastSlowAuthor[] = {"Daniel Kahneman", "", ""};
    //uncoment the below line and comment out the above line to see some weird output
    /*
            Book to String:
                    title: Thinking, Fast and Slow
                    author: Daniel Kahneman nd Slow Thinking, Fast and Slow 
    */
    // std::string fastSlowAuthor[] = {"Daniel Kahneman"};
    
    Date obamaDOB = {4, 8, 1961};
    Book obamaRecomendedBook; // Possible because of default constructor
    obamaRecomendedBook = Book("Thinking, Fast and Slow", fastSlowAuthor);
    
    std::cout << "Book to String:\n\t" << obamaRecomendedBook.toString() << std::endl;
    
    // Person obama; // illegal, Person does not have default constructor Person::Person()
    
    // legal
    Person obama = Person("Barrack Obama", obamaDOB, obamaRecomendedBook );

    std::cout << "Person 1 Info: \n\t " << obama.toString() << std::endl;
    return 0;
}

/* Console Output
[ConsoleOutputSectionStart]
Book to String:
        title: Thinking, Fast and Slow
        author: Daniel Kahneman   
Person 1 Info: 
         Name: Barrack Obama
        age: 458951824
        dob: 4/8/1961



...Program finished with exit code 0
Press ENTER to exit console.

[ConsoleOutputSectionEnd]

*/
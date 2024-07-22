//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************

class student
{
    int rollno;
    string name;
    int p_marks, c_marks, m_marks, e_marks, cs_marks;
    float per;
    char grade;
    void calculate();    // function to calculate grade
public:
    void getdata();    // function to accept data from user
    void showdata();    // function to show data on screen
    void show_tabular();
    int retrollno();
}; // class ends here

void student::calculate()
{
    per = (p_marks + c_marks + m_marks + e_marks + cs_marks) / 5.0;
    if (per >= 60)
        grade = 'A';
    else if (per >= 50)
        grade = 'B';
    else if (per >= 33)
        grade = 'C';
    else
        grade = 'F';
}

void student::getdata()
{
    cout << "\nEnter The roll number of student: ";
    cin >> rollno;
    cout << "\nEnter The Name of student: ";
    cin.ignore(); // clear the input buffer
    getline(cin, name);
    cout << "\nEnter The marks in physics out of 100: ";
    cin >> p_marks;
    cout << "\nEnter The marks in chemistry out of 100: ";
    cin >> c_marks;
    cout << "\nEnter The marks in maths out of 100: ";
    cin >> m_marks;
    cout << "\nEnter The marks in english out of 100: ";
    cin >> e_marks;
    cout << "\nEnter The marks in computer science out of 100: ";
    cin >> cs_marks;
    calculate();
}

void student::showdata()
{
    cout << "\nRoll number of student: " << rollno;
    cout << "\nName of student: " << name;
    cout << "\nMarks in Physics: " << p_marks;
    cout << "\nMarks in Chemistry: " << c_marks;
    cout << "\nMarks in Maths: " << m_marks;
    cout << "\nMarks in English: " << e_marks;
    cout << "\nMarks in Computer Science: " << cs_marks;
    cout << "\nPercentage of student is: " << per;
    cout << "\nGrade of student is: " << grade;
}

void student::show_tabular()
{
    cout << rollno << setw(6) << " " << name << setw(10) << p_marks << setw(4) << c_marks << setw(4) << m_marks << setw(4) << e_marks << setw(4) << cs_marks << setw(6) << per << setw(6) << " " << grade << endl;
}

int student::retrollno()
{
    return rollno;
}

//***************************************************************
//    	function declaration
//****************************************************************

void write_student();    // write the record in binary file
void display_all();        // read all records from binary file
void display_sp(int);    // accept rollno and read record from binary file
void modify_student(int);    // accept rollno and update record of binary file
void delete_student(int);    // accept rollno and delete selected records from binary file
void class_result();    // display all records in tabular format from binary file
void result();    // display result menu
void intro();    // display welcome screen
void entry_menu();    // display entry menu on screen

//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************

int main()
{
    char ch;
    cout.setf(ios::fixed | ios::showpoint);
    cout << setprecision(2); // program outputs decimal number to two decimal places
    // clrscr(); // Remove this line; it's specific to some environments and is not standard C++.
    intro();
    do
    {
        // clrscr(); // Remove this line; it's specific to some environments and is not standard C++.
        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t01. RESULT MENU";
        cout << "\n\n\t02. ENTRY/EDIT MENU";
        cout << "\n\n\t03. EXIT";
        cout << "\n\n\tPlease Select Your Option (1-3): ";
        cin >> ch;
        // clrscr(); // Remove this line; it's specific to some environments and is not standard C++.
        switch (ch)
        {
            case '1': result();
                break;
            case '2': entry_menu();
                break;
            case '3':
                break;
            default: cout << "\a";
        }
    } while (ch != '3');
    return 0;
}

//***************************************************************
//    	function to write in file
//****************************************************************

void write_student()
{
    student st;
    ofstream outFile;
    outFile.open("student.dat", ios::binary | ios::app);
    st.getdata();
    outFile.write((char *) &st, sizeof(student));
    outFile.close();
    cout << "\n\nStudent record has been created ";
    cin.ignore();
    // getch(); // Remove this line; it's specific to some environments and is not standard C++.
}

//***************************************************************
//    	function to read all records from file
//****************************************************************

void display_all()
{
    student st;
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be opened! Press any Key...";
        // getch(); // Remove this line; it's specific to some environments and is not standard C++.
        return;
    }
    cout << "\n\n\n\t\tDISPLAY ALL RECORDS!!!\n\n";
    while (inFile.read((char *) &st, sizeof(student)))
    {
        st.showdata();
        cout << "\n\n====================================\n";
    }
    inFile.close();

    // getch(); // Remove this line; it's specific to some environments and is not standard C++.
}

//***************************************************************
//    	function to read specific record from file
//****************************************************************

void display_sp(int n)
{
    student st;
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be opened! Press any Key...";
        // getch(); // Remove this line; it's specific to some environments and is not standard C++.
        return;
    }
    int flag = 0;
    while (inFile.read((char *) &st, sizeof(student)))
    {
        if (st.retrollno() == n)
        {
            st.showdata();
            flag = 1;
        }
    }
    inFile.close();
    if (flag == 0)
        cout << "\n\nRecord does not exist";

    // getch(); // Remove this line; it's specific to some environments and is not standard C++.
}

//***************************************************************
//    	function to modify record of file
//****************************************************************

void modify_student(int n)
{
    int found = 0;
    student st;
    fstream File;
    File.open("student.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be opened! Press any Key...";
        // getch(); // Remove this line; it's specific to some environments and is not standard C++.
        return;
    }

    while (File.read((char *) &st, sizeof(student)) && found == 0)
    {
        if (st.retrollno() == n)
        {
            st.showdata();
            cout << "\n\nPlease Enter The New Details of student" << endl;
            st.getdata();
            int pos = (-1) * sizeof(st);
            File.seekp(pos, ios::cur);
            File.write((char *) &st, sizeof(student));
            cout << "\n\n\tRecord Updated";
            found = 1;
        }
    }
    File.close();
    if (found == 0)
        cout << "\n\n Record Not Found ";
    // getch(); // Remove this line; it's specific to some environments and is not standard C++.
}

//***************************************************************
//    	function to delete record of file
//****************************************************************

void delete_student(int n)
{
    student st;
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be opened! Press any Key...";
        // getch(); // Remove this line; it's specific to some environments and is not standard C++.
        return;
    }
    ofstream outFile;
    outFile.open("Temp.dat", ios::out);
    inFile.seekg(0, ios::beg);
    while (inFile.read((char *) &st, sizeof(student)))
    {
        if (st.retrollno() != n)
        {
            outFile.write((char *) &st, sizeof(student));
        }
    }
    outFile.close();
    inFile.close();
    remove("student.dat");
    rename("Temp.dat", "student.dat");
    cout << "\n\n\tRecord Deleted ..";

    // getch(); // Remove this line; it's specific to some environments and is not standard C++.
}

//***************************************************************
//    	function to display all students' grade report
//****************************************************************

void class_result()
{
    student st;
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be opened! Press any Key...";
        // getch(); // Remove this line; it's specific to some environments and is not standard C++.
        return;
    }
    cout << "\n\n\n\t\tCLASS RESULT!!!\n\n";
    cout << "\n\nRoll No" << setw(6) << "Name" << setw(10) << "Physics" << setw(6) << "Chemistry" << setw(6) << "Maths" << setw(6) << "English" << setw(6) << "CS" << setw(8) << "Percentage" << setw(6) << "Grade" << endl;
    cout << "=================================================================================================\n";
    while (inFile.read((char *) &st, sizeof(student)))
    {
        st.show_tabular();
    }
    inFile.close();
    // getch(); // Remove this line; it's specific to some environments and is not standard C++.
}

//***************************************************************
//    	function to display result menu
//****************************************************************

void result()
{
    char ch;
    cout << "\n\n\n\tRESULT MENU";
    cout << "\n\n\t01. Class Result";
    cout << "\n\n\t02. Specific Student Result";
    cout << "\n\n\t03. Back to Main Menu";
    cout << "\n\n\tPlease Select Your Option (1-3): ";
    cin >> ch;
    switch (ch)
    {
        case '1': class_result();
            break;
        case '2':
            int num;
            cout << "\n\n\tEnter Roll Number: ";
            cin >> num;
            display_sp(num);
            break;
        case '3':
            break;
        default: cout << "\a";
    }
}

//***************************************************************
//    	function to display introduction screen
//****************************************************************

void intro()
{
    // clrscr(); // Remove this line; it's specific to some environments and is not standard C++.
    cout << "\n\n\n";
    cout << "\t\t\t\tStudent Record System";
    cout << "\n\n\t\t\t\tMade By: Hailu Kassu";
    cout << "\n\t\t\t\tSchool: Dire Dawa University";
    cout << "\n\n\t\t\t\tPress Enter to Continue...";
    cin.get(); // to pause the screen
}

//***************************************************************
//    	function to display entry menu
//****************************************************************

void entry_menu()
{
    char ch;
    cout << "\n\n\n\tENTRY MENU";
    cout << "\n\n\t01. Create Student Record";
    cout << "\n\n\t02. Display All Students' Record";
    cout << "\n\n\t03. Search Student Record";
    cout << "\n\n\t04. Modify Student Record";
    cout << "\n\n\t05. Delete Student Record";
    cout << "\n\n\t06. Back to Main Menu";
    cout << "\n\n\tPlease Select Your Option (1-6): ";
    cin >> ch;
    switch (ch)
    {
        case '1': write_student();
            break;
        case '2': display_all();
            break;
        case '3':
            int num;
            cout << "\n\n\tEnter Roll Number: ";
            cin >> num;
            display_sp(num);
            break;
        case '4':
            cout << "\n\n\tEnter Roll Number: ";
            cin >> num;
            modify_student(num);
            break;
        case '5':
            cout << "\n\n\tEnter Roll Number: ";
            cin >> num;
            delete_student(num);
            break;
        case '6':
            break;
        default: cout << "\a";
    }
}

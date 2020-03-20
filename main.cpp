#include <iostream>
#include <limits>
#include "tubKec.h"
using namespace std;

int main(){
    cout<<"+--------------------------------------+"<<endl;
    cout<<"|       Instructor List Program        |"<<endl;
    cout<<"+--------------------------------------+"<<endl;
    cout<<"|  1) Add a new Instructor             |"<<endl;
    cout<<"|  2) Assign a course to an instructor |"<<endl;
    cout<<"|  3) Delete a certain instructor      |"<<endl;
    cout<<"|  4) Delete a certain course          |"<<endl;
    cout<<"|  5) Show instructor course           |"<<endl;
    cout<<"|  6) Find course instructor           |"<<endl;
    cout<<"|  7) Show all instructors             |"<<endl;
    cout<<"|  8) Find course average              |"<<endl;
    cout<<"|  9) Find greatest course number      |"<<endl;
    cout<<"|     and the number of instructor     |"<<endl;
    cout<<"| 10) Find instructor who teach more   |"<<endl;
    cout<<"|     than three courses               |"<<endl;
    cout<<"| 11) Add a number of new students to  |"<<endl;
    cout<<"|     a certain course                 |"<<endl;
    cout<<"| 12) Decrease a number of students    |"<<endl;
    cout<<"|     from a certain course            |"<<endl;
    cout<<"| 13) Show the number of students of a |"<<endl;
    cout<<"|     certain course                   |"<<endl;
    cout<<"|  0) EXIT                             |"<<endl;
    cout<<"+--------------------------------------+"<<endl;
    cout<<"Insert command number: ";
    list L;
    createList(L);
    int x = 99;
    cin>>x;
    while (x != 0){
        string insName, crsID;
        if (x == 1){
            cout<<"Input instructor name to be added to the list: ";
            cin>>insName;
            addInstructor(L, insName);
        } else if (x == 2){
            cout<<"Input course ID to be added: ";
            cin>>crsID;
            cout<<"Input instructor name to be assign the course: ";
            cin>>insName;
            assignCourse(L, insName, crsID);
        } else if (x == 3){
            if (isEmpty(L)){
                cout<<"The list is empty"<<endl;
            } else {
                cout<<"Input instructor name to be deleted: ";
                cin>>insName;
                deleteInstructor(L, insName);
            }
        } else if (x == 4){
            if (isEmpty(L)){
                cout<<"The list is empty"<<endl;
            } else {
                cout<<"Input course ID to be deleted: ";
                cin>>crsID;
                deleteCourse(L, crsID);
            }
        } else if (x == 5){
            cout<<"Input instructor name to see what courses they teach: ";
            cin>>insName;
            showInstructorCourses(L, insName);
        } else if (x == 6){
            cout<<"Input course ID to find the instructor who taught it: ";
            cin>>crsID;
            findCourseInstructor(L, crsID);
        } else if (x == 7){
            showAllInstructor(L);
        } else if (x == 8){
            averageCourse(L);
        } else if (x == 9){
            maxCourse(L);
        } else if (x == 10){
            moreThanThree(L);
        } else if (x == 11){
            if(isEmpty(L)) {
                cout<<"There are no instructors or courses listed";
            } else {
                string crsID;
                cout<<"Input course ID to be added with new students: ";
                cin>>crsID;
                adrToIns I = searchCrs(L, crsID);
                if (I == NULL) {
                    cout<<"No course with that ID is found"<<endl;
                } else {
                    int addStud;
                    cout<<"Input number of new students: ";
                    cin>>addStud;
                    addStudToCourse(L, crsID, addStud);
                }
            }
        } else if (x == 12){
            if(isEmpty(L)){
                cout<<"There are no instructors or courses listed";
            } else {
                string crsID;
                cout<<"Input course ID to decrease the students: ";
                cin>>crsID;
                adrToIns I = searchCrs(L, crsID);
                if (I == NULL) {
                    cout<<"No course with that ID is found"<<endl;
                } else {
                    int decStud;
                    cout<<"Input number of students to be decreased: ";
                    cin>>decStud;
                    decStudFromCourse(L, crsID, decStud);
                }
            }
        } else if (x == 13) {
            if(isEmpty(L)) {
                cout<<"There are no instructors or courses listed";
            } else {
                adrToIns I = searchCrs(L, crsID);
                if (I == NULL) {
                    string crsID;
                    cout<<"Input course ID to know the number of students there: ";
                    cin>>crsID;
                    cout<<"No course with that ID is found"<<endl;
                } else {
                    showStudentOfCourse(L, crsID);
                }
            }
        } else {
            cout<<"No command with that number"<<endl;
        }
        inline waitEnter();
        cout<<endl;
        cout<<"+--------------------------------------+"<<endl;
        cout<<"|       Instructor List Program        |"<<endl;
        cout<<"+--------------------------------------+"<<endl;
        cout<<"|  1) Add a new Instructor             |"<<endl;
        cout<<"|  2) Assign a course to an instructor |"<<endl;
        cout<<"|  3) Delete a certain instructor      |"<<endl;
        cout<<"|  4) Delete a certain course          |"<<endl;
        cout<<"|  5) Show instructor course           |"<<endl;
        cout<<"|  6) Find course instructor           |"<<endl;
        cout<<"|  7) Show all instructors             |"<<endl;
        cout<<"|  8) Find course average              |"<<endl;
        cout<<"|  9) Find greatest course number      |"<<endl;
        cout<<"|     and the number of instructor     |"<<endl;
        cout<<"| 10) Find instructor who teach more   |"<<endl;
        cout<<"|     than three courses               |"<<endl;
        cout<<"| 11) Add a number of new students to  |"<<endl;
        cout<<"|     a certain course                 |"<<endl;
        cout<<"| 12) Decrease a number of students    |"<<endl;
        cout<<"|     from a certain course            |"<<endl;
        cout<<"| 13) Show the number of students of a |"<<endl;
        cout<<"|     certain course                   |"<<endl;
        cout<<"|  0) EXIT                             |"<<endl;
        cout<<"+--------------------------------------+"<<endl;
        cout<<"Insert command number: ";
        cin>>x;
    }
    return 0;
}

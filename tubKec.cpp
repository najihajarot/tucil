#include <iostream>
#include "tubKec.h"
using namespace std;

void createList(list &L){
/*  I.S -
    F.S list L is defined */
    first(L) = NULL;
    last(L) = NULL;
}

bool isEmpty(list L){
/*  I.S list L is defined
    F.S return true if L is empty, false if otherwise */
    return first(L) == NULL && last(L) == NULL;
}

adrToIns searchIns(list L, string insName){
/*  I.S list L is defined, L maybe empty
    F.S returns the address of Instructor with the name "insName",
        or NULL if not found*/
    adrToIns I = first(L);
    bool found = false;
    while (I != NULL && !found){
        found = name(I) == insName;
        if (!found){
            I = nextIns(I);
        }
    }
    if (found){
        return I;
    } else {
        return NULL;
    }
}

adrToIns searchCrs(list L, string crsID){
/*  I.S list L is defined, L maybe empty
    F.S returns the address of Instructor who teaches a course with
        the ID "crsID", or NULL if not found */
    adrToIns I = first(L);
    adrToCrs C = NULL;
    bool found = false;
    while (I != NULL && !found){
        if (crsHead(I) != NULL){
            C = crsHead(I);
            do{
                found = ID(C) == crsID;
                if (!found){
                    C = nextCrs(C);
                }
            } while (C != crsHead(I) && !found);
        }
        if (!found){
            I = nextIns(I);
        }
    }
    if (found){
        return I;
    } else {
        return NULL;
    }
}

void addInstructor(list &L, string insName){
/*  I.S list L is defined, L maybe empty
    F.S a new Instructor with the name "insName" is added to the first
        element of the list L*/
    adrToIns I = searchIns(L, insName);
    if (I != NULL){
        cout<<"There is already an instructor with that name"<<endl;
    } else {
        I = new instructor;
        name(I) = insName;
        sumCrs(I) = 0;
        crsHead(I) = NULL;
        if (isEmpty(L)){
            last(L) = I;
        } else {
            prevIns(first(L)) = I;
        }
        nextIns(I) = first(L);
        first(L) = I;
        cout<<"A new instructor has been added"<<endl;
    }
}

void assignCourse(list &L, string insName, string crsID){
/*  I.S list L is defined, L maybe empty
    F.S a new course with the ID "crsID" is assigned to an instructor
        with the name "insName" */
    adrToIns I = searchCrs(L, crsID);
    if (I != NULL){
        cout<<"That course is already assign to an Instructor with the name "<<name(I)<<endl;
    } else {
        I = searchIns(L, insName);
        if (I == NULL){
            cout<<"No instructor with that name is found"<<endl;
        } else {
            adrToCrs C = new course;
            ID(C) = crsID;
            stud(C) = 0;
            if (crsHead(I) == NULL){
                nextCrs(C) = C;
            } else {
                nextCrs(C) = crsHead(I);
                adrToCrs temp = crsHead(I);
                while (nextCrs(temp) != crsHead(I)){
                    temp = nextCrs(temp);
                }
                nextCrs(temp) = C;
            }
            crsHead(I) = C;
            sumCrs(I)++;
            cout<<"A new course has been assign"<<endl;
        }
    }
}

void deleteInstructor(list &L, string insName){
/*  I.S L is defined, L maybe empty
    F.S the Instructor with the name "insName" is deleted from the list L
        along with all of its courses */
    adrToIns I = searchIns(L, insName);
    if (I == NULL){
        cout<<"No instructor with that name is found"<<endl;
    } else {
        if (first(L) == last(L)){
            createList(L);
        } else if (I == first(L)){
            prevIns(nextIns(I)) = NULL;
            first(L) = nextIns(I);
        } else if (I == last(L)){
            nextIns(prevIns(I)) = NULL;
            last(L) = prevIns(I);
        } else {
            nextIns(prevIns(I)) = nextIns(I);
            prevIns(nextIns(I)) = prevIns(I);
        }
        nextIns(I) = NULL;
        prevIns(I) = NULL;
        cout<<"Instructor "<<insName<<" has been removed"<<endl;
    }
}

void deleteCourse(list &L, string crsID){
/*  I.S L is defined, L maybe empty
    F.S the course with the ID "crsID" is deleted from the the Instructor
        course list */
    adrToIns I = searchCrs(L, crsID);
    if (I == NULL){
        cout<<"No course with that ID is found"<<endl;
    } else {
        adrToCrs C = crsHead(I);
        if (nextCrs(C) == C){
            crsHead(I) = NULL;
        } else
            while (ID(nextCrs(C)) != crsID){
                C = nextCrs(C);
            }
            adrToCrs temp = nextCrs(C);
            nextCrs(C) = nextCrs(temp);
            if (temp == crsHead(I)){
                crsHead(I) = nextCrs(temp);
            }
        nextCrs(temp) = NULL;
        sumCrs(I)--;
        cout<<"course "<<crsID<<" has been deleted"<<endl;
    }
}

void showInstructorCourses(list L, string insName){
/*  I.S L is defined, L maybe empty
    F.S prints the courses taught by the instructor with the name "insName" */
    adrToIns I = searchIns(L, insName);
    if (I == NULL){
        cout<<"No instructor with that name is found"<<endl;
    } else {
        if (crsHead(I) == NULL){
            cout<<insName<<" does not teach any course";
        } else {
            cout<<insName<<" teaches: ";
            adrToCrs C = crsHead(I);
            do {
                cout<<ID(C)<<" ";
                C = nextCrs(C);
            } while (C != crsHead(I));
        }
    }
    cout<<endl;
}

void findCourseInstructor(list L, string crsID){
/*  I.S L is defined, L maybe empty
    F.S prints the Instructor who taught the course with the ID "crsID" */
    adrToIns I = searchCrs(L, crsID);
    if (I == NULL){
        cout<<"No course with that ID is found"<<endl;
    } else {
        cout<<crsID<<" is taught by "<<name(I)<<endl;
    }
}

void showAllInstructor(list L){
/*  I.S L is defined, L maybe empty
    F.S prints all of instructor listed on the list */
    if (isEmpty(L)){
        cout<<"There are no instructor listed"<<endl;
    } else {
        cout<<"Instructors: ";
        adrToIns I = first(L);
        while (I != NULL){
            cout<<name(I)<<" ";
            I = nextIns(I);
        }
        cout<<endl;
    }
}

void averageCourse(list L){
/*  I.S L is defined, L maybe empty
    F.S find the average number of courses taught by an instructor */
    if (isEmpty(L)){
        cout<<"There are no instructor listed"<<endl;
    } else {
        adrToIns I = first(L);
        int ins = 0;
        int crs = 0;
        while (I != NULL){
            if (crsHead(I) != NULL){
                ins++;
                crs = crs + sumCrs(I);
            }
            I = nextIns(I);
        }
        cout<<"The average number of courses taught by an instructor is: "<<crs/ins<<endl;
    }
}

void maxCourse(list L){
/*  I.S L is defined, L maybe empty
    F.S find the greatest number of courses taught by a same instructor
        and the number of courses who teach that much courses */
    if (isEmpty(L)){
        cout<<"There are no instructor listed"<<endl;
    } else {
        adrToIns I = first(L);
        int Nmax = 0;
        while (I != NULL){
            if (sumCrs(I) > Nmax){
                Nmax = sumCrs(I);
            }
            I = nextIns(I);
        }
        I = first(L);
        int ins = 0;
        while (I != NULL){
            if (sumCrs(I) == Nmax){
                ins++;
            }
            I = nextIns(I);
        }
        cout<<"The greatest number of courses taught by a same instructor are: "<<Nmax<<endl;
        cout<<"The number of courses who teach "<<Nmax<<" courses are: "<<ins<<endl;
    }
}

void moreThanThree(list L){
/*  I.S L is defined, L maybe empty
    F.S find an instructor who teaches more than 3 courses */
    if (isEmpty(L)){
        cout<<"There are no instructor listed"<<endl;
    } else {
        cout<<"Instructor who teaches more than 3 courses are: ";
        adrToIns I = first(L);
        bool found = false;
        while (I != NULL){
            if (sumCrs(I) > 3){
                found = true;
                cout<<name(I)<<" ";
            }
            I = nextIns(I);
        }
        if (!found){
            cout<<"No one";
        }
        cout<<endl;
    }
}

void addStudToCourse(list L, string crsID, int addStud){
/*  I.S L is defined, L maybe empty
    F.S find an instructor who teaches more than 3 courses */
    if(isEmpty(L)) {
        cout<<"There are no instructors or courses listed";
    } else {
        adrToIns I = searchCrs(L, crsID);
        if (I == NULL) {
            cout<<"No course with that ID is found"<<endl;
        } else {
            adrToCrs C = crsHead(I);
            while (ID(nextCrs(C)) != crsID){
                C = nextCrs(C);
            }
            while (stud(C) + addStud > 40) {
                cout<<"The current number of students in that class is "<<stud(C)<<" students"<<endl;
                cout<<"Maximum number of students in class is 40. Please input a valid number.";
                cout<<"Input number of students to be added: ";
                cin>>addStud;
                cout<<endl;
            }
            stud(C) = stud(C) + addStud;
            cout<<"Total student in "<<crsID<<" is now "<<stud(C)<<" student"<<endl;
        }
    }
}

void decStudFromCourse(list L, string crsID, int decStud){
/*  I.S L is defined, L maybe empty
    F.S find an instructor who teaches more than 3 courses */
    if(isEmpty(L)) {
        cout<<"There are no instructors or courses listed";
    } else {
        adrToIns I = searchCrs(L, crsID);
        if (I == NULL) {
            cout<<"No course with that ID is found"<<endl;
        } else {
            adrToCrs C = crsHead(I);
            while (ID(nextCrs(C)) != crsID){
                C = nextCrs(C);
            }
            while (stud(C) - decStud < 0) {
                cout<<"The current number of students in that class is "<<stud(C)<<" students"<<endl;
                cout<<"Please input a valid number."<<endl;
                cout<<"Input number of students to be decreased: ";
                cin>>decStud;
                cout<<endl;
            }
            stud(C) = stud(C) - decStud;
            cout<<"Total student in "<<crsID<<" is now "<<stud(C)<<" student"<<endl;
        }
    }
}

void showStudentOfCourse(list L, string crsID){
/*  I.S L is defined, L maybe empty
    F.S find an instructor who teaches more than 3 courses */
    if(isEmpty(L)) {
        cout<<"There are no instructors or courses listed";
    } else {
        adrToIns I = searchCrs(L, crsID);
        if (I == NULL) {
            cout<<"No course with that ID is found"<<endl;
        } else {
            adrToCrs C = crsHead(I);
            while (ID(nextCrs(C)) != crsID){
                C = nextCrs(C);
            }
            cout<<"Total student in this course is "<<stud(C)<<" student."<<endl;
        }

    }
}

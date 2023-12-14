#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
using namespace std;

enum Specialnist { Computer_Science, Philology, Information_Technology };

struct Student
{
    string prizv;
    int course;
    Specialnist specialnist;
    double physics_grade;
    double math_grade;
    double informatics_grade;
};

void Create(Student* S, const int N);
void Print(Student* S, const int N);
void BubbleSort(Student* students, const int N);
int BinSearch(Student* S, const int N, const string prizv, const Specialnist specialnost, const double grade);
int* Index_Sort(Student* students, const int N);
void PrintIndexSorted(Student* S, int* indexArray, const int N);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Input N: "; cin >> N;

    Student* S = new Student[N];
    string prizv;
    Specialnist specialnist;
    int ispecialnist;
    double third_grade;
    int found;

    int menuItem;
    do {
        cout << endl << endl << endl;
        cout << "Choose an extion: " << endl << endl;
        cout << " [1] - entering data from the keyboard" << endl;
        cout << " [2] - print data in display" << endl;
        cout << " [3] - sort" << endl;
        cout << " [4] - binary search student from last name, specialnist, thirdGrade" << endl;
        cout << " [5] - creat index massive" << endl;
        cout << " [0] - Exit" << endl << endl;
        cout << "Input value: "; cin >> menuItem;
        cout << endl << endl << endl;

        switch (menuItem)
        {
        case 1:
            Create(S, N);
            break;
        case 2:
            Print(S, N);
            break;
        case 3:
            BubbleSort(S, N);
            Print(S, N);
            break;
        case 4:
            cout << "Input keys of search: " << endl;
            cout << "Last Name: " << endl;
            cin >> prizv;
            cout << endl;
            cout << "Specialnost (0 - Computer_Science, 1 - Philology, 2 -  Information_Technology): ";
            cin >> ispecialnist;

            cin.get();
            cin.sync();

            specialnist = (Specialnist)ispecialnist;

            cout << "Input third grade: " << endl;
            cin >> third_grade;
            cout << endl;
            if ((found = BinSearch(S, N, prizv, specialnist, third_grade)) != -1)
                cout << "Student was founded " << found + 1 << endl;
            else
                cout << "Student wasn't founded " << endl;
            break;
        case 5:
            PrintIndexSorted(S, Index_Sort(S, N), N);
            break;
        case 0:
            break;
        default:
            cout << "You input mistake value!" << endl;
        }
    } while (menuItem != 0);


    delete[] S;

    return 0;
}

void Create(Student* S, const int N) {
    int specialnist_value;
    for (int i = 0; i < N; i++) {
        cout << "Student # " << i + 1 << ":" << endl;

        cin.get();
        cin.sync();

        cout << " Last Name: ";  getline(cin, S[i].prizv);
        cout << " Course: ";  cin >> S[i].course;
        cout << " Specialnist (0 - Computer_Science, 1 - Philology, 2 -  Information_Technology): ";

        cin >> specialnist_value;
        S[i].specialnist = static_cast<Specialnist>(specialnist_value);
        cout << "Physics Grade: ";
        cin >> S[i].physics_grade;
        cout << "Mathematics Grade: ";
        cin >> S[i].math_grade;
        cout << "Informatics Grade: ";
        cin >> S[i].informatics_grade;
        cout << "-----------------------------\n";
    }
}

void Print(Student* S, const int N)
{
    cout << "=================================================================================================="
        << endl;
    cout << "| # | Last Name             | Course | Specialnist                | Phisics | Math | Informatics |"
        << endl;
    cout << "--------------------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++) {
        cout << "| " << setw(3) << right << i + 1 << " ";
        cout << "| " << setw(24) << left << S[i].prizv << " | " << left << S[i].course
            << " | ";

        switch (S[i].specialnist) {
        case Computer_Science:
            cout << setw(27) << "Computer_Science";
            break;
        case Philology:
            cout << setw(27) << "Philology";
            break;
        case Information_Technology:
            cout << setw(27) << "Information_Technology";
            break;
        }

        cout << " | " << setw(6) << S[i].physics_grade << " | " << setw(10) << S[i].math_grade
            << " | " << setw(11) << S[i].informatics_grade << " |" << endl;
    }
    cout << "=================================================================================================="
        << endl;
}

void BubbleSort(Student* students, const int N) {
    for (int i0 = 0; i0 < N - 1; i0++) {
        for (int i1 = 0; i1 < N - i0 - 1; i1++) {
            double grade1, grade2;


            if (students[i1].specialnist == Computer_Science || Philology || Information_Technology) {
                grade1 = students[i1].informatics_grade;
            }
            else {
                grade1 = students[i1].informatics_grade;
            }

            if (students[i1 + 1].specialnist == Computer_Science || Philology || Information_Technology) {
                grade2 = students[i1 + 1].informatics_grade;
            }
            else {
                grade2 = students[i1 + 1].informatics_grade;
            }

            if (grade1 < grade2) {
                swap(students[i1], students[i1 + 1]);
            }

            else if (grade1 == grade2) {
                if (students[i1].specialnist > students[i1 + 1].specialnist) {
                    swap(students[i1], students[i1 + 1]);
                }

                else if (students[i1].specialnist == students[i1 + 1].specialnist && students[i1].prizv > students[i1 + 1].prizv) {
                    swap(students[i1], students[i1 + 1]);
                }
            }
        }
    }
}

int BinSearch(Student* S, const int N, const string prizv, const Specialnist specialnist, const double grade) {
    int left = 0, right = N - 1;

    do {
        int mid = (right + left) / 2;
        if (S[mid].prizv == prizv && S[mid].specialnist == specialnist)
            return mid;
        if ((S[mid].specialnist < specialnist) || (S[mid].specialnist == specialnist && S[mid].prizv < prizv) || (S[mid].specialnist == specialnist && S[mid].prizv == prizv && S[mid].informatics_grade < grade))
            left = mid + 1;
        else
            right = mid + 1;
    } while (left <= right);

    return -1;
}


int* Index_Sort(Student* students, const int N) {
    int* indexArray = new int[N];

    for (int i = 0; i < N; ++i) {
        indexArray[i] = i;
    }

    for (int i0 = 0; i0 < N - 1; i0++) {
        for (int i1 = 0; i1 < N - i0 - 1; i1++) {
            double grade1, grade2;

            if (students[indexArray[i1]].specialnist == Computer_Science || Philology || Information_Technology) {
                grade1 = students[indexArray[i1]].informatics_grade;
            }
            else {
                grade1 = students[indexArray[i1]].informatics_grade;
            }

            if (students[indexArray[i1 + 1]].specialnist == Computer_Science || Philology || Information_Technology) {
                grade2 = students[indexArray[i1 + 1]].informatics_grade;
            }
            else {
                grade2 = students[indexArray[i1 + 1]].informatics_grade;
            }

            if (grade1 < grade2) {
                swap(indexArray[i1], indexArray[i1 + 1]);
            }

            else if (grade1 == grade2) {
                if (students[indexArray[i1]].specialnist > students[indexArray[i1 + 1]].specialnist) {
                    swap(indexArray[i1], indexArray[i1 + 1]);
                }

                else if (students[indexArray[i1]].specialnist == students[indexArray[i1 + 1]].specialnist &&
                    students[indexArray[i1]].prizv > students[indexArray[i1 + 1]].prizv) {
                    swap(indexArray[i1], indexArray[i1 + 1]);
                }
            }
        }
    }

    return indexArray;
}



void PrintIndexSorted(Student* S, int* indexArray, const int N) {
    cout << "=================================================================================================="
        << endl;
    cout << "| # | Last Name             | Course | Specialnist                | Phisics | Math | Informatics |"
        << endl;
    cout << "--------------------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++) {
        cout << "| " << setw(3) << right << i + 1 << " ";
        cout << "| " << setw(24) << left << S[i].prizv << " | " << left << S[i].course
            << " | ";

        switch (S[i].specialnist) {
        case Computer_Science:
            cout << setw(27) << "Computer_Science";
            break;
        case Philology:
            cout << setw(27) << "Philology";
            break;
        case Information_Technology:
            cout << setw(27) << "Information_Technology";
            break;
        }

        cout << " | " << setw(6) << S[i].physics_grade << " | " << setw(10) << S[i].math_grade
            << " | " << setw(11) << S[i].informatics_grade << " |" << endl;
    }
    cout << "=================================================================================================="
        << endl;
}

#include "Schedule.h"
#include <algorithm>
#include <utility>

Schedule::Schedule(UC ucClass) {
    this->UcClass = std::move(ucClass);
    CsvAndVectors CSVInfo;
    vector<Lesson> LessonsVector = CSVInfo.getLessonsVector();
    vector<Student> StudentsVector = CSVInfo.getStudentsVector();

    // get lessons from this ucClass(UcCode, ClassCode)
    for (auto &lesson: LessonsVector) {
        if (lesson.getUc() == this->UcClass) {
            this->lessons.insert(lesson);
        }
        // if the user wants the schedule of an uc
        else if (lesson.getUc().getUcCode() == this->UcClass.getUcCode() && this->UcClass.getClassCode().empty()) {
            this->lessons.insert(lesson);
        }
        // if the user wants the schedule of a class
        else if (lesson.getUc().getClassCode() == this->UcClass.getClassCode() && this->UcClass.getUcCode().empty()) {
            this->lessons.insert(lesson);
        }
    }

    // get students from this ucClass(UcCode, ClassCode)
    for (auto &student_: StudentsVector) {
        for (auto &uc : student_.getUCs()) {
            if (uc == this->UcClass) {
                this->students.insert(student_);
            }
            // if the user wants the schedule of an uc
            else if (uc.getUcCode() == this->UcClass.getUcCode() && this->UcClass.getClassCode().empty()) {
                this->students.insert(student_);
            }
            // if the user wants the schedule of a class
            else if (uc.getClassCode() == this->UcClass.getClassCode() && this->UcClass.getUcCode().empty()) {
                this->students.insert(student_);
            }
        }
    }
}

// schedule of a student
Schedule::Schedule(const string& StudentCode) {
    CsvAndVectors CSVInfo;
    vector<Student> StudentsVector = CSVInfo.getStudentsVector();
    vector<Lesson> LessonsVector = CSVInfo.getLessonsVector();

    for (auto &student_ : StudentsVector) {
        if (StudentCode == student_.getStudentCode()) {
            this->student = student_;
        }
    }

    for (auto &uc: this->student.getUCs()) {
        for (auto &lesson : LessonsVector) {
            if (uc == lesson.getUc()) {
                this->lessons.insert(lesson);
            }
        }
    }
}

void Schedule::addLesson(const Lesson& lesson) {
    this->lessons.insert(lesson);

    //change in CSV file
    CsvAndVectors CSVInfo;
    vector<Lesson> LessonsVector = CSVInfo.getLessonsVector();
    LessonsVector.push_back(lesson);
    CSVInfo.setFromLessonsVector();
}

void Schedule::removeLesson(Lesson& lesson) {
    this->lessons.erase(lesson);

    CsvAndVectors CSVInfo;
    vector<Lesson> LessonsVector = CSVInfo.getLessonsVector();
    for (auto it = LessonsVector.begin(); it != LessonsVector.end(); it++) {
        if (*it == lesson) {
            LessonsVector.erase(it);
        }
    }
}

set<Lesson> Schedule::getLesson() const {
    return this->lessons;
}

void Schedule::drawSchedule() const {
    vector<string> v = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    bool exists = false;
    for (const string& day : v) {
        exists = false;
        cout << day << "\n";
        for (const Lesson& l: this->lessons) {
            if (l.getWeekday() == day) {
                l.drawLesson();
                exists = true;
            }
        }
        if (!exists) cout << ">> There is no lessons in this day." << endl;
        cout << endl;
    }
}

bool Schedule::hasSameUcCode(Schedule &UcCode) {
   return UcClass.getUcCode() == UcCode.getUcClass().getUcCode();
}

UC Schedule::getUcClass() {
    return this->UcClass;
}

set<Student> Schedule::getStudents() {
    return this->students;
}

void Schedule::addStudent(const Student& student) {
    students.insert(student);
}

void Schedule::removeStudent(const Student& student) {
    students.erase(student);
}

bool Schedule::operator<(Schedule schedule) {
    return this->UcClass < schedule.getUcClass();
}

void Schedule::printUcAndClass() {
    cout << "UC: " << UcClass.getUcCode() << " " << UcClass.getClassCode() << endl;
}

void Schedule::sortStudents(const int &sort_) {
    vector<Student> sorted = vector<Student>(students.begin(), students.end());
    if (sort_ == 1) {
        sort(sorted.begin(), sorted.end(), [](Student &A, Student &B) {
            return A.getStudentName() < B.getStudentName();
        });
    } else if (sort_ == 2) {
        sort(sorted.begin(), sorted.end(), [](Student &A, Student &B) {
            return A.getStudentName() > B.getStudentName();
        });
    } else if (sort_ == 3) {
        sort(sorted.begin(), sorted.end());
    } else if (sort_ == 4) {
        sort(sorted.rbegin(), sorted.rend());
    }

    for (const Student& student: sorted) {
        cout << student.getStudentCode() << "; " << student.getStudentName() << endl;
    }
}

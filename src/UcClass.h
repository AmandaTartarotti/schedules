//UcClass.h

#ifndef SCHEDULES_UCCLASS_H
#define SCHEDULES_UCCLASS_H

#include <utility>
#include <string>
#include <set>
#include <vector>
#include "Lecture.h"
using namespace std;
class Student;

class UcClass {
private:
    string uccode;
    string classnum;
    int size;
    vector<Lecture> lectureClass;
public:
    /**
     * @brief constructor of a UcClass object
     */
    UcClass(const string& uccode_, const string& classnum_);
    /**
     * @brief accesses the code of the UC
     * @complexity O(1)
     */
    string getUcCode() const;
    /**
     * @brief accesses the code of the class
     * @complexity O(1)
     */
    string getClassNum() const;
    /**
     * @brief accesses the size of the class
     * @complexity O(1)
     */
    int getSize() const;
    /**
     * @brief increments the size of a UcClass
     * @complexity O(1)
     */
    void incrementSize();
    /**
     * @brief decrements the size of a UcClass
     * @complexity O(1)
     */
    void decrementSize();
    /**
    * @brief defines the "<" operator to compare UcClass objects by UC code and class code
    * @complexity O(1)
    */
    bool operator<(UcClass s) const;
    /**
    * @brief defines the "==" operator to compare UcClass objects by UC code and class code
    * @complexity O(1)
    */
    bool operator==(UcClass s);
    /**
     * @brief adds a lecture to a UcClass
     * @complexity O(1)
     */
    void addLecture(const Lecture& lecture);
    /**
     * @brief accesses the lectures of a UcClass
     * @complexity O(1)
     */
    vector<Lecture> getLecture() const;
};

#endif //SCHEDULES_UCCLASS_H
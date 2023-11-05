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
     * @brief Constructor of a UcClass object
     * @param uccode_
     * @param classnum_
     */
    UcClass(const string& uccode_, const string& classnum_);
    /**
     * @brief Acesses the code of the UC
     * @complexity O(1)
     */
    string getUcCode() const;
    /**
     * @brief Acesses the code of the class
     * @complexity O(1)
     */
    string getClassNum() const;
    /**
     * @brief Acesses the size of the class
     * @complexity O(1)
     */
    int getSize() const;
    /**
     * @brief Increments the size of a UcClass
     * @complexity O(1)
     */
    void incrementSize();
    /**
     * @brief Decrements the size of a UcClass
     * @complexity O(1)
     */
    void decrementSize();
    /**
    * @brief Defines the "<" operator to compare UcClass objects by UC code and class code
    * @complexity O(1)
    */
    bool operator<(UcClass s) const;
    /**
    * @brief Defines the "==" operator to compare UcClass objects by UC code and class code
    * @complexity O(1)
    */
    bool operator==(UcClass s);
    /**
     * @brief Adds a lecture to a UcClass
     * @complexity O(1)
     */
    void addLecture(const Lecture& lecture);
    /**
     * @brief Acesses the lectures of a UcClass
     * @complexity O(1)
     */
    vector<Lecture> getLecture() const;
};

#endif //SCHEDULES_UCCLASS_H
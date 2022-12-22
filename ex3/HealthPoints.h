#ifndef EX3_HealthPoints_H
#define EX3_HealthPoints_H

#include <iostream>


class HealthPoints
{
public:
    /*
    * Creator of HealthPoints class.
    *
    * @param amount - the starting max health and current hp.
     *              if not given, reset to DEFAULT_POINTS.
    *
    * @return
    *      A new instance of HealthPoints.
    */
    HealthPoints(int amount = DEFAULT_POINTS);


    /*
     * default copy constructor, assignment operator and destructor.
     */
    HealthPoints(const HealthPoints &) = default;
    HealthPoints& operator=(const HealthPoints &other) = default;
    ~HealthPoints() = default;

    /*
    * adds a curtain amount of health to current hp.
    * hp will stay between 0 and maxHealth.
    *
    * @param amount - the amount needed to add.
    *
    * @return
    *   A reference to the object (this).
    */
    HealthPoints &operator+=(int amount);

    /*
    * subtracts a curtain amount of health to current hp.
    * hp will stay between 0 and maxHealth.
    *
    * @param amount - the amount needed to subtract.
    *
    * @return
    *   A reference to the object (this).
    */
    HealthPoints &operator-=(int amount);

    /*
     * exception for putting non-positive value in the constructor.
     */
    class InvalidArgument : public std::exception {};

private:
    int m_points;
    int m_maxPoints;
    static const int DEFAULT_POINTS = 100;

    /*
     * check if health is between 0 and max health, and enforces it if needed.
     */
    void applyBoundaries();

    friend bool operator==(const HealthPoints &hp1, const HealthPoints &hp2);
    friend bool operator>(const HealthPoints &hp1, const HealthPoints &hp2);
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints &hp);

};

/*
* ----------------------------= Independent function declarations =--------------------------------
*/


/*
* compares 2 HealthPoints objects only by their current points (not max points).
*
* @param hp1, hp2 - two HealthPoints objects to compare.
*
* @return
*       true - if current amounts are equal.
*       false - otherwise.
*/
bool operator==(const HealthPoints &hp1, const HealthPoints &hp2);

/*
* compares 2 HealthPoints objects only by their current points (not max points).
*
* @param hp1, hp2 - two HealthPoints objects to compare.
*
* @return
*       true - if current amounts are  NOT equal.
*       false - otherwise.
*/
bool operator!=(const HealthPoints &hp1, const HealthPoints &hp2);

/*
* compares 2 HealthPoints objects only by their current points (not max points).
*
* @param hp1, hp2 - two HealthPoints objects to compare.
*
* @return
*       true - health in hp1 is greater than health in hp2.
*       false - otherwise.
*/
bool operator>(const HealthPoints &hp1, const HealthPoints &hp2);

/*
* compares 2 HealthPoints objects only by their current points (not max points).
*
* @param hp1, hp2 - two HealthPoints objects to compare.
*
* @return
*       true - health in hp1 is greater or equal than health in hp2.
*      false - otherwise.
*/
bool operator>=(const HealthPoints &hp1, const HealthPoints &hp2);

/*
* compares 2 HealthPoints objects only by their current points (not max points).
*
* @param hp1, hp2 - two HealthPoints objects to compare.
*
* @return
*       true - health in hp1 is smaller than health in hp2.
*       false - otherwise.
*/
bool operator<(const HealthPoints &hp1, const HealthPoints &hp2);

/*
* compares 2 HealthPoints objects only by their current points (not max points).
*
* @param hp1, hp2 - two HealthPoints objects to compare.
*
* @return
*       true - health in hp1 is smaller or equal than health in hp2.
*       false - otherwise.
*/
bool operator<=(const HealthPoints &hp1, const HealthPoints &hp2);

/*
* adds HealthPoints object with integer.
*
* @param hp1 - HealthPoints object to add.
*        num - integer to add.
*
* @return
*       HealthPoints with same max points as hp and current points as hp + num.
*/
HealthPoints operator+(const HealthPoints& hp, int num);

/*
* adds HealthPoints object with integer.
*
* @param hp1 - HealthPoints object to add.
*        num - integer to add.
*
* @return
*       HealthPoints with same max points as hp and current points as hp + num.
*/
HealthPoints operator+(int num, const HealthPoints &hp);

/*
* subtracts integer from HealthPoints object.
*
* @param hp1 - HealthPoints object to subtract from.
*        num - integer to subtract.
*
* @return
*       HealthPoints with same max points as hp and current points as hp - num.
*/
HealthPoints operator-(const HealthPoints &hp, int num);


/*
* prints HealthPoints object to an output stream.
*
* @param os - output stream to print into
*        hp - HealthPoints object to print.
*
* @return
*       a reference to os.
*/
std::ostream& operator<<(std::ostream &os, const HealthPoints &hp);


#endif //EX3_HealthPoints_H

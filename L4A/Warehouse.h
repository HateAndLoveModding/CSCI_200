/* CSCI 200: L4A
 *
 * Author: Ryker Phelps
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     //None
 * Description: Impletement the Big 3 into the Warehouse object.
 */

#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "Box.h"

#include <ostream>
#include <vector>

/**
 * @brief takes in sized things and puts them into boxes.  stores
 * all the boxes internally
 * 
 */
class Warehouse {
public:
    /**
     * @brief Creates a deep copy of another warehouse object.
     * 
     * @param OTHER The Warehouse object to copy from.
     */
    Warehouse(const Warehouse& OTHER);

    /**
     * @brief Performs a deep copy of warehouse object and then deletes existing Box objects.
     * 
     * @param OTHER The Warehouse object to copy from.
     * @return Warehouse& A reference to the assigned Warehouse object.
     */
    Warehouse& operator=(const Warehouse& OTHER);

    /**
     * @brief Destroy the Warehouse object
     * 
     */
    ~Warehouse();

    /**
     * @brief Construct a new Warehouse object with
     * no boxes by default
     * 
     */
    Warehouse();
    /**
     * @brief puts the item into a Box of given size
     * @param SIZE size of the cube shaped box to store
     */
    void storeInBox(const int SIZE);
    /**
     * @brief Get the Box object at given position within the list
     * @param BOX_POS position within the list to retrieve
     * @return Box* pointer to the corresponding Box object
     */
    Box* getBox(const int BOX_POS) const;
    /**
     * @brief Get the Number Of Boxes object
     * 
     * @return int 
     */
    int getNumberOfBoxes() const;
    /**
     * @brief retrieves the warehouse letter identifier
     * @return char warehouse letter identifier
     */
    char getWarehouseLetter() const;
    /**
     * @brief sets the warehouse letter identifier
     * @param warehouseLetter letter to identify warehouse by
     */
     void setWarehouseLetter(char warehouseLetter);
private:
    /**
     * @brief holds a list of pointers to Boxes
     * 
     */
    std::vector<Box*>* _pBoxen;
    /**
     * @brief Warehouse letter identifier
     */
    char _warehouseLetter;
};

std::ostream& operator<<(std::ostream&, const Warehouse&);

#endif//WAREHOUSE_H

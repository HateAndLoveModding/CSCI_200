/* CSCI 200: L4B
 *
 * Author: Ryker Phelps
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     //None
 * Description: Implement a templated class.
 */

#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <ostream>
#include <vector>

/**
 * @brief Takes in things (of type T) and puts them into a list. Stores all the items internally.
 */
template <typename T>
class Warehouse {
public:
    /**
     * @brief Construct a new Warehouse object with no items by default.
     */
    Warehouse();

    /**
     * @brief Don't allow a Warehouse to be copied.
     */
    Warehouse(const Warehouse&) = delete;

    /**
     * @brief Don't allow a Warehouse to be copied.
     */
    Warehouse& operator=(const Warehouse&) = delete;

    /**
     * @brief Destroy the Warehouse object.
     */
    ~Warehouse();

    /**
     * @brief Puts the item into the warehouse.
     * @param ITEM The item of type T to store.
     */
    void store(const T& ITEM);

    /**
     * @brief Get the item at the given position within the warehouse.
     * @param ITEM_POS Position to retrieve.
     * @return T& Corresponding item.
     */
    T& retrieve(const size_t ITEM_POS) const;

    /**
     * @brief Get the Number Of items in the warehouse.
     * @return size_t The number of items.
     */
    size_t getNumberOfItems() const;

    /**
     * @brief Retrieves the warehouse letter identifier.
     * @return char Warehouse letter identifier.
     */
    char getWarehouseLetter() const;

    /**
     * @brief Sets the warehouse letter identifier.
     * @param warehouseLetter The letter to identify the warehouse.
     */
    void setWarehouseLetter(char warehouseLetter);

private:
    /**
     * @brief Holds a list of pointers to items of type T.
     */
    std::vector<T*>* _pItems;

    /**
     * @brief Warehouse letter identifier.
     */
    char _warehouseLetter;
};

/**
 * @brief Stream insertion operator to output a Warehouse.
 * 
 * @tparam T Type of items stored in the warehouse.
 * @param os Output stream.
 * @param warehouse The warehouse object to output.
 * @return std::ostream& The output stream with warehouse details.
 */
template <typename T>
std::ostream& operator<<(std::ostream& os, const Warehouse<T>& warehouse);

#endif // WAREHOUSE_H

template <typename T>
Warehouse<T>::Warehouse() {
    _pItems = new std::vector<T*>;
}

template <typename T>
Warehouse<T>::~Warehouse() {
    while( !_pItems->empty() ) {
        delete _pItems->back();
        _pItems->pop_back();
    }
    delete _pItems;
}

template <typename T>
void Warehouse<T>::store(const T& ITEM) {
    _pItems->push_back( new T(ITEM) );
}

template <typename T>
T& Warehouse<T>::retrieve(const size_t ITEM_POS) const {
    return *(_pItems->at(ITEM_POS));
}

template <typename T>
size_t Warehouse<T>::getNumberOfItems() const {
    return _pItems->size();
}

template <typename T>
char Warehouse<T>::getWarehouseLetter() const {
    return _warehouseLetter;
}

template <typename T>
void Warehouse<T>::setWarehouseLetter(const char warehouseLetter) {
    _warehouseLetter = warehouseLetter;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Warehouse<T>& WH) {
    const size_t NUM_ITEMS = WH.getNumberOfItems();
    os << "Warehouse " << WH.getWarehouseLetter() << " has " << NUM_ITEMS << " items (";
    for(size_t i = 0; i < NUM_ITEMS; i++) {
        os << WH.retrieve(i);
        if(i < NUM_ITEMS - 1) {
            os << ", ";
        }
    }
    os << ")";
    return os;
}
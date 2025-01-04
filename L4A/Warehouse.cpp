
#include "Warehouse.h"

using namespace std;

Warehouse::Warehouse() {
    _pBoxen = new vector<Box*>;
    _warehouseLetter = '?';
}

void Warehouse::storeInBox(const int SIZE) {
    _pBoxen->push_back( new Box(SIZE) );
}

Box* Warehouse::getBox(const int BOX_POS) const {
    return _pBoxen->at(BOX_POS);
}

int Warehouse::getNumberOfBoxes() const {
    return _pBoxen->size();
}

char Warehouse::getWarehouseLetter() const {
    return _warehouseLetter;
}

void Warehouse::setWarehouseLetter(const char warehouseLetter) {
    _warehouseLetter = warehouseLetter;
}

std::ostream& operator<<(ostream& os, const Warehouse& WH) {
    os << "Warehouse " << WH.getWarehouseLetter() << " has " << WH.getNumberOfBoxes() << " boxes (";
    for(int i = 0; i < WH.getNumberOfBoxes(); i++) {
        os << WH.getBox(i)->getBoxSize();
        if(i < WH.getNumberOfBoxes() - 1) {
            os << ", ";
        }
    }
    os << ")";
    return os;
}

Warehouse::Warehouse(const Warehouse& OTHER) {
    _pBoxen = new vector<Box*>;
    _warehouseLetter = OTHER._warehouseLetter;
    for(Box* box : *OTHER._pBoxen) {
        _pBoxen->push_back(new Box(*box));
    }
}

Warehouse& Warehouse::operator=(const Warehouse& OTHER) {
    if (this == &OTHER) return *this;
    for (Box* box : *_pBoxen) {
        delete box;
    }
    _pBoxen->clear();
    _warehouseLetter = OTHER._warehouseLetter;
    for (Box* box : *OTHER._pBoxen) {
        _pBoxen->push_back(new Box(*box));
    }
    return *this;
}

Warehouse::~Warehouse() {
    for (Box* box : *_pBoxen) {
        delete box;
    }
    delete _pBoxen;
}
#include "room.h"

Room::Room(unsigned int roomNo):_roomNumber(roomNo)
{

}

bool Room::available() const
{
    return _available;
}

void Room::setAvailable(bool available)
{
    _available = available;
}

unsigned int Room::roomNumber() const
{
    return _roomNumber;
}

void Room::setRoomNumber(unsigned int roomNumber)
{
    _roomNumber = roomNumber;
}

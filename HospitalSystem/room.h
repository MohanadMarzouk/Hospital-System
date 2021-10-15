#ifndef ROOM_H
#define ROOM_H


class Room
{
public:
    Room(unsigned int roomNo);
    bool available() const;
    void setAvailable(bool available);

    unsigned int roomNumber() const;
    void setRoomNumber(unsigned int roomNumber);

private:
    bool _available;
    unsigned int _roomNumber;
};

#endif // ROOM_H

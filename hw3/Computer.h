/*
 * Title: Heaps, Priority Queues
 * Author: Abdullah Riaz
 * ID: 22001296
 * Section: 3
 * Assignment: 3
 * Description: Computer Declaration File
 */


class Computer
{
public:
    Computer();
    ~Computer();

    int getID();
    void setTime(int time);
    int getTime();
    bool isFree(int time);

protected:
    static int nextId;

private:
    int id;
    int time;
};

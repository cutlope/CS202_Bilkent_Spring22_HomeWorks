/*
 * Title: Heaps, Priority Queues
 * Author: Abdullah Riaz
 * ID: 22001296
 * Section: 3
 * Assignment: 3
 * Description:  Requests Declaration File
 */

class Request
{
public:
    Request();
    Request(int requestID, int requestPriority, int requestTime, int processTime);
    Request(const Request &request);
    ~Request();

    int getRequestID() const;
    int getRequestPriority() const;
    int getRequestTime() const;
    int getProcessTime() const;

    void setRequestID(int requestID);
    void setRequestPriority(int requestPriority);
    void setRequestTime(int requestTime);
    void setProcessTime(int processTime);
    void setNull();
    void printRequest();

private:
    int requestID;
    int requestPriority;
    int requestTime;
    int processTime;
};

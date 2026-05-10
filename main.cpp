#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

std::string incoming_server_data = R"(HTTP1.1 200 OK 
{
    "light": "on",
    "fan": "off",
    "motor": "off"
})";

class ProcessData {
  private:
  public:
};

class IoT : ProcessData {
  private:
    enum class Device_State_t
    {
        OFF = 0,
        ON  = 1,
    };

  public:
    // Output handle
    typedef struct
    {
        char light;
        char fan;
        char motor
    } SmartHome_t;
};

int
main()
{

    return 0;
}
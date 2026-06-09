#include "Zappy.hpp"
#include "Raylib.hpp"
#include <memory>
#include <string>

zappy::Zappy::Zappy(int port, std::string hostname) : _map(0, 0), _commuication(port, hostname, _map),
    _graphical(std::make_unique<zappy::RaylibGraphical>(_map)), _exit(false), _communicationThread(&Zappy::LaunchSocket, this)
{
}

zappy::Zappy::~Zappy()
{
    _communicationThread.join();
}

void zappy::Zappy::Run()
{
    _graphical->loop();
}

void zappy::Zappy::LaunchSocket()
{
    _commuication.SocketLoop();
}

from .Communication import createSocket, handshake
from .AgenticIntelligenceKpiWorkflow import *
from select import *
import socket as skt


def initConnection(machine, port, name):
    socket = createSocket(machine, port, name)

    s = handshake(socket, name)
    if (s != ""):
        try:
            arr = [int(tmp) for tmp in s.split()]
        except ValueError:
            None
        if arr[0] > 0:
            return (True, Ai((arr[1], arr[2]), socket))
        return (False, Ai((arr[1], arr[2]), socket))


def mainLoop(machine, port, name):
    family = {}

    ret = initConnection(machine, port, name)
    while (ret[0] == True):
        family.update({ret[1].socket.fileno: ret[1]})
        ret = initConnection(machine, port, name)
    family.update({ret[1].socket.fileno(): ret[1]})

    pollObject = poll()
    for freakyAi in family.values():
        pollObject.register(freakyAi.socket, POLLIN)

    while True:
        pollEvent = pollObject.poll(0)

        for socket, event in pollEvent:
            if (event & POLLIN):
                s = family[socket].receive()
                print(s)

        if (len(family) == 0):
            break;
        for freakyAi in family.values():
            freakyAi.doThing()

    print("End of the program.")

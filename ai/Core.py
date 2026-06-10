from .AgenticIntelligenceKpiWorkflow import *
from .Communication import createSocket, SocketReceiveError
from select import *
import socket as skt


def slimeFreakster(ai, family, socketfd, pollObject):
    ai.socket.close()
    del family[socketfd]
    pollObject.unregister(socketfd)


def mainLoop(machine, port, name):
    firstConnection = Freakster((), createSocket(machine, port, name))
    family = {firstConnection.socket.fileno(): firstConnection}

    pollObject = poll()
    for freakyAi in family.values():
        pollObject.register(freakyAi.socket, POLLIN)

    while True:
        pollEvent = pollObject.poll(0)

        for socketfd, event in pollEvent:
            if (event & POLLIN):
                ai = family[socketfd]
                if ai.handshake == False and ai.welcome == False:
                    try:
                        ai.firstHandshake(name)
                    except SocketReceiveError:
                        slimeFreakster(ai, family, socketfd, pollObject)
                elif ai.handshake == False and ai.welcome == True:
                    try:
                        res = ai.finalHandshake()
                        if res == True:
                            newAi = Freakster((), createSocket(machine, port, name))
                            family.update({newAi.socket.fileno: newAi})
                    except SocketReceiveError:
                        slimeFreakster(ai, family, socketfd, pollObject)
                else:
                    try:
                        s = ai.receive()
                        print(s)
                    except SocketReceiveError:
                        slimeFreakster(ai, family, socketfd, pollObject)

        if len(family) == 0:
            break

    print("End of the program.")

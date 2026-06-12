from .AgenticIntelligenceKpiWorkflow import Freakster, Status
from .Communication import createSocket, SocketReceiveError
from select import poll, POLLIN
import socket as skt
import threading


def slimeFreakster(ai, socketfd, pollObject, family):
    del family[socketfd]
    pollObject.unregister(socketfd)
    ai.threadEvent.set()
    ai.thread.join()
    ai.socket.close()


def mainLoop(machine, port, name):
    firstConnection = Freakster(0, 0, createSocket(machine, port, name))
    family = {firstConnection.socket.fileno(): firstConnection}
    pollObject = poll()
    pollObject.register(firstConnection.socket, POLLIN)

    while True:
        pollEvent = pollObject.poll(0)

        for socketfd, event in pollEvent:
            if (event & POLLIN):
                ai = family[socketfd]
                if ai.handshake == False and ai.welcome == False:
                    try:
                        ai.firstHandshake(name)
                    except SocketReceiveError:
                        slimeFreakster(ai, socketfd, pollObject, family)
                elif ai.handshake == False and ai.welcome == True:
                    try:
                        res = ai.finalHandshake()
                        if res == True:
                            newAi = Freakster(0, 0, createSocket(machine, port, name))
                            family.update({newAi.socket.fileno(): newAi})
                            pollObject.register(newAi.socket, POLLIN)
                        ai.startThread()
                    except SocketReceiveError:
                        slimeFreakster(ai, socketfd, pollObject, family)
                else:
                    try:
                        s = ai.receive()
                        ai.threadEvent.set()
                        print(f"s = {s}")
                    except SocketReceiveError:
                        slimeFreakster(ai, socketfd, pollObject, family)

        if len(family) == 0:
            break

    print("End of the program.")

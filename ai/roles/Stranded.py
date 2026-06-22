from ..AgenticIntelligenceKpiWorkflow import Freakster, Direction, Role
from .Explorer import Explorer
from random import randint

class Stranded(Explorer):
    def __init__(self, socket, toAdd):
        super().__init__(socket, toAdd)
        self.pos_x = -1
        self.pos_y = -1
        self.is_home_found = False
        self.direction = 0

    def mainloop(self):
        self.Look()
        self.gloutonTypeShit()

    def gloutonTypeShit(self):
        while True:
            idx = 1
            maxVal = -1
            val = []

            self.Inventory()
            if self.inv["food"] <= 3 or self.is_home_found:
                self.returnKremlin()
            if len(self.vision) < 2:
                self.Look()
            for i in self.vision[1]:
                val.append(self.getValue(i))
            for i in range(len(val)):
                if val[i] > maxVal:
                    maxVal = val[i]
                    idx = i
            if (maxVal == 0):
                idx = randint(0, 2)
            cache = self.vision
            if idx == 1:
                self.Forward()
            elif idx == 0:
                self.Left()
                self.Forward()
                self.Right()
                self.Forward()
            else:
                self.Right()
                self.Forward()
                self.Left()
                self.Forward()
            if (len(cache) != 1):
                self.takeItems(cache[1][idx])
            self.Look()


    def returnKremlin(self):
        # go back to base
        if self.pos_x == -1 or self.pos_y == -1:
           pass 
        if self.pos_x < 0:
            while self.direction != Direction.RIGHT:
                self.Right()
        else:
            while self.direction != Direction.LEFT:
                self.Left()
        while self.pos_x != 0:
            self.Forward()

        if self.pos_y < 0:
            while self.direction != Direction.UP:
                self.Left()
        else:
            while self.direction != Direction.DOWN:
                self.Right()
        while self.pos_y != 0:
            self.Forward()

        # refills and drop
        for i in range(15):
            self.Take("food")
        self.Fork(Role.SACRIFICE)
        for (key, value) in self.inv.items():
            if key != "food":
                for i in range(value):
                    self.Set(key)
        return

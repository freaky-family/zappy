from ..AgenticIntelligenceKpiWorkflow import Freakster, Role, OLIGARCH_STASH


class FoodFactory(Freakster):
    def mainloop(self):
        self.Forward()
        self.pos_x = 0
        self.pos_y = 0
        while (True):
            self.returnKremlin()
            self.Fork(Role.SACRIFICE)
            self.Inventory()
            if (self.inv["food"] < OLIGARCH_STASH):
                self.Take("food")
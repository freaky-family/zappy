from ..AgenticIntelligenceKpiWorkflow import Freakster, Role


class FoodFactory(Freakster):
    def mainloop(self):
        self.Fork(Role.SACRIFICE)
        if (self.inv["food"] < 3):
            print("took food")
            self.Take("food")
            self.Take("food")
            self.Take("food")
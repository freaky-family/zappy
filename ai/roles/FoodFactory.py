from ..AgenticIntelligenceKpiWorkflow import Freakster, Role


class FoodFactory(Freakster):
    def mainloop(self):
        self.Fork(Role.SACRIFICE)
        # self.Inventory() Does not work currently
        while (self.Take("food")):
            pass
-- Human.lua

Human = class (
    function(self)
        self.number = 0
    end
)

function Human:onLoop()
    self.number = self.number + 1
    print(self.number)
end

function Human:humanStuff(animal)
    animal.number = 0
end

return Human()
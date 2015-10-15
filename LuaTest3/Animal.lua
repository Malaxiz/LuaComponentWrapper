-- Animal.lua

Animal = class (
    function(self)
        self.number = 0
    end
)

function Animal:onLoop()
    self.number = self.number + 1
    print(self.number)
end

return Animal()
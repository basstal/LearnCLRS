# https://leetcode-cn.com/problems/basic-calculator-ii/
class Solution:
    optStack = {}
    numStack = {}
    numTop = 0
    optTop = 0
    optPriority = {43: 1, 45: 1, 42: 2, 47: 2}
    prevIsNum = False

    def add(a, b):
        return a + b

    def sub(a, b):
        return a - b

    def mul(a, b):
        return a * b

    def div(a, b):
        return a // b

    optCal = {43: add, 45: sub, 42: mul, 47: div}

    def DoCal(self):
        b = self.numStack[self.numTop]
        a = self.numStack[self.numTop - 1]
        opt = self.optStack[self.optTop]
        self.optTop -= 1
        result = self.optCal[opt](a, b)
        print(a, b, opt, result)
        self.numTop -= 1
        self.numStack[self.numTop] = result

    def calculate(self, s: str) -> int:
        print(s)
        sbyte = s.encode("utf-8")
        for b in sbyte:
            if b == 43 or b == 45 or b == 42 or b == 47:
                self.prevIsNum = False
                nowPriority = self.optPriority[b]
                topPriority = 0
                if self.optTop > 0:
                    topOpt = self.optStack[self.optTop]
                    topPriority = self.optPriority[topOpt]
                while topPriority >= nowPriority:
                    self.DoCal()
                    if self.optTop == 0:
                        break
                    topOpt = self.optStack[self.optTop]
                    topPriority = self.optPriority[topOpt]
                self.optTop += 1
                self.optStack[self.optTop] = b
            elif b >= 48:
                if self.prevIsNum:
                    prevNum = self.numStack[self.numTop]
                    self.numStack[self.numTop] = prevNum * 10 + (b - 48)
                else:
                    self.numTop += 1
                    self.numStack[self.numTop] = b - 48
                self.prevIsNum = True

        while self.numTop > 1:
            self.DoCal()
        self.numTop = 0
        self.prevIsNum = False
        return self.numStack[1]


s = Solution()
print(s.calculate("3+2*2"))
print(s.calculate(" 3+ 2 *2 "))
print(s.calculate(" 3* 2 +2 "))
print(s.calculate(" 48 "))
print(s.calculate("1*2-3/4+5*6-7*8+9/10"))
print(s.calculate("1+2*5/3+6/4*2"))

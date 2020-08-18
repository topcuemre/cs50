from cs50 import get_float
cond = True
while (cond):
    dollar = get_float("Change owed :")
    if dollar >= 0.:
        cond = False
cents = round(dollar * 100)
print(cents)
counter = 0
while cents > 0.:
    if (cents - 25.0 >= 0.0):
        cents = cents - 25.0
        counter += 1
        
    elif (cents - 10.0 >= 0.0):
        cents = cents - 10.0
        counter += 1
        
    elif (cents - 5.0 >= 0.0):
        cents = cents - 5.0
        counter += 1
        
    elif (cents - 1.0 >= 0.0):
        cents = cents - 1.0
        counter += 1
        
print(counter,"\n")
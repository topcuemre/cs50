from cs50 import get_int
# this is for input the height of pyramid only int values valid
#while loop run over and over again until a value between 0 and 8 is entered
while (True):
    height = get_int("Height: ")
    if not (height <= 1 or height > 8):
        break
#to form pyramid i used for loop
# every print values end parameter is set to "" in order to create a good shaped pyramid
for i in range(height):
    print(" " * (height - i - 1),end="")
    print("#" * (i + 1),end="")
    print("  ",end="")
    print("#" * (i + 1),end="")
    print(end="\n")





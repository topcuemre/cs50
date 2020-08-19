# TODO
from cs50 import SQL
from sys import argv,exit

if len(argv) != 2:
    print("error")
    exit(1)
    
database = SQL("sqlite:///students.db")
house = argv[1]
row = database.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", house)
for i in row:
    first, middle, last, birth = i["first"], i["middle"], i["last"], i["birth"]
    print(f"{first} {middle} {last}, born {birth}")
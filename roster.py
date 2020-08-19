# TODO
from cs50 import SQL
from sys import argv, exit
# checks whether necessary numbers of arg inputted via command line
if len(argv) != 2:
    print("error")
    exit(1)
# access to database
database = SQL("sqlite:///students.db")
house = argv[1]
# executing the sqlite from python
row = database.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", house)
# formatting and printing the content of house
for i in row:
    first, middle, last, birth = i["first"], i["middle"], i["last"], i["birth"]
    print(f"{first} {middle + ' ' if middle else ''} {last}, born {birth}")
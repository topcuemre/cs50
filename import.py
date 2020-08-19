# TODO
from cs50 import SQL
from sys import exit, argv
import csv

# checks whether appropiriate numbers of arguments are inputted
if len(argv) != 2:
    print("wrong argument number")
    exit(1)

# editing the persons with 3 names first, middle and last


def splitter(fname):
    nam = fname.split()
    return nam if len(nam) >= 3 else [nam[0], None, nam[1]]
    
    
# accessing to database
database = SQL("sqlite:///students.db")
# this is the indicator of file argument
path = argv[1]
# file opened and closed after use
with open(path) as file:
    read = csv.DictReader(file)
    for row in read:
        ns = splitter(row["name"])
        database.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                         ns[0], ns[1], ns[2], row["house"], row["birth"])
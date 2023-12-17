# Output (print)
print ("Hello World")

# Var declaration
int01 = 1
str01 = "Testing"

# Concat var: , or +; but + may be cause number addition instead.
print(int01, str01)

# List
newList = ["a", "b", "c"]

"""
List methods (e.g. <var>.Method(<arg>) ): 
append()    Add at end
clear()     Remove all
copy()      Returns copy
count()     Returns length
extend()    Add the elements of a list to the end
index()     Returns first index specified
insert()    Insert in specified position
pop()       Remove in specified position
remove()    Remove first index specified
reverse()   Reverse order
sort()      Sort
"""

# String Formatting
""" 
Argument specifier
    %s - string
    %d - int
    %f - float 
    %.<digit>f - float with specified rounding digits
"""
# Similar to String.Format in C#.
print("A number: %d %s" %(int01))

"""
String methods
void/str
    capitalize()    First letter capitalize
    casefold()      To lower
    center()        Centered str
    encode()        Encode
    expendtabs()    Sets tab size
    format()        Format specified values
    format_map()    Format specified values
    lstrip()        Left trim ver
    maketrans()     Return translation table to be used in translations
    partition()     Return a tuple where string is parted into 3 parts
    replace()       Replace specified value
    rjust()         Right justified version
    rpartition()    Return a tuple where the string is parted into 3 parts
    rsplit()        Split string
    rstrip          Return right trim ver
    split()         Split string
    splitlines()    Split at line breaks
    strip()         Returns a trimmed versino
    swapcase()      Swap cases
    title()         Title case
    translate()     Translated string
    upper()         Upper case
    zfll()          fills the string with specified number of 0 values at the beginning
    
int
    count()         Number of times of specified values
    find()/index()  Search string and returns position
    rfind/rindex()  Returns last position

    
bool
    endswith()      Ends with
    isalnum()       Is alphanumeric
    isalpha         Is alphabet
    isdecimal()     Is decimals
    isdigit()       Is digits
    isidentifier()  Is identifier
    islower()       Is lowercase
    isnumeric()     Is numberic
    isprintable()   Is printable
    isspace()       Is whitespaces
    istitle()       If follows the rules of a title
    isupper()       Is uppercase
    startswith()    If string start at speficied value

    """

#Conditions/Comparisons
"""
    If else statements: if/elif/else
    Comparisons: ==, !=, >, <, <=, >=
    Logical operations: and, or, not
    Indentations: tab/space
    is : Tests if two objects has same memory location
    in : Tests if specified value is present in object/var.

"""

#Example If else statement
if (True):
    print("First true")
elif (True):
    print("Else if")
else: 
    print("Else")

#Loops
"""
    Syntax: for, while
    Statements: break (exits the loop), continue (ends the current loop)
    Operator: in, range, else
"""

#Example loops 
for i in newList:
    print("do something")
for i in range(1, 10, 2): #range: start(inclusive), end(EXCLUSIVE), steps
    print("do something") 

#With else clause
"""
    Executed when loop ends even with continue.
    Skipped when break is called.
"""

#Functions
def cooladdition(x, y):
    return x+y

#Classes
class Student:
    count = 0
    def __init__(self, name, IDnum):
        self.name = name
        self.IDnum = IDnum
        Student.count += 1
    def displayCount(self):
        print("Total student count: %d" % Student.count)
    def displayStudent(self): 
        print("Name: %s \t\t ID: %d" %(self.name, self.IDnum))

s1 = Student("student name 1", 12000)
s2 = Student("student name 2", 12011)

#Tuples (static variable: collection of items of which its order is unchangeable and indexed)

x = ("a", "b", "c", "d")

"""
Tuple methods
    count()     Number of times specified value occurs
    index()     Search and return position
"""


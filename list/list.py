import pdb

mylist = ["apple", "banana", "cherry"]
print(mylist)

# allow duplicates
thislist = ["apple", "banana", "cherry", "apple", "cherry"]
print(thislist)

# list length
thislist = ["apple", "banana", "cherry"]
print(len(thislist))

pdb.set_trace()

thislist = ["apple", "banana", "cherry"]
thislist[1:2] = ["blackcurrant", "watermelon"]
print(thislist)

thislist = ["apple", "banana", "cherry"]
thislist[1:3] = ["watermelon"]
print(thislist)

thislist = ["apple", "banana", "cherry"]
thistuple = ("kiwi", "orange")
thislist.extend(thistuple)
print(thislist)

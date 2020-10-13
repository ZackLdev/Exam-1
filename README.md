# Exam-1
CSE335
TASK1

Description For this first task you will be demonstrating your understanding of class inheritence and virtual functions by extending a class that stores and retrieves information about aquatic plants.

Create a new class CInvasivePlant that is derived from CPlant. CInvasivePlant extends CPlant for plants that are incompatible with all fish. Demonstrating your understanding of inheritance and virtual functions, you must:

Implement a version of DisplayDescription that will append a space and the text [invasive] onto the end of the plant's description.

Implement a version of DisplayIncompatible that will ignore the list of known incompatible fish and instead return the string "All" You are not allowed to change the class CPlant at all.

Expand to see example return values for the two classes:

Testing It is strongly recommended that you create some simple tests to ensure your classes are working.

Grading We will grade your solution by running unit tests. As such, you must implement your solution exactly as specified in order for our tests to link with your code and test your functions.

You are not required to add Doxygen comments to your solution.

TASK 2

For this task, you will continue to use the same solution code that you used to implement the previous task.

Description In this task you will be demonstrating your understanding of the Visitor Pattern by implementing a visor that will determine whether or not there is a predator-prey balance in the aquarium.

Some initial code to assist with this task has been provided:

A menu item View>CheckBalance that will display a dialogue box. Visitor support for the Aquarium and visit functions for each of the four types of fish. A method in CAquarium that will accept a visitor and pass it along to items in the aquarium. A base class for an item visitor you will implement to complete this task. A method in CItem that will accept an item visitor. Your task is to implement an concrete visitor class named CPredatorPreyBalance that inherits from CItemVisitor that will check to see if the fish in the aquarium are in predator-prey balance. For the purposes of this exercise, the aquarium is considered balance if there are at least twice as many prey fish (non-angler fish) as predator fish (angler fish). If the aquarium is not in balance, CPredatorPreyBalance's method TooManyPredators should return true; otherwise it should return false. Once you have finished your implementation, you should finish writing the code in the menu handler for the menu item View>CheckBalance.

Examples An aquarium with 4 Angler fish and 6 other fish would not be in balance, since there are not more than twice as many prey (6) as predators (4). The function TooManyPredators should return true, since there are too many predators. An aquarium with 3 Angler fish and 6 of any other type of fish is in balance since there are at least twice as many prey (6) as there are predators (3). The function TooManyPredators should return false, since there are not too many predators.

Testing As with the previous task, it is strongly recommended that you create some simple tests to ensure your classes are working. An empty CPredatorPreyBalanceTest.cpp has been provided for you to use.

Grading We will grade your solution by running unit tests. As such, you must implement your solution exactly as specified in order for our tests to link with your code and test your functions.

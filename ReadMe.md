
# Self-service diner simulation
<sub> Author: Šarūnas Jemeljanovas, group 5 </sub>

### Running the program
    To run the program you need to launch go.bat file.
    
### Simulation process
    Clients come into the diner, they take a plate from a plate stack, put food on it, eat it and put the plate onto used plate stack.

### Simulation goal
    Analyze how many plates the diner needs to have at all times.

### Input data
    Data is inputed through a file. The name of the file should be given through command line. The data is number of plates, client's eating time, probability of client's arival and plate washing time.

### Results
    Results are printed into results.txt file. The result file contain number of plates left, customers served and unserved, and how many additional plates were needed at the end of time interval, as well as the time stamps when the plates were needed.

### Files
    -test.c file contains main method.
    -cafe.c file contains additional functions for simulation.
    -stack.c file contains functions for stack data structure.
    -BigInteger.c file contains functions for big integer data structure.

    Used data structures:
    1. Stack (made by joli9279)
    2. Big Integer (made by albu9211)

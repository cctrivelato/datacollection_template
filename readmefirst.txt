This is a folder to facilitate the connection 
between script and MySQL Database for both
C++ and python code.

Each logic is split separatedly by programming 
language:

        - Python has two files - one file with
        the method and imports necessary for connection
        to database (template of a SLQ query included)
        and the other file for database info (username,
        password, database table, and local address).
        
        - C++ has also two files - one is for the methods,
        method calls, and variables necessary to throw
        data info from code to API, and the other file
        is a php API (it simply means that this code 
        translates variable' values to database format
        and performs a query to insert or select data from/to
        database).
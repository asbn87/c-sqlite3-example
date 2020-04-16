#include <stdlib.h>
#include <stdio.h>
#include "sqlite3.h"

int main()
{
    db_open("test.db");

    // Create table
    db_exec("DROP TABLE IF EXISTS Cars;");
    db_exec("CREATE TABLE Cars(Id INTEGER PRIMARY KEY, Name TEXT, Price INTEGER);");

    // Insert some cars
    db_exec("INSERT INTO Cars(Name, Price) VALUES ('Volvo', 340000);");
    db_exec("INSERT INTO Cars(Name, Price) VALUES ('Audi', 450000);");
    db_exec("INSERT INTO Cars(Name, Price) VALUES ('BMW', 360000);");
    db_exec("SELECT * FROM Cars;");

    // Delete last inserted record
    db_exec("DELETE FROM Cars WHERE Id = ?;");
    db_exec("SELECT * FROM Cars;");

    // Update the first record
    db_exec("UPDATE Cars SET Price = 300000 WHERE Id = 1;");
    db_exec("SELECT * FROM Cars;");

    db_close();
    getchar();
    return 0;
}
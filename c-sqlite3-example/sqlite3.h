#pragma once

#include <winsqlite/winsqlite3.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#pragma comment (lib, "winsqlite3.lib")

int res;                                // Return code
char* error_msg;                        // Error code
sqlite3* db;                            // Database handler
sqlite3_stmt* stmt;                     // Statement handler

int db_open(const char* db_name);       // Create if it doesn't exist and open database
int db_exec(const char* query);         // Execute SQL statement
int db_close();                         // Close database

#include "sqlite3.h"

int db_open(const char* db_name)
{
    res = sqlite3_open(db_name, &db);

    if (res != SQLITE_OK) {
        printf("ERROR opening SQLite DB in memory: %s\n", sqlite3_errmsg(db));
        return res;
    }
    else
        printf("Database opened successfully!\n\n");

    return res;
}


int db_exec(const char* query)
{
    res = sqlite3_prepare_v2(db, query, -1, &stmt, &error_msg);
    printf("Statement: %s\n", query);
    printf("Result: ");

    if (res != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", error_msg);
        sqlite3_free(error_msg);
        sqlite3_close(db);
        return res;
    }
    else
    {
        printf("SQL statement executed successfully!\n");
        if (strchr(query, '?') != NULL)
            sqlite3_bind_int(stmt, 1, sqlite3_last_insert_rowid(db));
    }

    while ((res = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        printf("%d\t%s\t%d\n",
            sqlite3_column_int(stmt, 0),
            sqlite3_column_text(stmt, 1),
            sqlite3_column_int(stmt, 2));
    }

    printf("\n");
    sqlite3_finalize(stmt);
    return res;
}

int db_close()
{
    res = sqlite3_close(db);

    if (res != SQLITE_OK)
    {
        printf("Error closing database\n");
        return res;
    }

    printf("Database closed successfully!\n");
    return res;
}
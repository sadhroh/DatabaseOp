#include "Demo.h"

int DBOperations()
{  
  MYSQL *con = mysql_init(NULL);

  if (con == NULL) 
  {
      printf ("Initialization failure");
      exit(1);
  }

  if (mysql_real_connect(con, "localhost", "root", "", 
          NULL, 0, NULL, 0) == NULL) 
  {
      printf ("Connection failure");
      mysql_close(con);
      exit(1);
  }  

  if (mysql_query(con, "CREATE TABLE Cars(Id INT, Name TEXT, Price INT)")) 
  {
      printf ("DB creation query failure");
      mysql_close(con);
      exit(1);
  }
  if (mysql_query(con, "INSERT INTO Cars VALUES(2,'Mercedes',57127)")) 
  {
      printf ("DB insertion query failure");
      mysql_close(con);
      exit(1);
  }
  if (mysql_query(con, "SELECT * FROM Cars")) 
  {
      printf ("Data retrieval query failure");
      mysql_close(con);
      exit(1);
  }

  MYSQL_ROW row;
  MYSQL_RES *result = mysql_store_result(con);
  int num_fields = mysql_num_fields(result);

  while(field = mysql_fetch_field(result)) 
  {
      printf("%s ", field->name);
  }

  while ((row = mysql_fetch_row(result))) 
  { 
      for(int i = 0; i < num_fields; i++) 
      { 
          printf("%s ", row[i] ? row[i] : "NULL"); 
      } 
          printf("\n"); 
  }

  mysql_free_result(result);
  mysql_close(con);
  exit(0);
}
import mysql.connector
from mysql.connector import Error
import math

conn = None
try:
    conn = mysql.connector.connect(host='localhost',
                                       database='amusement-park',
                                       user='root',
                                       password='')
    if conn.is_connected():
        print('Connected to MySQL database')

        cursor = conn.cursor()
        
        for i in range(7):
            visitors = 500 + math.e**i
            time = f"INSERT INTO time VALUES(\"04-{17 + i}-2024\", 5, {visitors}, {visitors * 150}\");"
            cursor.execute(time)

except Error as err:
    print(err)

finally:
    if conn is not None and conn.is_connected():
        conn.close()

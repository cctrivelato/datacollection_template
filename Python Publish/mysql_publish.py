import mysql.connector
from mysql.connector import Error
from configparser import ConfigParser

table = None

# It is important to keep this method before connecting in order to properly run query
def read_db_config(filename='dbconfig.ini', section='database'):
    parser = ConfigParser()
    parser.read(filename)
    db = {}
    if parser.has_section(section):
        items = parser.items(section)
        for item in items:
            db[item[0]] = item[1]
    else:
        raise Exception(f'Section {section} not found in {filename}')
    return db

db_config = read_db_config()

try:
    # Connect to MySQL
    conn = mysql.connector.connect(**db_config)

    # Create a cursor object
    cursor = conn.cursor()

    # Example query
    cursor.execute("INSERT INTO {table} ({your_table}) VALUES ({your_data})") # Table and 

    # Fetch results
    results = cursor.fetchall()
    for row in results:
        print(row)

except mysql.connector.Error as e:
        print(f"Error while inserting records to {table}: {e}")
        conn.rollback()  # Rollback to maintain data integrity

finally:
    # Close connection
    cursor.close()
    conn.close()
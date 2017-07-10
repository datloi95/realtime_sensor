import MySQLdb
import time
import datetime
import glob
import MySQLdb
from time import strftime
import serial


ser = serial.Serial("/dev/ttyACM2", 9600)
db = MySQLdb.connect(host="localhost", user="root",passwd="tasumania", db="testDb")
#create a cursor
cur = db.cursor();

while True:
    print("Waiting for data")
    temp = ser.readline()
    print temp
    datetimeWrite = (time.strftime("%Y-%m-%d ") + time.strftime("%H:%M:%S"))
    print datetimeWrite
    sql = ("""INSERT INTO tempLog (datetime,temperature) VALUES (%s,%s)""",(datetimeWrite,temp))
    try:
        print "Writing to database..."
        # Execute the SQL command
        cur.execute(*sql)
        # Commit changes in the database
        db.commit()
        print "Write Complete"
 
    except:
        # Rollback in case there is any error
        db.rollback()
        print "Failed writing to database"
    #time.sleep(10)
    cur.close()
    db.close()
    break

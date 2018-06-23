# Benchmark Test Environment: Qt(4 or 5) + Sqlite with In-memory

## Test Case
- 6000 records is repeated.

### SQL DML for testing
- CREATE TABLE qdn( id int primary key, name varchar(50) )
- INSERT INTO qdn VALUES( :id, :name )
- UPDATE qdn SET name='newhello' WHERE id = :id
- SELECT * FROM qdn
- DELETE FROM qdn WHERE id = :id
 
### Test Result 1

![](./media/image1.png)

### Test Result 2

![](./media/image2.png)

### Test Result 3

![](./media/image3.png)

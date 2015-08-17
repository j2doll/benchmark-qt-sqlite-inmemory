**Benchmark Test Environment: Qt(4 or 5) + Sqlite with In-memory**

<span id="How_to_test" class="anchor"></span>**How to test**

**Test Case: 6000 records is repeated. **

**  CREATE TABLE qdn( id int primary key, name varchar(50) )\
 **

INSERT INTO qdn VALUES( :id, :name )\
 

UPDATE qdn SET name='newhello' WHERE id = :id\
 

SELECT \* FROM qdn\
 

DELETE FROM qdn WHERE id = :id\
 

<span id="Result_1" class="anchor"></span>**Result 1**

![](./media/image1.png)

<span id="Result_2" class="anchor"></span>**Result 2**

![](./media/image2.png)

<span id="Result_3" class="anchor"></span>**Result 3**

![](./media/image3.png)

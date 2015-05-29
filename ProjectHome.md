## Benchmark Test Environment: <font color='blue'>Qt(4 or 5)</font> + <font color='red'>Sqlite with In-memory</font> ##
### How to test ###
**Test Case: 6000 records is repeated.**<font size='4'>
<pre><code><br>
CREATE TABLE qdn( id int primary key, name varchar(50) )<br>
<br>
INSERT INTO qdn VALUES( :id, :name )<br>
<br>
UPDATE qdn SET name='newhello' WHERE id = :id<br>
<br>
SELECT * FROM qdn<br>
<br>
DELETE FROM qdn WHERE id = :id<br>
</code></pre>
</font>
### Result 1 ###
![https://benchmark-qt-sqlite-inmemory.googlecode.com/svn/wiki/05.png](https://benchmark-qt-sqlite-inmemory.googlecode.com/svn/wiki/05.png)
### Result 2 ###
![https://benchmark-qt-sqlite-inmemory.googlecode.com/svn/wiki/10.png](https://benchmark-qt-sqlite-inmemory.googlecode.com/svn/wiki/10.png)
### Result 3 ###
![https://benchmark-qt-sqlite-inmemory.googlecode.com/svn/wiki/15.png](https://benchmark-qt-sqlite-inmemory.googlecode.com/svn/wiki/15.png)
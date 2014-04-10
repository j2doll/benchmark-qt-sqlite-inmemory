// main.cpp

#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QDir>
#include <QDateTime>
#include <QDate>
#include <QTime>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

void test();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    test();
    return 0; // return a.exec();
}

void test()
{
    // open the in-memory database of sqlite
    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName( ":memory:" );
    bool isOpenDB = db.open();
    qDebug() << "(1) db open : " << isOpenDB;
    if ( !db.isValid() )
        return;

    // create a table in the memory DB
    QSqlQuery q_create = db.exec( "CREATE TABLE qdn( id int, name varchar(50) );" );
    qDebug() << "(2) create table : " << q_create.lastError();
    // if ( ! q_create.isValid() )
    //    return;

    // repeat test
    // 1. insert
    // 4. select
    // 2. delete
    // 3. update

    int maxRepeatCount = 6000;

    {
        // insert test

        QTime t;
        qDebug() << "(INSERT) start to test ";
        t.start();
        for ( int i = 0 ; i < maxRepeatCount ; i++ )
        {
            QSqlQuery q_insert(db);
            q_insert.prepare( "INSERT INTO qdn VALUES( :id, :name );" );
            q_insert.bindValue( ":id", QVariant::fromValue(i) );
            q_insert.bindValue( ":name", QString("hello%1").arg(i) );
            if ( ! q_insert.exec() )
            {
                qDebug() << " failed to insert data";
                break; // failed to execute
            }
        }
        int elapsedTime = t.elapsed();
        qDebug() << "(INSERT) time elapsed :" << elapsedTime << "mil-sec."
                 << "\n max repeat count :" << maxRepeatCount;
    }

    {
        // update test

        QTime t;
        qDebug() << "(UPDATE) start to test ";
        t.start();
        for ( int i = 0 ; i < maxRepeatCount ; i++ )
        {
            QSqlQuery q_update(db);
            q_update.prepare( "UPDATE qdn SET name='newhello' WHERE id = :id ;" );
            q_update.bindValue( ":id", QVariant::fromValue(i) );
            if ( ! q_update.exec() )
            {
                qDebug() << " failed to update data";
                break; // failed to execute
            }
        }
        int elapsedTime = t.elapsed();
        qDebug() << "(UPDATE) time elapsed :" << elapsedTime << "mil-sec."
                 << "\n max repeat count :" << maxRepeatCount;
    }

    {
        // select-all test

        QTime t;
        qDebug() << "(SELECT-ALL) start to test ";
        t.start();

        QSqlQuery q("SELECT * FROM qdn;");
        QSqlRecord rec = q.record();
        int count = 0;
        int nameCol = rec.indexOf("name");
        while ( q.next() ) // get next record
        {
            QString name = q.value(nameCol).toString(); // get 'name'
            count++;
        }

        int elapsedTime = t.elapsed();

        qDebug() << " number of records: " << count;

        qDebug() << "(SELECT-ALL) time elapsed :" << elapsedTime << "mil-sec.";
    }

    {
        // delete test

        QTime t;
        qDebug() << "(DELETE) start to test ";
        t.start();
        for ( int i = 0 ; i < maxRepeatCount ; i++ )
        {
            QSqlQuery q_delete(db);
            q_delete.prepare( "DELETE FROM qdn WHERE id = :id ;" );
            q_delete.bindValue( ":id", QVariant::fromValue(i) );
            if ( ! q_delete.exec() )
            {
                qDebug() << " failed to delete data";
                break; // failed to execute
            }
        }
        int elapsedTime = t.elapsed();
        qDebug() << "(DELETE) time elapsed :" << elapsedTime << "mil-sec."
                 << "\n max repeat count :" << maxRepeatCount;
    }


}


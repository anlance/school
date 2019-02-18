package club.anlan.lab1;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class DatabaseHelper extends SQLiteOpenHelper {

    static final String userTable = "rank";
    static final String colNumber ="number";
    static final String colUserName ="username";
    static final String colUsedTime ="usedTime";
    static final String colCreatedTime ="createdTime";

    public DatabaseHelper(Context context, String name, SQLiteDatabase.CursorFactory factory, int version) {
        super(context, name, factory, version);
    }


    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL("CREATE TABLE "+userTable+"("+colNumber+" INTEGER PRIMARY KEY,"
                +colUserName+" Text,"
                +colUsedTime+" Text,"
                +colCreatedTime+" Text)");
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {

    }
}
